package SynchronizedDemo;

import java.util.Collections;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Set;

/**
 * ֻ��
 * @author JawieZhu
 *
 */
public class Demo02 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Map<String,String> map=new HashMap<String,String>();
		map.put("test", "sss");
		map.put("ssss", "sssssf");
		
		//����ֻ��
		Map<String,String> map2=Collections.unmodifiableMap(map);
		
		map2.put("Ddd", "dddddssa");
		
		System.out.println(map2.size());
		
		//һ��Ԫ�ص���������
		List<String> list=Collections.singletonList(new String());
		
	}
	
	public static Set<String> oper(Set<String> set){
		if(null==set){
			return Collections.EMPTY_SET;
			//�ⲿ��ȡ�Ͳ��ô���յ�����
		}
		//
		return set;
	}

}
