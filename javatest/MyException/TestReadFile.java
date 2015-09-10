package MyException;

import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;

public class TestReadFile {
	public static void main(String[] args){
		FileReader reader=null;
		try {
			
			reader=new FileReader("/Volumes/HDD/java/test/testfile/azhu");
			
				char c=(char) reader.read();
				System.out.println(c);
		
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (IOException e){
			e.printStackTrace();
		}finally{
			try {
				if(reader!=null){
				reader.close();
				}
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
		
		
	}
}
