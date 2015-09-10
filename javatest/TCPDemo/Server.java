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
 */
public class Server {

	public static void main(String[] args) throws IOException {
		//创建服务器 制定端口
		ServerSocket server=new ServerSocket(8888);//可在浏览器中输入localhost:8888 对服务器发出请求
		//接受客户端连接  阻塞式
		Socket socket=server.accept();
		System.out.println("一个客户端建立连接");
		//发送数据
		String msg="welcome!";
		//输出流
//		BufferedWriter bw=new BufferedWriter(
//				new OutputStreamWriter(
//						socket.getOutputStream())); //这里是 OutputStream
//		
//		bw.write(msg);
//		bw.newLine();
//		bw.flush(); //不用关闭，不然道路会关掉
		
		DataOutputStream dos=new DataOutputStream(socket.getOutputStream());
		dos.writeUTF(msg);
		dos.flush();
	}

}
