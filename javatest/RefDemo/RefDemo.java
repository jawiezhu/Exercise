package RefDemo;

import java.lang.ref.WeakReference;

/**
 * 引用的分类
 * 强软弱虚
 * @author JawieZhu
 *
 */
public class RefDemo {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		//字符串在常量池 共享 不能被回收
		//String str="azhuazhuazhu";
		String str=new String("azhuazhuazhu");//堆中，可以被回收
		WeakReference<String> wr=new WeakReference<String>(str);
		System.out.println("before gc:"+wr.get());
		
		str=null;
		
		System.gc();
		System.runFinalization();
		System.out.println("after gc:"+wr.get());
	}

}
