package CharIoDemo;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.Writer;

public class Demo02 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		File dest=new File("/Volumes/HDD/java/test/testfile/newazhu");
		
		Writer wr=null;
		try {
			wr=new FileWriter(dest);
			
			String meg="newazhu hello love you~";
			wr.write(meg);
			wr.append("aaaaaaaaa");
			
			wr.flush();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}finally{
			if(null!=wr){
				try {
					wr.close();
				} catch (IOException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
			}
		}
		
	}

}
