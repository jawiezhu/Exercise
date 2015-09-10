package UDPDemo;

import java.io.ByteArrayInputStream;
import java.io.DataInput;
import java.io.DataInputStream;
import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.SocketException;

/**
 * 服务端
 * 1 创建服务端+端口 DatagramSocket类+制定窗口
 * 2 准备接受容器 字节数组 封装 DatagramPacket
 * 3 包 接受数据
 * 4 分析 字节数组->double
 * @author JawieZhu
 *
 */
public class Server {

	public static void main(String[] args) throws IOException {
		//创建服务端+窗口
		DatagramSocket server=new DatagramSocket(8888);
		
		//准备接受容器 
		byte[] container=new byte[1024];
		//封装成包
		DatagramPacket packet=new DatagramPacket(container,container.length);
		
		//接收数据
		server.receive(packet);
		
		//分析数据
		double data=convert(packet.getData());
		
		System.out.println(data);
		
		//释放
		server.close();
		
	}
	/**
	 * 字节数组+ data 输入流
	 * @param data
	 * @return
	 * @throws IOException 
	 */
	public static double convert(byte[] data) throws IOException{
		DataInputStream dis=new DataInputStream(new ByteArrayInputStream(data));
		double num=dis.readDouble();
		
		dis.close();
		return num;
		
	}

}
