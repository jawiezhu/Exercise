package OtherIo;

import java.io.BufferedInputStream;
import java.io.ByteArrayInputStream;
import java.io.ByteArrayOutputStream;
import java.io.IOException;
import java.io.InputStream;

/**
 * 字节数组节点流
 * 数组的长度有限，数据量不会很大
 * 
 * 文件内容不要太大
 * 1 文件---程序---字节数组
 * 2 字节数组----程序----文件 
 * 
 * @author JawieZhu
 *
 */
public class ByteArrayDemo01 {

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		read(write());
	}
	
	
	//输出流 操作与文件输出流有些不同，有新增方法，不能使用多态
	public static byte[] write() throws IOException{
		//目的地
		byte[] dest;
		//选择流
		ByteArrayOutputStream bos=new ByteArrayOutputStream();
		//写出
		String msg="ddddddddd";
		byte[] info=msg.getBytes();
		bos.write(info,0,info.length);
		
		//获取数据
		dest=bos.toByteArray();
		
		bos.close();
		return dest;
	}
	
	
	public static void read(byte[] src) throws IOException{
		/**
		 * 输入流 操作与文件输入流操作一致
		 * 读取字节数组
		 */
		
		
		//选择流
		InputStream is=new BufferedInputStream(
				new ByteArrayInputStream(src));
		
		//操作
		byte[] flush=new byte[1024];
		int len=0;
		
		while(-1!=(len=is.read(flush))){
			System.out.println(new String(flush,0,len));
		}
		is.close();
		
		
		
	}

}
