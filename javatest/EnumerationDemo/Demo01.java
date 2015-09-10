package EnumerationDemo;

import java.util.Enumeration;
import java.util.Vector;

/**
 * Enumeraion
 * 1. �ж� hasMoreElments()
 * 2. ��ȡ nextElement()
 * @author JawieZhu
 *
 *
 * Vector�� elements����
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
