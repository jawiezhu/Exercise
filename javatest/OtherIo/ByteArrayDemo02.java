package OtherIo;

import java.io.BufferedInputStream;
import java.io.BufferedOutputStream;
import java.io.ByteArrayInputStream;
import java.io.ByteArrayOutputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;

public class ByteArrayDemo02 {

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		
		byte[] data=getBytesFromFile("/Volumes/HDD/java/test/testfile/newazhu");
		toFileFromByteArray(data,"/Volumes/HDD/java/test/testfile/newahui");
		//System.out.println(new String(data));
	}
	
	public static void toFileFromByteArray(byte[] src,String destPath) throws IOException{
		//����Դ
		//Ŀ�ĵ�
		File dest=new File(destPath);
		
		//ѡ����
		//�ֽ����������� ���ļ������
		InputStream is=new BufferedInputStream(new ByteArrayInputStream(src));
		
		//�ļ������
		OutputStream os=new BufferedOutputStream(new FileOutputStream(dest));
		
		//����
		byte[] flush=new byte[1024];
		int len=0;
		while(-1!=(len=is.read(flush))){
			os.write(flush, 0, len);
		}
		os.flush();
		os.close();
		is.close();
	}
	
	
	
	
	
	//�ļ�---����---�ֽ�����
	public static byte[] getBytesFromFile(String srcPath) throws IOException{
		//�����ļ�Դ
		//����Ŀ�ĵ� �ֽ�����
		File src=new File(srcPath);
		byte[] dest=null;
		
		//ѡ����
		//�ļ�������
		InputStream is=new BufferedInputStream(new FileInputStream(src));
		//�ֽ���������� ����ʹ�ö�̬
		ByteArrayOutputStream bos=new ByteArrayOutputStream();
		
		//���� ���϶�ȡ�ļ� д�����ֽ���������
		byte[] flush=new byte[1024];
		int len=0;
		while(-1!=(len=is.read(flush))){
			//д���ֽ���������
			bos.write(flush,0,len);
		}
		
		bos.flush();
		
		//��ȡ����
		dest=bos.toByteArray();
		
		bos.close();
		is.close();
		return dest;
		
	}

}
