package Map;

import java.util.HashMap;
import java.util.Map;
import java.util.Set;

/**
 * ͳ��ÿ�����ʳ��ֵĴ���
 * �洢��map��
 * 
 * key��String
 * value���Զ�������
 * 
 * ���ּ�
 * 1.Ϊ���е�key����������֮���Ŷ�Ӧ��value
 * 2.��һ�δ��������������value���ڶ���ֱ��ʹ���������ֵ
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
			System.out.println(key+"��"+col.getCount());
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
			Letter col=letters.get(temp);//ֱ��ʹ������
			col.setCount(col.getCount()+1);
		}
		
		*/
		
		for(String temp:strArray){
			//Ϊ����key��������
			if(!letters.containsKey(temp)){
				letters.put(temp, new Letter());
			}
			//֮�������д�Ŷ�Ӧvalue
			Letter col=letters.get(temp);
			col.setCount(col.getCount()+1);
		}
		
		Set<String> keys=letters.keySet();
		for(String key:keys){
			Letter col=letters.get(key);
			System.out.println(key+"��"+col.getCount());
		}
	}
}
