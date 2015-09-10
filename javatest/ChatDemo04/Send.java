package ChatDemo04;

import java.io.BufferedReader;
import java.io.DataOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.Socket;

//发送数据
/**
 * 
 * @author JawieZhu
 *
 */
public class Send implements Runnable{
	
	//控制台输入流
	private BufferedReader console;
	//管道输出流
	private DataOutputStream dos;
	//控制线程
	private boolean isRunning=true;
	//名称
	private String name;
	
	public Send(){
		console=new BufferedReader(new InputStreamReader(System.in));
		
	}
	
	public Send(Socket client,String name){
		this();
		try {
			dos = new DataOutputStream(client.getOutputStream());
			this.name=name;
			send(this.name);
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
			isRunning=false;
			CloseUtil.closeAll(dos,console);
		}
	}
	
	//从控制台接收数据
	private String getMsgFromConsole()
	{
		try {
			return console.readLine();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} 
		return "";
	}
	/*
	 * 
	 * 发送数据
	 */
	public void send(String msg){
		//String msg=getMsgFromConsole();
		if(null!=msg && !msg.equals("")){
			try {
				dos.writeUTF(msg);
				dos.flush();
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
				isRunning=false;
				CloseUtil.closeAll(dos,console);
			}
		}
	}
	
	
	@Override
	public void run() {
		// 线程体
		while(isRunning){
			send(getMsgFromConsole());
		}
	}

}
