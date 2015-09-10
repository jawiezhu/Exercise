package GoodsDemo;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class GoodsApp {
	public static void main(String[] args){
		List<Goods> list=new ArrayList<Goods>();
		list.add(new Goods("kinoshita",100,20000));
		list.add(new Goods("aaaa",10,2000));
		list.add(new Goods("bbbb",1222,100000));
		
		//Collections.sort(list, new GoodsPriceCmp());
		Collections.sort(list, new GoodsFavCmp());
		System.out.println(list);
	}
}
