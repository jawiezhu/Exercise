package SynchronizedDemo;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

/**
 * 使用collection同步管理容器
 * @author JawieZhu
 *
 */
public class Demo01 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		List<String> list=new ArrayList<String>();
		list.add("a");
		list.add("b");
		List<String> synList=Collections.synchronizedList(list);
		
		
	}

}
