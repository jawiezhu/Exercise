package ThreadCreate;

public class RabbitApp {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		//创建子类对象
		Rabbit rab=new Rabbit();
		Tortoise tor=new Tortoise();
		
		
		
		//调用start方法 将其加入线程组中  
		//并未启动，只是站在起跑线上，由cpu决定开始启动
		rab.start(); //不要调用run方法，由父类的start调用run方法
		tor.start();
		
		//调用run方法，则 是按顺序执行
		
		
		//main+gc+异常+rab+tor一共五个线程
		
		for(int i=0;i<100;i++){
			System.out.println("\t\tmain:"+i);
		}
	}

}
