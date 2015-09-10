package TestCollection;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class CollectEmployee {

	
	public static void main(String[] args){
		Map map=new HashMap();
		map.put("id",0301);
		map.put("name","azhu");
		map.put("salary",3500);
		map.put("department","development");
		map.put("hireDate", "2006-10");
		
		Map map2=new HashMap();
		map2.put("id",0302);
		map2.put("name","bzhu");
		map2.put("salary",5500);
		map2.put("department","vvdevelopment");
		map2.put("hireDate", "2016-10");
		
		
		Map map3=new HashMap();
		map3.put("id",0303);
		map3.put("name","czhu");
		map3.put("salary",4500);
		map3.put("department","bvdevelopment");
		map3.put("hireDate", "2116-10");
		
		List<Map> list=new ArrayList<Map>();
		
		list.add(map);
		list.add(map2);
		list.add(map3);
		
		printEmpName(list);
	}
	
	
	public static void printEmpName(List<Map> list){
		for(int i=0;i<list.size();i++){
			Map tempMap=list.get(i);
			System.out.println(tempMap.get("name"));
		}
	}
}
