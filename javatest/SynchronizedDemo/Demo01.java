package SynchronizedDemo;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

/**
 * ʹ��collectionͬ����������
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
