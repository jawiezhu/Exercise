package sort;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class Demo05 {
	public static void main(String[] args){
		List<String> list=new ArrayList<String>();
		list.add("a");
		list.add("aaa");
		list.add("defdd");
		list.add("abc");
		Collections.sort(list, new StrComparator());
		System.out.println(list);
		
		list=new ArrayList<String>();
		list.add("z");
		list.add("aaa");
		list.add("defdvvvv");
		list.add("abc");
		Collections.sort(list);
		System.out.println(list);
		
	
	}
}
