package GoodsDemo;

import java.util.Comparator;

/**
 * ���ռ۸������ҵ���� ����
 * @author JawieZhu
 *
 */
public class GoodsPriceCmp implements Comparator<Goods> {

	@Override
	public int compare(Goods o1, Goods o2) {
		// TODO Auto-generated method stub
		return -(o1.getPrice()-o2.getPrice()>0?1:(o1.getPrice()==o2.getPrice()?0:-1));
		//��Ϊ���� 0 1 ����double����Ҫ��������������ֱ���������
	}
	
	
}
