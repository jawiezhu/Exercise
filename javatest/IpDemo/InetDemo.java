package IpDemo;

import java.net.InetAddress;
import java.net.UnknownHostException;

public class InetDemo {

	public static void main(String[] args) throws UnknownHostException {
		//使用getLocalHost方法创建InetAddress对象
		InetAddress addr=InetAddress.getLocalHost();
		System.out.println(addr.getHostAddress());
		System.out.println(addr.getHostName());
		
		//根据域名得到InetAddress对象
		addr=InetAddress.getByName("www.163.com");
		System.out.println(addr.getHostAddress());//返回ip地址
		System.out.println(addr.getHostName());//输出 域名
		
		//根据ip得到InetAddress对象
		addr=InetAddress.getByName("61.135.253.15");
		System.out.println(addr.getHostAddress());//返回ip地址
		System.out.println(addr.getHostName());
	}

}
