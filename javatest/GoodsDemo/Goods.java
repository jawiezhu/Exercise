package GoodsDemo;
/**
 * ��ʵ���κνӿ�
 * @author JawieZhu
 *
 */
public class Goods {
	private String name;
	private double price;
	private int fav;
	
	
	public Goods() {
		super();
		// TODO Auto-generated constructor stub
	}
	
	public Goods(String name, double price, int fav) {
		super();
		this.name = name;
		this.price = price;
		this.fav = fav;
	}
	
	public String getName() {
		return name;
	}
	public void setName(String name) {
		this.name = name;
	}
	public double getPrice() {
		return price;
	}
	public void setPrice(double price) {
		this.price = price;
	}
	public int getFav() {
		return fav;
	}
	public void setFav(int fav) {
		this.fav = fav;
	}
	@Override
	public String toString() {
		return "��Ʒ����"+this.name+";�ղ���"+this.fav+"���۸�:"+this.price+"\n";
	}
	
	
	
}
