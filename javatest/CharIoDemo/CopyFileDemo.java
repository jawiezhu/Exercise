package CharIoDemo;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.Reader;
import java.io.Writer;

public class CopyFileDemo {

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		File src=new File("/Volumes/HDD/java/test/testfile/azhu");
		File dest=new File("/Volumes/HDD/java/test/testfile/hui/azhu");
		
		Reader reader=null;
		Writer wr=null;
		
		reader=new FileReader(src);
		wr=new FileWriter(dest);
		char[] car=new char[1024];
		int len=0;
		while(-1!=(len=reader.read(car))){
			wr.write(car, 0, len);
		}
		wr.flush();
		
		wr.close();
		reader.close();
	}

}
