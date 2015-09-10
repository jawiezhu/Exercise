package IpDemo;

import java.net.MalformedURLException;
import java.net.URL;

public class UrlDemo {

	public static void main(String[] args) throws MalformedURLException {
		// 绝对路径构建
		URL url=new URL("http://www.baidu.com:80/index.html?uname=azhu");
		System.out.println(url.getProtocol());
		System.out.println(url.getHost());
		System.out.println(url.getPort());
		System.out.println(url.getFile());
		System.out.println("相对路径："+url.getPath());
		System.out.println("锚点："+url.getRef());
		System.out.println("参数："+url.getQuery());//参数，存在锚点，则是空
		
		url=new URL("http://www.baidu.com/a/");
		url=new URL(url,"b.txt");//相对路径
		System.out.println(url.toString());
	}

}
