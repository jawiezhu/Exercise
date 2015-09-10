package UDPDemo;

import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.SocketException;

/**
 * 服务端
 * 1 创建服务端+端口 DatagramSocket类+制定窗口
 * 2 准备接受容器 字节数组 封装 DatagramPacket
 * 3 包 接受数据
 * 4 分析
 * @author JawieZhu
 *
 */
public class MyServer {

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
		byte[] data=packet.getData();
		int len=packet.getLength();
		System.out.println("server get!"+new String(data,0,len));
		
		//释放
		server.close();
		
	}

}
