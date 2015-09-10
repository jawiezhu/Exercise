package SetDemo;

import java.util.Comparator;
import java.util.Set;
import java.util.TreeMap;



public class TreeMapDemo {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Person p1=new Person("you",100);
		Person p2=new Person("liu",1000);
		Person p3=new Person("hhaa",110);
		Person p4=new Person("acgirl",222);
		
		TreeMap<Person,String> map=new TreeMap<Person,String>(new Comparator<Person>(){

			@Override
			public int compare(Person o1, Person o2) {
				// TODO Auto-generated method stub
				
				return o1.getHandsome()-o2.getHandsome();
			}
			
		});
		map.put(p1, "bj");
		map.put(p2, "bj");
		map.put(p3, "bj");
		map.put(p4, "bj");
		
		//²é¿´¼ü
		Set<Person> persons=map.keySet();
		
		System.out.println(persons);
		
		
	}

}
