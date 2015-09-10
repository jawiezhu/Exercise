package RefDemo;

import java.util.WeakHashMap;

/**
 * WeakHashMap 建为弱类型，gc运行立即回收
 * @author JawieZhu
 *
 */
public class WeakHashMapDemo{

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		WeakHashMap<String,String> map=new WeakHashMap<String,String>();
		
		//常量池对象不被回收
		map.put("a", "bb");
		map.put("b", "dd");
		
		//gc运行已被回收
		map.put(new String("btdd"), "c");
		map.put(new String("dss"), "d");
		
		System.gc();
		System.runFinalization();
		
	}

}
