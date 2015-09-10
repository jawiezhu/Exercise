package TestCollection;

import java.util.ArrayList;
import java.util.Collection;
import java.util.Date;
import java.util.List;

public class Test01 {
	 public static void main(String[] args){
		 List list=new ArrayList();
		 
		 list.add(1234);
		 list.add("aaa");
		 list.add(new Date());
		 
		 System.out.println(list.size());
		 list.remove("aaa");
		 
		 int str=(Integer) list.get(0);
		 System.out.println(str);
		 
		 list.set(1,"ababa");
	 }
}
