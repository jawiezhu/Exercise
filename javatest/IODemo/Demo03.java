package IODemo;

import java.io.File;
import java.io.IOException;

/**
 * ���÷�����
 * 
 * @author JawieZhu
 *
 */
public class Demo03 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		//test01();
		//test02();
		try {
			test03();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (InterruptedException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}

	public static void test01(){
		File src=new File("/Volumes/HDD/java/test/testfile/zhuazhu");
		System.out.println(src.getName());
		System.out.println(src.getPath());
		System.out.println(src.getAbsolutePath());
		System.out.println(src.getParent());//�����ϼ�Ŀ¼��û���ϼ�������null
	}
	
	public static void test02(){
		File src=new File("/Volumes/HDD/java/test/testfile/");
		System.out.println("IS OR NOT:"+src.exists());
		File src2=new File("/Volumes/HDD/java/test/testfile/azhu");
		System.out.println("SRC2 IS OR NOT:"+src2.exists());
		
		System.out.println("CanWrite? "+src2.canWrite());
		
		System.out.println("isFile?"+src2.isFile());
		System.out.println("isDirectory?"+src.isDirectory());
		
		if(src2.isFile()){
			System.out.println("File");
		}else if(src2.isDirectory()){
			System.out.println("Directory");
		}else{
			System.out.println("File not exist");
		}
		
		System.out.println("Absolute?"+src2.isAbsolute());
		
		System.out.println("length= "+src.length());//�ֽ�����ֻ���ļ����Զ�ȡ��
		
	}
	
	public static void test03() throws IOException, InterruptedException{
		String path="/Volumes/HDD/java/test/testfile/200.jpg";
		File src=new File(path);
		if(!src.exists()){
			boolean flag=src.createNewFile();
			System.out.println(flag?"yes":"no");
		}
		
		boolean flag=src.delete();
		System.out.println(flag?"yes":"no");
		
		//static createTempFile(ǰ׺3���ֽڳ�����׺Ĭ��.temp��Ĭ����ʱ�ռ�
		File temp=File.createTempFile("tes",".temp", new File("/Volumes/HDD/java/test/testfile/"));
		Thread.sleep(5000);
		temp.deleteOnExit(); //�˳���ɾ��
		
	}
}
