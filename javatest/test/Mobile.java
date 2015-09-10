package test;

import java.text.DateFormat;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Arrays;
import java.util.Date;

public class Mobile {
	public String toString(){
		return "ddddd";
	}
	
	public void print(){
		System.out.println("eeeee");
	}
	
	public static void otherprint(){
		System.out.println("wwwwwwww");
	}
	
	public static void main(String[] args){
//		int[] a={2,3,1,8,6,3,22,55};
//		Arrays.sort(a);
//		System.out.println(Arrays.toString(a));
		
//		Integer i=new Integer(100);
//		System.out.println(Integer.toHexString(100));
//		
//		Integer j=100;
//		
//		int m=new Integer(100);
		
//		Date d=new Date();
//		
//		long t=System.currentTimeMillis();
//		
//		System.out.println(t);
//		System.out.println(d);
//		
		
		DateFormat df=new SimpleDateFormat("yyyyƒÍMM‘¬dd»’");
		
		Date d=new Date(123213123L);
		
		System.out.println(df.format(d));
		
		String str2="1977-7-7";
		
		DateFormat df2=new SimpleDateFormat("yyyy-MM-dd");
		
		try {
			Date d2=df2.parse(str2);
			System.out.println(d2);
		} catch (ParseException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		
		
		
		
	}
}
