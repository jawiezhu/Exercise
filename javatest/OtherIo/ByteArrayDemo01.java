package OtherIo;

import java.io.BufferedInputStream;
import java.io.ByteArrayInputStream;
import java.io.ByteArrayOutputStream;
import java.io.IOException;
import java.io.InputStream;

/**
 * �ֽ�����ڵ���
 * ����ĳ������ޣ�����������ܴ�
 * 
 * �ļ����ݲ�Ҫ̫��
 * 1 �ļ�---����---�ֽ�����
 * 2 �ֽ�����----����----�ļ� 
 * 
 * @author JawieZhu
 *
 */
public class ByteArrayDemo01 {

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		read(write());
	}
	
	
	//����� �������ļ��������Щ��ͬ������������������ʹ�ö�̬
	public static byte[] write() throws IOException{
		//Ŀ�ĵ�
		byte[] dest;
		//ѡ����
		ByteArrayOutputStream bos=new ByteArrayOutputStream();
		//д��
		String msg="ddddddddd";
		byte[] info=msg.getBytes();
		bos.write(info,0,info.length);
		
		//��ȡ����
		dest=bos.toByteArray();
		
		bos.close();
		return dest;
	}
	
	
	public static void read(byte[] src) throws IOException{
		/**
		 * ������ �������ļ�����������һ��
		 * ��ȡ�ֽ�����
		 */
		
		
		//ѡ����
		InputStream is=new BufferedInputStream(
				new ByteArrayInputStream(src));
		
		//����
		byte[] flush=new byte[1024];
		int len=0;
		
		while(-1!=(len=is.read(flush))){
			System.out.println(new String(flush,0,len));
		}
		is.close();
		
		
		
	}

}
