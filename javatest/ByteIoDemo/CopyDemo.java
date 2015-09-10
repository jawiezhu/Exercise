package ByteIoDemo;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;

public class CopyDemo {

	public static void main(String[] args) throws IOException {
		//1.建立联系
		String src="/Volumes/HDD/java/test/testfile/1.png";
		String dest="/Volumes/HDD/java/test/testfile/hui/110.png";
		FileUtil.copyFile(src,dest);
	}

	
}
