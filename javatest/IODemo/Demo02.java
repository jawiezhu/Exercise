package IODemo;

import java.io.File;

/**
 * 相对路径与绝对路径
 * @author JawieZhu
 *
 */
public class Demo02 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		String parentPath="/Volumes/HDD/java/test/testfile";
		String name="azhua";
		//相对路径构建
		File src=new File(parentPath,name);
		src=new File(new File(parentPath),name);
		
		System.out.println(src.getName());
		System.out.println(src.getPath());
		
		//绝对路径
		File src2=new File("/Volumes/HDD/java/test/testfile/azhua");
		
		//没有盘符，以user.dir构建
		File src3=new File("azhuazhu.txt");
		System.out.println(src3.getAbsolutePath());
		
		//表示当前路径
		File src4=new File(".");
		System.out.println(src4.getAbsolutePath());
	}

}
