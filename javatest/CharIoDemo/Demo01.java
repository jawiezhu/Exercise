package CharIoDemo;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.Reader;

/**
 * ���ı���ȡ
 * @author JawieZhu
 *
 */
public class Demo01 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		//����Դ
		File src=new File("/Volumes/HDD/java/test/testfile/azhu");
		//ѡ����
		Reader reader=null;
		try {
			reader =new FileReader(src);
			//��ȡ����
			char[] car=new char[1024];
			int len=0;
			while(-1!=(len=reader.read(car))){
				//�ַ�ת�ַ���
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
