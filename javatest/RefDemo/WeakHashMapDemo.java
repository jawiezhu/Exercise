package RefDemo;

import java.util.WeakHashMap;

/**
 * WeakHashMap ��Ϊ�����ͣ�gc������������
 * @author JawieZhu
 *
 */
public class WeakHashMapDemo{

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		WeakHashMap<String,String> map=new WeakHashMap<String,String>();
		
		//�����ض��󲻱�����
		map.put("a", "bb");
		map.put("b", "dd");
		
		//gc�����ѱ�����
		map.put(new String("btdd"), "c");
		map.put(new String("dss"), "d");
		
		System.gc();
		System.runFinalization();
		
	}

}
