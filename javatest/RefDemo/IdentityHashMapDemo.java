package RefDemo;

import java.util.IdentityHashMap;

/**
 * IdentityHashMap ���Ƚϵ�ַȥ��
 * @author JawieZhu
 *
 */
public class IdentityHashMapDemo {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		IdentityHashMap<String,String> map=new IdentityHashMap<String,String>();
		
		//�������е�a
		map.put("a", "a1");
		map.put("a","a2");
		//���������ǲ�ͬ�ĵ�ַ�����Զ����Խ���IdentityHashMap
		map.put(new String("a"),"a3");
		map.put(new String("a"),"a4");
		
		
	}

}
