package ByteIoDemo;
import java.io.File;
import java.io.IOException;

/**
 * 1. �ݹ�������Ｖ�ļ����ļ���
 * 2. �ļ� ֱ�Ӹ���
 * 3. �ļ��� ��������
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
