package EnumerationDemo;

import java.util.Enumeration;
import java.util.Vector;

/**
 * Enumeraion
 * 1. 判断 hasMoreElments()
 * 2. 获取 nextElement()
 * @author JawieZhu
 *
 *
 * Vector中 elements方法
 */


public class Demo01 {
	public static void main(String[] args){
		Vector<String> vector=new Vector<String>();
		vector.add("javase");
		vector.add("html");
		vector.add("oracle");
		
		Enumeration<String> en=vector.elements();
		
		while(en.hasMoreElements()){
			System.out.println(en.nextElement());
		}
	}
}
