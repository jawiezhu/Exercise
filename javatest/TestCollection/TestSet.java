package TestCollection;

import java.util.HashSet;
import java.util.Set;

public class TestSet {
	public static void main(String[] args){
		Set set=new HashSet();
		set.add("aaa");
		set.add(new String("aaa"));
		System.out.println(set.size());
		
	}
}
