package ThreadInfo;

public class InfoDemo01 {

	public static void main(String[] args) throws InterruptedException {
		// TODO Auto-generated method stub
		MyThread it=new MyThread();
		Thread proxy=new Thread(it,"ITT");
		//proxy.setName("test");
		System.out.println(proxy.getName());
		System.out.println(Thread.currentThread().getName());//main�߳�
		proxy.start();
		
		System.out.println("�������״̬��"+proxy.isAlive());
		
		Thread.sleep(10);
		it.stop();
		Thread.sleep(100);
		System.out.println("ֹͣ���״̬��"+proxy.isAlive());
		
	}

}
