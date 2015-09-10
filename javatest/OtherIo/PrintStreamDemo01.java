package OtherIo;

import java.io.BufferedOutputStream;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.PrintStream;

/**
 * 打印流->处理流
 * @author JawieZhu
 *
 */
public class PrintStreamDemo01 {

	public static void main(String[] args) throws FileNotFoundException {
		// TODO Auto-generated method stub
		System.out.println("dddd");
		
		PrintStream ps=System.out;
		ps.println(false);
		
		//输出到文件
		File src=new File("/Volumes/HDD/java/test/testfile/newzhu");
		ps=new PrintStream(new BufferedOutputStream(new FileOutputStream(src)));
		ps.println("iosiosiossososs"); 
		
		ps.close();
	}

}
