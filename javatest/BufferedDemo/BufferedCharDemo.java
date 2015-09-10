package BufferedDemo;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.Reader;
import java.io.Writer;

public class BufferedCharDemo {

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		File src=new File("/Volumes/HDD/java/test/testfile/azhu");
		File dest=new File("/Volumes/HDD/java/test/testfile/newzhu");
		
//		新增功能不能多态
//		Reader reader=null;
//		Writer wr=null;
		BufferedReader reader=null;
		BufferedWriter wr=null;
		
		reader=new BufferedReader(new FileReader(src));
		wr=new BufferedWriter(new FileWriter(dest));
//		char[] car=new char[1024];
//		int len=0;
//		while(-1!=(len=reader.read(car))){
//			wr.write(car, 0, len);
//		}
		
		String line=null;
		while(null!=(line=reader.readLine()) ){
			wr.write(line);
			wr.newLine();//换行符
		}
		wr.flush();
		
		wr.close();
		reader.close();
	}

}
