package PropertiesDemo;

import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.Properties;

/**
 * ʹ��properties��ȡ�����ļ�
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
