package IODemo;

import java.io.File;
import java.io.FilenameFilter;
import java.util.Arrays;

/**
 * ����Ŀ¼
 * mkdir ����Ŀ¼����֤��Ŀ¼���ڣ���������ʧ��
 * mkdirs ����Ŀ¼�������Ŀ¼�����ڣ�һͬ����
 * list 
 * 
 * @author JawieZhu
 *
 */
public class Demo04 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		test01();
	}
	
	public static void test01(){
		String path="/Volumes/HDD/java/test/testfile";
		File src=new File(path);
		src.mkdirs();
		
		String[] subnames=src.list();
		System.out.println(Arrays.toString(subnames));
		
		
		File[] subFiles=src.listFiles();
	
		
		//�������ģʽ
		subFiles=src.listFiles(new FilenameFilter(){

			@Override
			public boolean accept(File dir, String name) {
				// TODO Auto-generated method stub
				//System.out.println(dir.getAbsolutePath());
				return new File(dir,name).isFile()&&name.endsWith(".java");
			}
			
		});
		
		for(File temp:subFiles){
			System.out.println(temp);
		}

		
	}

}
