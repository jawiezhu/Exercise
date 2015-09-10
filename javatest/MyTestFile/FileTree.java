package MyTestFile;

import java.io.File;
import java.util.Arrays;

public class FileTree {
	
	public static void main(String[] args){
		File f=new File("/Volumes/HDD/java/test/testfile");
		printFile(f,0);
	}
	
	public static void printFile(File file,int level){
		for(int i=0;i<level;i++)
		{
			System.out.print("-");
		}
		
		System.out.println(file.getName());
		
		if(file.isDirectory()){
			File[] files=file.listFiles();
			//System.out.println(files.length);
			System.out.println(Arrays.toString(files));
			for(File temp:files){
				printFile(temp,level+1);
			}
		}
	}
}
