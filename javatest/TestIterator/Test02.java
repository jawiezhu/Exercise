package TestIterator;

import java.util.HashMap;
import java.util.Iterator;
import java.util.Map;
import java.util.Set;

public class Test02 {
	public static void main(String[] args){
		Map map=new HashMap();
		Set keys=map.keySet();
		map.put("aaa", 123);
		map.put("bbb",333);
		
		
		for(Iterator iter=keys.iterator();iter.hasNext();){
			String keyStr=(String) iter.next();
			System.out.println(keyStr+map.get(keyStr));
		}
		
	}
}
