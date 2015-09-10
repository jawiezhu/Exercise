package OfferSolution;


/**
 * 一般来说，第一种不算单例，第四种和第三种就是一种，
 * 如果算的话，第五种也可以分开写了。
 * 所以说，一般单例都是五种写法。
 * 懒汉，恶汉，双重校验锁，枚举和静态内部类。
 * @author JawieZhu
 *
 */

public class SingletonDemo {
	
}

//懒汉、线程不安全
class Singleton{
	private static Singleton instance;
	private Singleton(){
		
	}
	
	public static Singleton getInstance(){
		if(instance==null){
			instance=new Singleton();
		}
		return instance;
	}
}

//懒汉、线程安全 但是效率底下，99%的情况不用同步
class Singleton2{
	private static Singleton2 instance;
	private Singleton2(){
		
	}
	
	public static synchronized Singleton2 getInstance(){
		if(instance==null){
			instance=new Singleton2();
		}
		return instance;
	}
	
}


/**
 * 饿汉
 * 基于classloder机制避免了多线程的同步问题，不过，instance
 * 在类装载时就实例化，虽然导致类装载的原因有很多种，
 * 在单例模式中大多数都是调用getInstance方法， 
 * 但是也不能确定有其他的方式（或者其他的静态方法）导致类装载，
 * 这时候初始化instance显然没有达到lazy loading的效果。
 */
class Singleton3{
	private static Singleton3 instance=new Singleton3();
	private Singleton3(){
		
	}
	
	public static Singleton3 getInscence(){
		return instance;
	}
}


//饿汉 变种
class Singleton4{
	private static Singleton4 instance=null;
	static{
		instance=new Singleton4();
	}
	
	private Singleton4(){
		
	}
	
	public static Singleton4 getInstance(){
		return instance;
	}
	
}



/**
 * 静态内部类
 * 这种方式同样利用了classloder的机制来保证初始化instance时只有一个线程，
 * 它跟第三种和第四种方式不同的是（很细微的差别）：
 * 第三种和第四种方式是只要Singleton类被装载了，
 * 那么instance就会被实例化（没有达到lazy loading效果），
 * 而这种方式是Singleton类被装载了，instance不一定被初始化。
 * 因为SingletonHolder类没有被主动使用，只有显示通过调用getInstance方法时，
 * 才会显示装载SingletonHolder类，从而实例化instance。
 * 想象一下，如果实例化instance很消耗资源，我想让他延迟加载，另外一方面，
 * 我不希望在Singleton类加载时就实例化，
 * 因为我不能确保Singleton类还可能在其他的地方被主动使用从而被加载，
 * 那么这个时候实例化instance显然是不合适的。
 * 这个时候，这种方式相比第三和第四种方式就显得很合理。
 */
class Singleton5{
	private static class SingletonHolder{
		private static final Singleton5 INSTANCE=new Singleton5();
	}
	
	private Singleton5(){
		
	}
	
	public static final Singleton5 getInstance(){
		return SingletonHolder.INSTANCE;
	}
	
}


/**
 * 枚举
 * 这种方式是Effective Java作者Josh Bloch 提倡的方式，
 * 它不仅能避免多线程同步问题，
 * 而且还能防止反序列化重新创建新的对象，可谓是很坚强的壁垒啊，不过，
 * 个人认为由于1.5中才加入enum特性，用这种方式写不免让人感觉生疏，
 * 在实际工作中，我也很少看见有人这么写过。
 */
enum Singleton6{
	INSTANCE;
	public void whateverMethod(){
		
	}
}


/**
 * 双重校验锁
 * 
 */
class Singleton7{
	private volatile static Singleton7 singleton;
	private Singleton7(){
		
	}
	
	public static Singleton7 getSingleton(){
		if(singleton==null){
			synchronized (Singleton7.class){
				if(singleton==null){
					singleton=new Singleton7();
				}
			}
		}
		return singleton;
	}
	
}


