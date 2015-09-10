package sort;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class Demo {
	public static void main(String[] args){
		String[] str={"azhu","dhuih","ddd","zzzz"};
		Utils.sort(str);
		System.out.println(Arrays.toString(str));
		
		//´æ·ÅÔÚÈİÆ÷ÖĞ
		List<String> list=new ArrayList<String>();
		list.add("a");
		list.add("abcd");
		list.add("dddd");
		
		Utils.sort(list);
		
		System.out.println(list);
		
		
		Utils.sort(str, new StrComparator());
		System.out.println(Arrays.toString(str));
		
		Utils.sort(list, new StrComparator());
		System.out.println(list);
	}
}
