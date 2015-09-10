package SynchronizedDemo;

 

public class SynDemo01 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Web12306 test=new Web12306();
		Thread proxy=new Thread(test,"·�˼�");
		Thread pro2=new Thread(test,"��ţ");
		Thread pro3=new Thread(test,"����ʦ");
		
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
	
	
	
	//�̲߳���ȫ ������Դ����ȷ
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
	
	
	
	//������Χ����ȷ
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
	
	
	
	
	
	
	//ͬ����
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
	
	
	//ͬ������
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
	
	
	//�̲߳���ȫ
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
	