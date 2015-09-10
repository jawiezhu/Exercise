package ChatDemo02;

import java.io.BufferedReader;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.Socket;
import java.net.UnknownHostException;

/**
 * 创建客户端：发送数据+接受数据
 * @author JawieZhu
 *
 *写出数据  输出流
 *读取数据  输入流
 *
 *输入流 与 输出流 目前在同一个线程内，应该批次独立 需用多线程
 *
 */
public class Client {

	public static void main(String[] args) throws UnknownHostException, IOException {
		// TODO Auto-generated method stub
		Socket client=new Socket("localhost",9999);
		
		//控制台输入流
		new Thread(new Send(client)).start();//一条路径
		
		new Thread(new Receive(client)).start();
	}

}
