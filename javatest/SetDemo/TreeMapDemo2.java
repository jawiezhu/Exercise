package SetDemo;

import java.util.TreeMap;

public class TreeMapDemo2 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		// TODO Auto-generated method stub
		Worker w1=new Worker("TrashBack",12000);
		Worker w2=new Worker("Farmer",8000);
		Worker w3=new Worker("Grmger",9099);
		
		TreeMap<Worker,String> employees=new TreeMap<Worker,String>();
		employees.put(w1, "bj");
		employees.put(w2, "bj");
		employees.put(w3, "bj");
		System.out.println(employees.keySet());
			
				
				
	}

}
