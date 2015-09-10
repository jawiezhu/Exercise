package TestCollection;

import java.text.DateFormat;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.List;

public class TestEmployee { //JavaBean  µÃÂ¿‡
	public static void main(String[] args){
//		Employee e=new Employee();
//		e.setId(0301);
//		e.setName("azhu");
//		e.setDepartment("Development");
//		e.setSalary(3000);
//		String strDate="2007-10";
//		DateFormat format=new SimpleDateFormat("yyyy-MM");
//		try {
//			e.setHireDate(format.parse(strDate));
//		} catch (ParseException e1) {
//			// TODO Auto-generated catch block
//			e1.printStackTrace();
//		}
//		
		Employee e=new Employee(0301,"azhu",3000,"DP","2007-10");
		Employee e2=new Employee(0302,"zzhu",3050,"DPl","2008-10");
		Employee e3=new Employee(0303,"czhu",3800,"DPd","2009-10");
		
		List<Employee> list=new ArrayList<Employee>();
		
		list.add(e);
		list.add(e2);
		list.add(e3);
		printEmpName(list);
	}
	
	public static void printEmpName(List<Employee> list){
		for(int i=0;i<list.size();i++){
			System.out.println(list.get(i).getName());
		}
	}
	
	
}
