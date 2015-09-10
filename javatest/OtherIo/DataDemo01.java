package OtherIo;

import java.io.BufferedInputStream;
import java.io.BufferedOutputStream;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;

//���ݴ�����
//��������+�ַ���

public class DataDemo01 {

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		//write("/Volumes/HDD/java/test/testfile/datazhu");//�����ļ� ������ �Ǹ���������
		read("/Volumes/HDD/java/test/testfile/datazhu");
	}
	
	
	/**
	 * ���ļ��ж�ȡ����+����
	 * @param destPath
	 * @throws IOException
	 */
	public static void read(String destPath) throws IOException{
		//����Դ
		File src=new File(destPath);
		//ѡ����
		DataInputStream dis=new DataInputStream(
				new BufferedInputStream(
						new FileInputStream(src))
				);
		
		//����  ��ȡ��˳����д��һ�� ������� ���ܶ�ȡ ˳��һ�� ��ȡ����
		double num1=dis.readDouble();
		long num2=dis.readLong();
		String str=dis.readUTF();
		
		System.out.println(str);
		
		
	}
	
	/**
	 * ����+���� ������ļ�
	 * @param destPath
	 * @throws IOException
	 */
	public static void write(String destPath) throws IOException{
		double point=2.5;
		long num=100L;
		String str="��������";
		
		//����Դ
		File dest=new File(destPath);
		//ѡ����  
		DataOutputStream dos=new DataOutputStream(
				new BufferedOutputStream(
						new FileOutputStream(dest)
						));
		//���� ��ȡ˳����д��˳�����һ��
		dos.writeDouble(point);
		dos.writeLong(num);
		dos.writeUTF(str);
		
		dos.flush();
		dos.close();
	}
	
}
