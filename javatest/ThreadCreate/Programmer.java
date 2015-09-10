package ThreadCreate;
/**
 * 使用Runnable创建线程
 * 1. 类实现 runnable接口+ 重写 run方法  真实角色类
 * 2. 启动多线程 使用静态代理
 *    创建真实角色
 *    创建代理角色+真实角色引用
 *    调用.start方法
 * @author JawieZhu
 *
 */
public class Programmer implements Runnable{

	@Override
	public void run() {
		// TODO Auto-generated method stub
		for(int i=0;i<20;i++){
			System.out.println("helloworld！");
		}
	}

}
