package PropertiesDemo;

import java.io.IOException;
import java.util.Properties;

/**
 * ʹ�������·����ȡ�ļ�
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
