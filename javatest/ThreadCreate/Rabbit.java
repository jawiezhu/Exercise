package ThreadCreate;
/**
 * 模拟龟兔赛跑
 * @author JawieZhu
 *创建多线程
 *继承 Thread类 重写run(线程体) 一切从run开始
 *使用线程：创建子类对象 调用对象.start()方法
 *
 */
public class Rabbit extends Thread{
	
	
	@Override
	public void run() {
		// 线程体
		for(int i=0;i<100;i++){
			System.out.println("\t兔子跑了"+i+"步");
		}
	}
}

class Tortoise extends Thread{
	@Override
	public void run() {
		// 线程体
		for(int i=0;i<100;i++){
			System.out.println("乌龟跑了"+i+"步");
		}
	}
}
