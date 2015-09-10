package GoodsDemo;

import java.util.Comparator;
/*
 * 按照收藏量的 升序
 */
public class GoodsFavCmp implements Comparator<Goods> {

	@Override
	public int compare(Goods o1, Goods o2) {
		// TODO Auto-generated method stub
		return o1.getFav()-o2.getFav();
	}

}
