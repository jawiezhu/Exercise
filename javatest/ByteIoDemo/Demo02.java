package ByteIoDemo;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.OutputStream;

public class Demo02 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		//1.建立联系
		File dest=new File("/Volumes/HDD/java/test/testfile/azhu");
		//2.选择流、文件输出流
		OutputStream os=null;
		try {
			//以追加的形式写出文件
			//追加，需要写成true
			os=new FileOutputStream(dest,true);
			//3.操作
			String str="beijing beijing\r\n";
			//字符串转字节
			byte[] data=str.getBytes();
			os.write(data,0, data.length);
			
			os.flush();//强制刷新出去
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
			System.out.println("文件未找到");
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
			System.out.println("failed!");
		}finally{
			if(null!=os){
				try {
					os.close();
				} catch (IOException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
					System.out.println("Failed!");
				}
			}
		}
	}

}
