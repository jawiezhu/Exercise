package SetDemo;

import java.util.Comparator;
import java.util.TreeSet;
/**
 * 提供 业务排序类 comparator
 * @author JawieZhu
 *
 */
public class TreeSetDemo {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Person p1=new Person("you",100);
		Person p2=new Person("liu",1000);
		Person p3=new Person("hhaa",110);
		Person p4=new Person("acgirl",222);
		
		//使用排序的业务类 匿名内部类
		TreeSet<Person> persons=new TreeSet<Person>(
				new Comparator<Person>(){

					@Override
					public int compare(Person o1, Person o2) {
						// TODO Auto-generated method stub
						
						return o1.getHandsome()-o2.getHandsome();
					}
					
				});
		
		
		persons.add(p1);
		
		persons.add(p2);
		persons.add(p3);
		persons.add(p4);
		
		System.out.println(persons);
		
	}

}
