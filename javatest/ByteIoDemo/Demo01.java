package ByteIoDemo;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStream;

/**
 * �ļ���ȡ
 * @author JawieZhu
 *
 */
public class Demo01 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		//1������ϵ
		File src=new File("/Volumes/HDD/java/test/testfile/azhu");
		//2ѡ����
		InputStream is=null;//����������
		try {
			is=new FileInputStream(src);
			//3�������϶�ȡ
			byte[] car=new byte[10];//��������
			int len=0;//����ʵ�ʶ�ȡ��С
			//ѭ����ȡ
			while(-1!=(len=is.read(car))){
				//����ֽ����� ת���ַ���
				String info=new String(car,0,len);
				System.out.println(info);
			}
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
			System.out.println("File not exist.");
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
			System.out.println("Read File.");
		}finally{
			if(null!=is){
				try {
					is.close();
				} catch (IOException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
					System.out.println("close failed!");
				}
			}
		}
		
	}

}
