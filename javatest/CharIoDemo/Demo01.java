package CharIoDemo;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.Reader;

/**
 * 纯文本读取
 * @author JawieZhu
 *
 */
public class Demo01 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		//创建源
		File src=new File("/Volumes/HDD/java/test/testfile/azhu");
		//选择流
		Reader reader=null;
		try {
			reader =new FileReader(src);
			//读取操作
			char[] car=new char[1024];
			int len=0;
			while(-1!=(len=reader.read(car))){
				//字符转字符串
				String str=new String(car,0,len);
				System.out.println(str);
			}
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}finally{
			if(null!=reader){
				try {
					reader.close();
				} catch (IOException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
			}
		}
		
		
	}

}
