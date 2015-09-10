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

//数据处理流
//基本类型+字符串

public class DataDemo01 {

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		//write("/Volumes/HDD/java/test/testfile/datazhu");//生成文件 看不懂 是给机器看的
		read("/Volumes/HDD/java/test/testfile/datazhu");
	}
	
	
	/**
	 * 从文件中读取数据+类型
	 * @param destPath
	 * @throws IOException
	 */
	public static void read(String destPath) throws IOException{
		//创建源
		File src=new File(destPath);
		//选择流
		DataInputStream dis=new DataInputStream(
				new BufferedInputStream(
						new FileInputStream(src))
				);
		
		//操作  读取的顺序与写出一致 必须存在 才能读取 顺序不一致 读取错误
		double num1=dis.readDouble();
		long num2=dis.readLong();
		String str=dis.readUTF();
		
		System.out.println(str);
		
		
	}
	
	/**
	 * 数据+类型 输出到文件
	 * @param destPath
	 * @throws IOException
	 */
	public static void write(String destPath) throws IOException{
		double point=2.5;
		long num=100L;
		String str="数据类型";
		
		//创建源
		File dest=new File(destPath);
		//选择流  
		DataOutputStream dos=new DataOutputStream(
				new BufferedOutputStream(
						new FileOutputStream(dest)
						));
		//操作 读取顺序与写出顺序必须一致
		dos.writeDouble(point);
		dos.writeLong(num);
		dos.writeUTF(str);
		
		dos.flush();
		dos.close();
	}
	
}
