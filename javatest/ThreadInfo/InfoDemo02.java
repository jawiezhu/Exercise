package ThreadInfo;

public class InfoDemo02 {

	public static void main(String[] args) throws InterruptedException {
		// TODO Auto-generated method stub
		MyThread it1=new MyThread();
		Thread proxy1=new Thread(it1,"ITT");
		
		MyThread it2=new MyThread();
		Thread proxy2=new Thread(it2,"ITT222");
		proxy1.setPriority(Thread.MIN_PRIORITY);
		proxy2.setPriority(Thread.MAX_PRIORITY);
		proxy1.start();
		
		proxy2.start();
		Thread.sleep(20);
		it1.stop();
		it2.stop();
		
	}

}
