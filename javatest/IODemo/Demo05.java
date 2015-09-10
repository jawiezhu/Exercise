package IODemo;

import java.io.File;
import java.util.Arrays;


/**
 * ������ＶĿ¼|�ļ�������
 * 1.listFiles()
 * @author JawieZhu
 *
 *������չ�� �����ļ� ���� �����ض��ļ�
 */
public class Demo05 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		String path="/Volumes/HDD/java/test/testfile";
		File parent=new File(path);
		printName(parent);
		
		File[] roots=File.listRoots();
		System.out.println(Arrays.toString(roots));
	}
	
	public static void printName(File src){
		if(null==src||!src.exists()){
			return ;
		}
		System.out.println(src.getAbsolutePath());
		
		if(src.isDirectory())
			for(File sub:src.listFiles())
				//System.out.println(sub);
				printName(sub);
	}

}
