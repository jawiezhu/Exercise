package GoodsDemo;

import java.util.Comparator;
/*
 * �����ղ����� ����
 */
public class GoodsFavCmp implements Comparator<Goods> {

	@Override
	public int compare(Goods o1, Goods o2) {
		// TODO Auto-generated method stub
		return o1.getFav()-o2.getFav();
	}

}
