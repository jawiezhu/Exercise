package ByteIoDemo;
import java.io.File;
import java.io.IOException;

/**
 * 1. 递归查找子孙级文件和文件夹
 * 2. 文件 直接复制
 * 3. 文件夹 创建即可
 * 
 * @author JawieZhu
 *
 */
public class CopyDirDemo {
	
	
	public static void main(String[] args) {
		
		String srcPath="/Volumes/HDD/java/test/testfile";
		String destPath="/Volumes/HDD/java/test/aa";
		
		FileUtil.copyDir(srcPath,destPath);
	}
	
	

}
