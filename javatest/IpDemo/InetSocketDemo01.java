package IpDemo;

import java.net.InetAddress;
import java.net.InetSocketAddress;
import java.net.UnknownHostException;

/**
 * 包含端口 在 InetAddress基础上加入端口
 * @author JawieZhu
 *
 */
public class InetSocketDemo01 {
	
	public static void main(String[] args) throws UnknownHostException {
		//封装
		InetSocketAddress addr=new InetSocketAddress("127.0.0.1",9999);
		//手动添加，上一行 是 添加字符串 源码里 执行 下面这行的 getByName
		addr=new InetSocketAddress(InetAddress.getByName("127.0.0.1"),9999);
		System.out.println(addr.getHostName());
		System.out.println(addr.getPort());
		//解析
		InetAddress add=addr.getAddress();
		System.out.println(add.getHostAddress()); //返回ip地址
		System.out.println(add.getHostName()); 
		
		
		
		
	}

}
