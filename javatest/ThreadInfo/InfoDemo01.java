package ThreadInfo;

public class InfoDemo01 {

	public static void main(String[] args) throws InterruptedException {
		// TODO Auto-generated method stub
		MyThread it=new MyThread();
		Thread proxy=new Thread(it,"ITT");
		//proxy.setName("test");
		System.out.println(proxy.getName());
		System.out.println(Thread.currentThread().getName());//main线程
		proxy.start();
		
		System.out.println("启动后的状态："+proxy.isAlive());
		
		Thread.sleep(10);
		it.stop();
		Thread.sleep(100);
		System.out.println("停止后的状态："+proxy.isAlive());
		
	}

}
