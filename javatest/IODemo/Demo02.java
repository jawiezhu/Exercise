package IODemo;

import java.io.File;

/**
 * ���·�������·��
 * @author JawieZhu
 *
 */
public class Demo02 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		String parentPath="/Volumes/HDD/java/test/testfile";
		String name="azhua";
		//���·������
		File src=new File(parentPath,name);
		src=new File(new File(parentPath),name);
		
		System.out.println(src.getName());
		System.out.println(src.getPath());
		
		//����·��
		File src2=new File("/Volumes/HDD/java/test/testfile/azhua");
		
		//û���̷�����user.dir����
		File src3=new File("azhuazhu.txt");
		System.out.println(src3.getAbsolutePath());
		
		//��ʾ��ǰ·��
		File src4=new File(".");
		System.out.println(src4.getAbsolutePath());
	}

}
