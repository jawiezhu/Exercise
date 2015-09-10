package PropertiesDemo;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.util.Properties;

/**
 * 使用properties输出到文件
 * @author JawieZhu
 *
 */
public class Demo02 {

	public static void main(String[] args) {
	
				Properties pro=new Properties();
				
				pro.setProperty("java", "oracle.jdbc.java.oraclejava");
				pro.setProperty("url", "jdbc:oracls:localhost:orbc");
				pro.setProperty("user", "azhu");
				pro.setProperty("pwd", "tiger");
				
				try {
					pro.store(new FileOutputStream(new File("/Volumes/HDD/java/azhu.properties")), "db");
				} catch (FileNotFoundException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				} catch (IOException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
				
				try {
					pro.storeToXML(new FileOutputStream(new File("/Volumes/HDD/java/azhu.xml")), "dbxml");
				} catch (FileNotFoundException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				} catch (IOException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
				
				
	}

}
