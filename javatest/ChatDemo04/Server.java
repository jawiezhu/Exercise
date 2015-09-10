package ChatDemo04;

import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.ArrayList;
import java.util.List;

/**
 * 创建服务器
 * @author JawieZhu
 *
 */
public class Server { 
	private List<MyChannel> all=new ArrayList<MyChannel>();
	
	 
	public static void main(String[] args) throws IOException {
		new Server().start();
	}
	
	public void start() throws IOException{
		ServerSocket server=new ServerSocket(9999);
		while(true){
			Socket client=server.accept();
			MyChannel channel=new MyChannel(client);
			all.add(channel); //加入容器中 统一管理
			new Thread(channel).start(); //一条道路
		}
	}
	
	/**
	 * 一个客户端一条道路
	 * 输入流
	 * 输出流
	 * 输入流 接收数据
	 * 输出流 发送数据
	 * @author JawieZhu
	 *
	 */
	private class MyChannel implements Runnable{

		private DataInputStream dis;
		private DataOutputStream dos;
		private boolean isRunning=true;
		
		public MyChannel (Socket client){
			try {
				dis=new DataInputStream(client.getInputStream());
				dos=new DataOutputStream(client.getOutputStream());
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
				CloseUtil.closeAll(dis,dos);
				isRunning=false;
				all.remove(this);
			}
		}
		
		/**
		 * 读取数据
		 * @return
		 */
		private String receive(){
			String msg="";
			try {
				msg=dis.readUTF();
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
				CloseUtil.closeAll(dis);
				isRunning=false;
				all.remove(this);
			}
			return msg;
		}
		
		/**
		 * 发送数据
		 */
		private void send(String msg){
			if(msg==null || msg.equals("")){
				return ;
			}
			
			try {
				dos.writeUTF(msg);
				dos.flush();
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
				CloseUtil.closeAll(dos);
				isRunning=false;
				all.remove(this);
			}
		}
		
		
		/**
		 * 发送给其他客户端
		 */
		private void sendOthers(){
			String msg=this.receive();
			//遍历容器
			for(MyChannel other:all){
				if(other==this){
					continue;
				}
				//发送给其他客户端
				other.send(msg);
			}
		}
		@Override
		public void run() {
			// TODO Auto-generated method stub
			while(isRunning){
				sendOthers();
			}
		}
		
	}
	
	
}


