package ByteIoDemo;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStream;

/**
 * 文件读取
 * @author JawieZhu
 *
 */
public class Demo01 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		//1建立联系
		File src=new File("/Volumes/HDD/java/test/testfile/azhu");
		//2选择流
		InputStream is=null;//提升作用域
		try {
			is=new FileInputStream(src);
			//3操作不断读取
			byte[] car=new byte[10];//缓冲数组
			int len=0;//接受实际读取大小
			//循环读取
			while(-1!=(len=is.read(car))){
				//输出字节数组 转成字符串
				String info=new String(car,0,len);
				System.out.println(info);
			}
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
			System.out.println("File not exist.");
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
			System.out.println("Read File.");
		}finally{
			if(null!=is){
				try {
					is.close();
				} catch (IOException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
					System.out.println("close failed!");
				}
			}
		}
		
	}

}
