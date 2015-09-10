package PropertiesDemo;

import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.Properties;

/**
 * 使用properties读取配置文件
 * @author JawieZhu
 *
 */
public class Demo03 {

	public static void main(String[] args) throws FileNotFoundException, IOException {
		// TODO Auto-generated method stub
		Properties pro=new Properties();
		pro.load(new FileReader("/Volumes/HDD/java/azhu.properties"));
		System.out.println(pro.getProperty("user","adzhu"));
		
	}

}
