package ThreadStatus;

/**
 * ģ��������ʱ
 * @author JawieZhu
 *
 */
public class SleepDemo02 {

	public static void main(String[] args){
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
	private int num=50;

	@Override
	public void run() {
		// TODO Auto-generated method stub
		//��Դ��ͻ������һ����Դ ��������֤��ȫ
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


