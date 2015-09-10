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
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.util.Arrays;

public class ObjectDemo01 {

	public static void main(String[] args) throws FileNotFoundException, IOException, ClassNotFoundException {
		// TODO Auto-generated method stub
		seri("/Volumes/HDD/java/test/testfile/objectzhu");
		read("/Volumes/HDD/java/test/testfile/objectzhu");
	}

	public static void read(String destPath) throws IOException, ClassNotFoundException{
		//����Դ
		File src=new File(destPath);
		//ѡ����
		ObjectInputStream dis=new ObjectInputStream(
				new BufferedInputStream(
						new FileInputStream(src))
				);
		
		//����  ��ȡ��˳����д��һ�� ������� ���ܶ�ȡ ˳��һ�� ��ȡ����
		Object obj=dis.readObject();
		
		if(obj instanceof Employee){
			Employee emp=(Employee) obj;
			System.out.println(emp.getName());
			System.out.println(emp.getSalary());
		}
		
		obj=dis.readObject();
		int [] arr=(int[])obj;
		System.out.println(Arrays.toString(arr));
		dis.close();
		
	}
	
	//���л�
	public static void seri(String destPath) throws FileNotFoundException, IOException{
			Employee emp=new Employee("pku",9000);
			int[] arr={1,2,3,45};
	//����Դ
			File dest=new File(destPath);
			//ѡ����  
			ObjectOutputStream dos=new ObjectOutputStream(
					new BufferedOutputStream(
							new FileOutputStream(dest)
							));
			//���� ��ȡ˳����д��˳�����һ��
			dos.writeObject(emp);
			dos.writeObject(arr);
			dos.flush();
			dos.close();
	}
}
