package ThreadStatus;

/**
 * 模拟网络延时
 * @author JawieZhu
 *
 */
public class SleepDemo02 {

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

class Web12306 implements Runnable{
	private int num=50;

	@Override
	public void run() {
		// TODO Auto-generated method stub
		//资源冲突，对用一份资源 并发，保证安全
		while(true){
			if(num<=0){
				break;
			}
			try {
				Thread.sleep(1000);
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
			System.out.println(Thread.currentThread().getName()+"Get!"+num--);
		}
	}
}


