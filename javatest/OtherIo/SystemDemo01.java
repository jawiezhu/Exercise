package OtherIo;

import java.io.BufferedInputStream;
import java.io.BufferedOutputStream;
import java.io.FileDescriptor;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.InputStream;
import java.io.PrintStream;
import java.util.Scanner;

public class SystemDemo01 {

	public static void main(String[] args) throws FileNotFoundException {
		// TODO Auto-generated method stub
//		test1();
//		test2();
		
		 System.setOut(new PrintStream(new BufferedOutputStream
				 (new FileOutputStream
						 ("/Volumes/HDD/java/test/testfile/printazhu")),true));
		 //让其自动刷新 true
		 
		 System.out.println("ddddlaldkjagkldajdf");
		 
		 //回控制台
		 System.setOut(new PrintStream(new BufferedOutputStream(
				 new FileOutputStream(FileDescriptor.out)),true));
		 System.out.println("back~!!");
		 
		 
	}
	
	public static void test2() throws FileNotFoundException{
		InputStream is=System.in;
		is=new BufferedInputStream(new FileInputStream("/Volumes/HDD/java/test/testfile/newazhu"));
		Scanner sc=new Scanner(is);
		System.out.println(sc.nextLine());
	}
	
	public static void test1(){
		System.out.println("Aaa");
		System.err.println("ddddd");
	}
	
}
