package ByteIoDemo;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.OutputStream;

public class Demo02 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		//1.������ϵ
		File dest=new File("/Volumes/HDD/java/test/testfile/azhu");
		//2.ѡ�������ļ������
		OutputStream os=null;
		try {
			//��׷�ӵ���ʽд���ļ�
			//׷�ӣ���Ҫд��true
			os=new FileOutputStream(dest,true);
			//3.����
			String str="beijing beijing\r\n";
			//�ַ���ת�ֽ�
			byte[] data=str.getBytes();
			os.write(data,0, data.length);
			
			os.flush();//ǿ��ˢ�³�ȥ
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
			System.out.println("�ļ�δ�ҵ�");
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
			System.out.println("failed!");
		}finally{
			if(null!=os){
				try {
					os.close();
				} catch (IOException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
					System.out.println("Failed!");
				}
			}
		}
	}

}
