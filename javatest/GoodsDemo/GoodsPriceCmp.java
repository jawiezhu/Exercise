package GoodsDemo;

import java.util.Comparator;

/**
 * 按照价格排序的业务类 降序
 * @author JawieZhu
 *
 */
public class GoodsPriceCmp implements Comparator<Goods> {

	@Override
	public int compare(Goods o1, Goods o2) {
		// TODO Auto-generated method stub
		return -(o1.getPrice()-o2.getPrice()>0?1:(o1.getPrice()==o2.getPrice()?0:-1));
		//因为返回 0 1 所以double类型要上述处理，而整形直接相减即可
	}
	
	
}
