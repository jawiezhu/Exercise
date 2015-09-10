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
		//创建源
		File src=new File(destPath);
		//选择流
		ObjectInputStream dis=new ObjectInputStream(
				new BufferedInputStream(
						new FileInputStream(src))
				);
		
		//操作  读取的顺序与写出一致 必须存在 才能读取 顺序不一致 读取错误
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
	
	//序列化
	public static void seri(String destPath) throws FileNotFoundException, IOException{
			Employee emp=new Employee("pku",9000);
			int[] arr={1,2,3,45};
	//创建源
			File dest=new File(destPath);
			//选择流  
			ObjectOutputStream dos=new ObjectOutputStream(
					new BufferedOutputStream(
							new FileOutputStream(dest)
							));
			//操作 读取顺序与写出顺序必须一致
			dos.writeObject(emp);
			dos.writeObject(arr);
			dos.flush();
			dos.close();
	}
}
