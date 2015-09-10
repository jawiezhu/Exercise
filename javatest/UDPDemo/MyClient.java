package UDPDemo;

import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetSocketAddress;
import java.net.SocketAddress;
import java.net.SocketException;

/**
 * 客户端
 * 1. 创建客户端 DatagramSocket 类+制定端口
 * 2. 准备数据 字节数组
 * 3. 打包 DatagramPacket + 服务器地址 以及 端口
 * 4. 发送
 * 5. 释放资源
 * @author JawieZhu
 *
 */
public class MyClient {

	public static void main(String[] args) throws IOException {
		// 创建客户端+端口
		DatagramSocket client=new DatagramSocket(6666);//端口不能冲突
		//准备数据
		String msg="UDP test~!";
		byte[] data=msg.getBytes();
		
		//打包 发送的地点以及端口
		DatagramPacket packet=new DatagramPacket(data,data.length,
				new InetSocketAddress("localhost",8888));
		
		//发送
		client.send(packet);
		
		//释放
		client.close();

	}

}
