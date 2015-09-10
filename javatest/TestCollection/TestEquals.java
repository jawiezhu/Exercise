package TestCollection;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class TestEquals {
	public static void main(String[] args){
		List list=new ArrayList();
		String s1=new String("aaa");
		String s2=new String("aaa");
		
		list.add(s1);
		list.add(s2);
		
		Map map=new HashMap();
		map.put(s1,"AAAA");
		map.put(s2, "BBBBBB"); //s1.equals(s2)==true,À˘“‘±ª∏≤∏«
		System.out.println(map.size());
		System.out.println(map.get("aaa"));
		
		
	}
}
