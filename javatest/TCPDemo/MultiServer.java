package TCPDemo;

import java.io.BufferedWriter;
import java.io.DataOutputStream;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.net.ServerSocket;
import java.net.Socket;

/**
 * 创建服务器 制定端口
 * 接受客户端连接
 * 发送数据+接受数据
 * @author JawieZhu
 *
 *接受多个客户端
 */
public class MultiServer {

	public static void main(String[] args) throws IOException {
		//创建服务器 制定端口
		ServerSocket server=new ServerSocket(8888);//可在浏览器中输入localhost:8888 对服务器发出请求
		//接受客户端连接  阻塞式
		while(true){ //死循环 一个accpet 一个客户端
			Socket socket=server.accept();
			System.out.println("一个客户端建立连接");
			//发送数据
			String msg="welcome!";
			//输出流
	
			
			DataOutputStream dos=new DataOutputStream(socket.getOutputStream());
			dos.writeUTF(msg);
			dos.flush();
		}
	}

}
