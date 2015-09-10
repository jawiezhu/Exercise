package PropertiesDemo;

import java.io.IOException;
import java.util.Properties;

/**
 * 使用类相对路径读取文件
 * bin
 * @author JawieZhu
 *
 */
public class Demo04 {

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		Properties pro=new Properties();
		pro.load(Demo04.class.getResourceAsStream("/"));
		
	}

}
