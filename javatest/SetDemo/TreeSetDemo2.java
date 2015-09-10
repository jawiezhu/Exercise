package SetDemo;

import java.util.TreeSet;
/**
 * 实体类实现 comparable
 * @author JawieZhu
 *
 */
public class TreeSetDemo2 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Worker w1=new Worker("TrashBack",12000);
		Worker w2=new Worker("Farmer",8000);
		Worker w3=new Worker("Grmger",9099);
		
		TreeSet<Worker> employees=new TreeSet<Worker>();
		
		employees.add(w1);
		employees.add(w2);
		employees.add(w3);
		System.out.println(employees);
	}

}
