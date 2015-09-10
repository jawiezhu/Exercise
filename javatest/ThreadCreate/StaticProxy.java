package ThreadCreate;

/**
 * 静态代理设计模式
 * 有 真实角色
 * 有 代理角色 要持有 真实角色的引用
 * 二者 要实现 相同 接口
 * 
 * @author JawieZhu
 *
 */
public class StaticProxy {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		//创建真实角色
		You you=new You();
		//创建代理角色 加入 真实角色的引用
		WeddingCompany company=new WeddingCompany(you);
		//或者 无新增方法 可以用接口
		//Marry company=new WeddingCompany(); 
		
		//执行任务
		company.marry();
		
	}

}

interface Marry{
	//公共的抽象方法
	void marry();
	
}
//真实角色
class You implements Marry{

	@Override
	public void marry() {
		// TODO Auto-generated method stub
		System.out.println("wedding!~~~~~~");
	}
}

//代理角色
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
