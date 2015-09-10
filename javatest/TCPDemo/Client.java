package TCPDemo;

import java.io.BufferedReader;
import java.io.DataInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.Socket;
import java.net.UnknownHostException;

/**
 * 创建客户端 必须制定服务器+端口 此时就在连接
 * 接受数据+发送数据
 * 
 * @author JawieZhu
 *
 */

public class Client {

	public static void main(String[] args) throws UnknownHostException, IOException {
		//创建客户端 必须指定服务器+端口 此时就在连接
		Socket client=new Socket("localhost",8888);//发送端口 由系统内部自动分配
		//接受数据
//		BufferedReader br=new BufferedReader(new InputStreamReader(
//				client.getInputStream())); //这里是 InputStream
//		String echo=br.readLine(); 
//		System.out.println(echo);
		
		DataInputStream dis=new DataInputStream(client.getInputStream());
		String echo=dis.readUTF();
		System.out.println(echo);
	}

}
