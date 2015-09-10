package ThreadCreate;

/**
 * ��̬�������ģʽ
 * �� ��ʵ��ɫ
 * �� �����ɫ Ҫ���� ��ʵ��ɫ������
 * ���� Ҫʵ�� ��ͬ �ӿ�
 * 
 * @author JawieZhu
 *
 */
public class StaticProxy {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		//������ʵ��ɫ
		You you=new You();
		//���������ɫ ���� ��ʵ��ɫ������
		WeddingCompany company=new WeddingCompany(you);
		//���� ���������� �����ýӿ�
		//Marry company=new WeddingCompany(); 
		
		//ִ������
		company.marry();
		
	}

}

interface Marry{
	//�����ĳ��󷽷�
	void marry();
	
}
//��ʵ��ɫ
class You implements Marry{

	@Override
	public void marry() {
		// TODO Auto-generated method stub
		System.out.println("wedding!~~~~~~");
	}
}

//�����ɫ
class WeddingCompany implements Marry{
	private Marry you;
	
	public WeddingCompany(){
		
	}
	
	
	public WeddingCompany(Marry you) {
		super();
		this.you = you;
	}

	private void before(){
		System.out.println("before~~~~~~");
	}
	
	private void after(){
		System.out.println("after~~~~~~");
	}
	
	@Override
	public void marry() {
		// TODO Auto-generated method stub
		before();
		you.marry();
		after();
	}
	
}
