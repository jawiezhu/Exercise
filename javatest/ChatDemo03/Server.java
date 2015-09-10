package ChatDemo03;

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
		private String name;
		
		public MyChannel (Socket client){
			try {
				dis=new DataInputStream(client.getInputStream());
				dos=new DataOutputStream(client.getOutputStream());
				
				this.name=dis.readUTF();
				//System.out.println(this.name);
				this.send("welcome this room!!!");
				sendOthers(this.name+"enter the room！",true);
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
		private void sendOthers(String msg,boolean sys){
			//String msg=this.receive();
			if(msg.startsWith("@")&& msg.indexOf(":")>-1) {
				//获取name
				String name=msg.substring(1,msg.indexOf(":"));
				String content=msg.substring(msg.indexOf(":")+1);
				for(MyChannel other:all){
					if(other.name.equals(name)){
						other.send(this.name+"to YOU:"+content);
					}
					
				}
			}else{
				//遍历容器
				for(MyChannel other:all){
					if(other==this){
						continue;
					}
					if(sys){//系统信息
						other.send("SERVER:"+msg);
					}else{
						//发送给其他客户端
						other.send(this.name+"to ALL:"+msg);
					}
					
			}
			}
		}
		
		
		@Override
		public void run() {
			// TODO Auto-generated method stub
			while(isRunning){
				sendOthers(receive(),false);
			}
		}
		
	}
	
	
}


