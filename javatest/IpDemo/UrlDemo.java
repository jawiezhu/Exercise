package IpDemo;

import java.net.MalformedURLException;
import java.net.URL;

public class UrlDemo {

	public static void main(String[] args) throws MalformedURLException {
		// ����·������
		URL url=new URL("http://www.baidu.com:80/index.html?uname=azhu");
		System.out.println(url.getProtocol());
		System.out.println(url.getHost());
		System.out.println(url.getPort());
		System.out.println(url.getFile());
		System.out.println("���·����"+url.getPath());
		System.out.println("ê�㣺"+url.getRef());
		System.out.println("������"+url.getQuery());//����������ê�㣬���ǿ�
		
		url=new URL("http://www.baidu.com/a/");
		url=new URL(url,"b.txt");//���·��
		System.out.println(url.toString());
	}

}
