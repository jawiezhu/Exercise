package Map;

import java.util.HashMap;
import java.util.Map;
import java.util.Set;

/**
 * 统计每个单词出现的次数
 * 存储到map中
 * 
 * key：String
 * value：自定义类型
 * 
 * “分拣”
 * 1.为所有的key创建容器、之后存放对应的value
 * 2.第一次创建容器，并存放value、第二次直接使用容器存放值
 * 
 *
 * @author JawieZhu
 *
 */

public class Demo01 {
	public static void main(String[] args){
		String str="this is a cat and that is a mice and where is the food";
		String[] strArray=str.split(" ");
		Map<String,Letter> letters=new HashMap<String,Letter>();
		
//		for(String temp:strArray){
//			if(!letters.containsKey(temp)){
//				Letter col=new Letter();
//				col.setCount(1);
//				letters.put(temp, col);
//			}else{
//				Letter col=letters.get(temp);
//				col.setCount(col.getCount()+1);
//			}
//		}
		for(String temp:strArray){
			Letter col=null;
			if(null==(col=letters.get(temp))){
				col=new Letter();
				col.setCount(1);
				letters.put(temp, col);
			}else{
				col.setCount(col.getCount()+1);
			}
		}
		
		Set<String> keys=letters.keySet();
		for(String key:keys){
			Letter col=letters.get(key);
			System.out.println(key+"："+col.getCount());
		}
	}
	
	public static void test1(){
		String str="this is a cat and that is a mice and where is the food";
		String[] strArray=str.split(" ");
		Map<String,Letter> letters=new HashMap<String,Letter>();
		/*
		for(String temp:strArray){
		
			if(!letters.containsKey(temp)){
				letters.put(temp, new Letter());
			}
			
		}
		
		for(String temp:strArray){
			Letter col=letters.get(temp);//直接使用容器
			col.setCount(col.getCount()+1);
		}
		
		*/
		
		for(String temp:strArray){
			//为所有key创建容器
			if(!letters.containsKey(temp)){
				letters.put(temp, new Letter());
			}
			//之后容器中存放对应value
			Letter col=letters.get(temp);
			col.setCount(col.getCount()+1);
		}
		
		Set<String> keys=letters.keySet();
		for(String key:keys){
			Letter col=letters.get(key);
			System.out.println(key+"："+col.getCount());
		}
	}
}
