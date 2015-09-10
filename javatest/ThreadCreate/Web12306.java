package ThreadCreate;

public class Web12306 implements Runnable{
	private int num=50;

	@Override
	public void run() {
		// TODO Auto-generated method stub
		while(true){
			if(num<=0){
				break;
			}
			System.out.println(Thread.currentThread().getName()+"Get!"+num--);
		}
	}
	
	
	public static void main(String[] args){
		Web12306 test=new Web12306();
		Thread proxy=new Thread(test,"路人甲");
		Thread pro2=new Thread(test,"黄牛");
		Thread pro3=new Thread(test,"工程师");
		
		proxy.start();
		pro2.start();
		pro3.start(); 
		
		
	}
	
}
