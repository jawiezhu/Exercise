package MyTestFile;

import java.io.File;
import java.io.IOException;

public class TestFile {
	
	public static void main(String[] args){
		File f=new File("/Volumes/HDD/java/test/testfile/azhu");
	
	
		if(f.isFile()){
			System.out.println("Yes!");
		}
		
		File f2=new File("/Volumes/HDD/java/test/testfile/huihui");
		try {
			f2.createNewFile();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		f2.delete();
		
		
		
	}
	
}
