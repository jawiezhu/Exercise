package TestCollection;

import java.util.HashMap;
import java.util.Map;

public class TestMap {
	public static void main(String[] args){
		Map map=new HashMap();
		map.put("azhu", new Wife("zhua"));
		map.put("huihui","gou");
		
		Wife w=(Wife) map.get("azhu");
		System.out.println(w.name);
		map.remove("azhu");
		
		System.out.println(map.size());
		
		System.out.println(map.get("azhu"));
		System.out.println(map.containsValue(new Wife("zhua")));
		
		
	}
}


class Wife{
	String name;
	
	public Wife(String name){
		this.name=name;
	}
}