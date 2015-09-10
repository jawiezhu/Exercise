package TestIterator;


import java.util.ArrayList;
import java.util.HashSet;
import java.util.Iterator;
import java.util.List;
import java.util.Scanner;
import java.util.Set;

public class Test01 {
	public static void main(String[] args){
		List list=new ArrayList();
		list.add("aaa");
		list.add("bbb");
		list.add("ccc");
		
//		for(int i=0;i<list.size();i++){
//			System.out.println(list.get(i));
//		}
		
		//Scanner scan=new Scanner(System.in);
		
		Set set=new HashSet();
		set.add("azhu");
		set.add("bzhu");
		set.add("czhu");
		
//		Iterator iter=set.iterator();
//		while(iter.hasNext()){
//			String str=(String) iter.next();
//			System.out.println(str);
//		}
		
		for(Iterator iter=set.iterator();iter.hasNext();){
			String str=(String) iter.next();
			System.out.println(str);
		}
		
	}
}
