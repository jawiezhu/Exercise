package SetDemo;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

/**
 * 
 * @author JawieZhu
 *
 */
public class CollectionsDemo01 {
	public static void main(String[] args){
		List<Integer> list=new ArrayList<Integer>();
		for(int i=0;i<54;i++){
			list.add(i);
		}
		
		Collections.shuffle(list);
		
		List<Integer> p1=new ArrayList<Integer>();
		List<Integer> p2=new ArrayList<Integer>();
		List<Integer> p3=new ArrayList<Integer>();
		List<Integer> last=new ArrayList<Integer>();
		
		for(int i=0;i<51;i+=3){
			p1.add(list.get(i));
			p2.add(list.get(i+1));
			p3.add(list.get(i+2));
			
		}
		last.add(list.get(51));
		last.add(list.get(52));
		last.add(list.get(53));
		
		System.out.println(p1);
		System.out.println(p2);
		System.out.println(p3);
		System.out.println(last);
		
		
	}
	
	public static void test01(List<Integer> list){
		list.add(1);
		list.add(2);
		list.add(3);
		list.add(4);
		Collections.reverse(list);
		System.out.println(list);
	}
}
