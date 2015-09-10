package SynchronizedDemo;

public class SynDemo02 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
//		Jvm jvm1=Jvm.getInstance();
//		Jvm jvm2=Jvm.getInstance();
//		//单线程中地址相同
//		System.out.println(jvm1);
//		System.out.println(jvm2);
		
		//不加同步 两个对象地址不一样
		JvmThread thread1=new JvmThread(100);
		JvmThread thread2=new JvmThread(500);
		thread1.start();
		thread2.start();
		
		
	}

}

class JvmThread extends Thread{
	private long time;
	public JvmThread(){
		
	}
	
	public JvmThread (long time){
		this.time=time;
	}
	
	@Override
	public void run() {
		// TODO Auto-generated method stub
		super.run();
		System.out.println(Thread.currentThread().getName()+
				"--->创建:"+Jvm.getInstance(time));
	}
	
} 

/**
 * 单例设计模式
 * 确保一个类只有一个对象
 * 懒汉式
 * @author JawieZhu
 *构造器私有化、避免外部直接创建对象
 *声明一个私有的静态变量
 *创建一个对外的公共的静态方法 访问该变量，如果变量没有对象，创建该对象
 */
class Jvm{
	//声明一个私有的静态变量
	private static Jvm instance =null;
	
	//构造器私有化、避免外部直接创建对象
	private Jvm(){
		
	}
	
	
	//提高效率
	//双重检查 double-checking
	public static Jvm getInstance(long time){
		//提高已经存在对象的访问效率
		if(null==instance){
		synchronized(Jvm.class){ //没有this，因为静态的原因
				if(null==instance){
					try {
						Thread.sleep(time);//放大发生错误的概率
					} catch (InterruptedException e) {
						// TODO Auto-generated catch block
						e.printStackTrace();
					}
					instance =new Jvm();
				}
					return instance;
			}
		}
		return instance;
	}
	
	
	public static Jvm getInstance3(long time){
		//效率不高
		synchronized(Jvm.class){ //没有this，因为静态的原因
		if(null==instance){
			try {
				Thread.sleep(time);//放大发生错误的概率
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
			instance =new Jvm();
		}
		return instance;
	}
	}
	
	
	public static synchronized Jvm getInstance2(long time){
		if(null==instance){
			try {
				Thread.sleep(time);//放大发生错误的概率
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
			instance =new Jvm();
		}
		return instance;
	}
	
	
	
	//创建一个对外的公共的静态方法 访问该变量，如果变量没有对象，创建该对对象
	
	public static Jvm getInstance1(long time){
		if(null==instance){
			try {
				Thread.sleep(time);//放大发生错误的概率
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
			instance =new Jvm();
		}
		return instance;
	}
}
