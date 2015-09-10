package BufferedDemo;

import java.io.BufferedInputStream;
import java.io.BufferedOutputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.InputStream;
import java.io.OutputStream;

public class BufferedByteDemo {

	public static void main(String[] args) throws FileNotFoundException {
		// TODO Auto-generated method stub
		String srcPath="/Volumes/HDD/java/test/testfile/azhu";
		String destPath="/Volumes/HDD/java/test/testfile/huihui";
		
		File src=new File(srcPath);
		File dest=new File(destPath);
		
		InputStream is=new BufferedInputStream(new FileInputStream(src));
		OutputStream os=new BufferedOutputStream(new FileOutputStream(dest));
	}

}
