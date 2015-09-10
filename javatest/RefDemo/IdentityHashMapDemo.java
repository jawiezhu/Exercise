package RefDemo;

import java.util.IdentityHashMap;

/**
 * IdentityHashMap 建比较地址去重
 * @author JawieZhu
 *
 */
public class IdentityHashMapDemo {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		IdentityHashMap<String,String> map=new IdentityHashMap<String,String>();
		
		//常量池中的a
		map.put("a", "a1");
		map.put("a","a2");
		//以下两个是不同的地址，所以都可以进入IdentityHashMap
		map.put(new String("a"),"a3");
		map.put(new String("a"),"a4");
		
		
	}

}
