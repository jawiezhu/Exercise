package OtherIo;

import java.io.BufferedInputStream;
import java.io.BufferedOutputStream;
import java.io.ByteArrayInputStream;
import java.io.ByteArrayOutputStream;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.util.Arrays;

//���ݴ�����
//��������+�ַ���

public class DataDemo02 {

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		//write("/Volumes/HDD/java/test/testfile/datazhu");//�����ļ� ������ �Ǹ���������
		//read("/Volumes/HDD/java/test/testfile/datazhu");
		
		byte[] data=write();
		read(data);
		System.out.println(data.length);
	}
	
	
	/**
	 * ���ֽ������ж�ȡ����+����
	 * @param destPath
	 * @throws IOException
	 */
	public static void read(byte[] src) throws IOException{
		
		//ѡ����
		DataInputStream dis=new DataInputStream(
				new BufferedInputStream(
						new ByteArrayInputStream(src))
				);
		
		//����  ��ȡ��˳����д��һ�� ������� ���ܶ�ȡ ˳��һ�� ��ȡ����
		double num1=dis.readDouble();
		long num2=dis.readLong();
		String str=dis.readUTF();
		
		dis.close();
		//System.out.println(str);
		
		
	}
	
	/**
	 * ����+���� ����� �ֽ�������
	 * @param destPath
	 * @throws IOException
	 */
	public static byte[] write() throws IOException{
		
		//Ŀ������
		byte[] dest=null;
		
		double point=2.5;
		long num=100L;
		String str="��������";
		
		
		
		//ѡ����  
		ByteArrayOutputStream bos=new ByteArrayOutputStream();
		
		DataOutputStream dos=new DataOutputStream(
				new BufferedOutputStream(
							bos
							));
		//���� ��ȡ˳����д��˳�����һ��
		dos.writeDouble(point);
		dos.writeLong(num);
		dos.writeUTF(str);
		
		dos.flush();
		dos.close();
		dest=bos.toByteArray();
		return dest;
	}
	
}
