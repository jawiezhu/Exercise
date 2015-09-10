package SynchronizedDemo;

/**
 * 单例创建的方式
 * 懒汉式
 * 		构造器私有化
 * 		声明私有的静态变量
 * 		对外提供访问属性的静态方法，确保该对象不在
 * 饿汉试
 * 		构造器私有化
 * 		声明私有的静态变量,同时创建该对象
 * 		对外提供访问属性的静态方法
 * 
 * 
 * @author JawieZhu
 *
 */
public class MyJvm {
	private static MyJvm instance;
	private MyJvm(){
		
	}
	
	public static MyJvm getInstance(){
		if(null==instance){ //提高效率
			synchronized(MyJvm.class){
			if(null==instance){
				instance =new MyJvm();
			}
				
			}
		}
		return instance;
	}
}
	
	
class MyJvm2 {
		private static MyJvm2 instance=new MyJvm2();
		private MyJvm2(){
			
		}
		
		public static MyJvm2 getInstance(){
			if(null==instance){ //提高效率
				synchronized(MyJvm2.class){
				if(null==instance){
					instance =new MyJvm2();
				}
					
				}
			}
			return instance;
		}

}
	
	/**
	 * 类在使用的时候加载 延缓了加载时间
	 * @author JawieZhu
	 *
	 */
	class MyJvm3 {
		private static class JVMholder{
			private static MyJvm3 instance=new MyJvm3();
		}
		
		private MyJvm3(){
			
		}
		
		public static MyJvm3 getInstance(){
			return JVMholder.instance;
			}
		}


	

