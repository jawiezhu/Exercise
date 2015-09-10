package SynchronizedDemo;

import java.util.Collections;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Set;

/**
 * 只读
 * @author JawieZhu
 *
 */
public class Demo02 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Map<String,String> map=new HashMap<String,String>();
		map.put("test", "sss");
		map.put("ssss", "sssssf");
		
		//控制只读
		Map<String,String> map2=Collections.unmodifiableMap(map);
		
		map2.put("Ddd", "dddddssa");
		
		System.out.println(map2.size());
		
		//一个元素的容器测试
		List<String> list=Collections.singletonList(new String());
		
	}
	
	public static Set<String> oper(Set<String> set){
		if(null==set){
			return Collections.EMPTY_SET;
			//外部获取就不用处理空的问题
		}
		//
		return set;
	}

}
