package SynchronizedDemo;

 

public class SynDemo01 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Web12306 test=new Web12306();
		Thread proxy=new Thread(test,"路人甲");
		Thread pro2=new Thread(test,"黄牛");
		Thread pro3=new Thread(test,"工程师");
		
		proxy.start();
		pro2.start();
		pro3.start(); 
	}

}


class Web12306 implements Runnable{
	private int num=20;
	private boolean flag=true;

	@Override
	public void run() {
	
		while(flag){
			test6();
		}
	}
	
	
	
	public  void test6(){
		
		if(num==1){
			flag=false;
			return ;
		}
		synchronized(this){
			try {
				Thread.sleep(50);
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
			System.out.println(Thread.currentThread().getName()+"Got!"+num--);
			
		}
	}
	
	
	
	//线程不安全 锁定资源不正确
	public  void test5(){
		synchronized((Integer) num){
		if(num<=0){
			flag=false;
			return ;
		}
		
			try {
				Thread.sleep(50);
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
			System.out.println(Thread.currentThread().getName()+"Got!"+num--);
			
		}
	}
	
	
	
	//锁定范围不正确
	public  void test4(){
		
		synchronized(this){
		if(num<=0){
			flag=false;
			return ;
		}
		}
		
			try {
				Thread.sleep(50);
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
			System.out.println(Thread.currentThread().getName()+"Got!"+num--);
			
		}
	
	
	
	
	
	
	//同步块
	public  void test3(){
		synchronized(this){
		if(num<=0){
			flag=false;
			return ;
		}
		
			try {
				Thread.sleep(50);
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
			System.out.println(Thread.currentThread().getName()+"Got!"+num--);
			
		}
	}
	
	
	//同步方法
	public synchronized void test2(){
		if(num<=0){
			flag=false;
			return ;
		}
		
			try {
				Thread.sleep(50);
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
			System.out.println(Thread.currentThread().getName()+"Got!"+num--);
			
		
	}
	
	
	//线程不安全
	public void test1(){
		if(num<=0){
			flag=false;
		}
		
			try {
				Thread.sleep(500);
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
			System.out.println(Thread.currentThread().getName()+"Got!"+num--);
			
		
	}
}
	