package SynchronizedDemo;

public class SynDemo03 {

	public static void main(String[] args) {
		Object g=new Object();
		Object m=new Object();
		// TODO Auto-generated method stub
		Test t1=new Test(g,m);
		Test2 t2=new Test2(g,m);
		
		Thread pro=new Thread(t1);
		Thread pro2=new Thread(t2);
		pro.start();
		pro2.start();
		
	}

}


class Test implements Runnable{
	Object goods;
	Object money;
	
	public Test(Object goods, Object money) {
		super();
		this.goods = goods;
		this.money = money;
	}

	@Override
	public void run() {
		// TODO Auto-generated method stub
		while(true){
			test();
		}
	}
	
	public void test(){
		synchronized(goods){
			try {
				Thread.sleep(500);
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
			
			synchronized(money){
				
			}
			
		}
		
		System.out.println("give money!~~~");
	}
	
}


class Test2 implements Runnable{
	Object goods;
	Object money;
	
	
	public Test2(Object goods, Object money) {
		super();
		this.goods = goods;
		this.money = money;
	}

	@Override
	public void run() {
		// TODO Auto-generated method stub
		while(true){
			test();
		}
	}
	
	public void test(){
		synchronized(money){
			try {
				Thread.sleep(500);
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
			
			synchronized(goods){
				
			}
			
		}
		
		System.out.println("give goods!~~~");
	}
}