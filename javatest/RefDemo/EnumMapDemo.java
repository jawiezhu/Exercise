package RefDemo;

import java.util.EnumMap;

/*
 * EnumMap要求jian 为枚举
 */
public class EnumMapDemo {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		EnumMap<Season,String> map=new EnumMap<Season,String>(Season.class);
		
		map.put(Season.SPRING, "aa");
		map.put(Season.SUMMER, "dd");
		map.put(Season.AUTUMN, "dddd");
		map.put(Season.WINTER, "ddddd");
		
		System.out.println(map.size());
	}

}

enum Season{
	SPRING,SUMMER,AUTUMN,WINTER
}
