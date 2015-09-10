package PropertiesDemo;

import java.util.Properties;

/**
 * Properties 资源配置文件读写
 * 
 * @author JawieZhu
 *
 */
public class Demo01 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Properties pro=new Properties();
		
		pro.setProperty("java", "oracle.jdbc.java.oraclejava");
		pro.setProperty("url", "jdbc:oracls:localhost:orbc");
		pro.setProperty("user", "azhu");
		pro.setProperty("pwd", "tiger");
		
		String url=pro.getProperty("url", "azhu");
		System.out.println(url);
		
	}

}
