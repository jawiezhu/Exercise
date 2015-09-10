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

//数据处理流
//基本类型+字符串

public class DataDemo02 {

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		//write("/Volumes/HDD/java/test/testfile/datazhu");//生成文件 看不懂 是给机器看的
		//read("/Volumes/HDD/java/test/testfile/datazhu");
		
		byte[] data=write();
		read(data);
		System.out.println(data.length);
	}
	
	
	/**
	 * 从字节数组中读取数据+类型
	 * @param destPath
	 * @throws IOException
	 */
	public static void read(byte[] src) throws IOException{
		
		//选择流
		DataInputStream dis=new DataInputStream(
				new BufferedInputStream(
						new ByteArrayInputStream(src))
				);
		
		//操作  读取的顺序与写出一致 必须存在 才能读取 顺序不一致 读取错误
		double num1=dis.readDouble();
		long num2=dis.readLong();
		String str=dis.readUTF();
		
		dis.close();
		//System.out.println(str);
		
		
	}
	
	/**
	 * 数据+类型 输出到 字节数组中
	 * @param destPath
	 * @throws IOException
	 */
	public static byte[] write() throws IOException{
		
		//目标数组
		byte[] dest=null;
		
		double point=2.5;
		long num=100L;
		String str="数据类型";
		
		
		
		//选择流  
		ByteArrayOutputStream bos=new ByteArrayOutputStream();
		
		DataOutputStream dos=new DataOutputStream(
				new BufferedOutputStream(
							bos
							));
		//操作 读取顺序与写出顺序必须一致
		dos.writeDouble(point);
		dos.writeLong(num);
		dos.writeUTF(str);
		
		dos.flush();
		dos.close();
		dest=bos.toByteArray();
		return dest;
	}
	
}
