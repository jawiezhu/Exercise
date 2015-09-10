package ThreadStatus;

/**
 * yield 暂停自己的线程，让出cpu给其他线程
 * @author JawieZhu
 *
 */
public class YieldDemo01 extends Thread {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		YieldDemo01 demo=new YieldDemo01();
		Thread t=new Thread(demo);//新生
		t.start();//就绪
		
		
		for(int i=0;i<1000;i++){
			if(i%20==0){
				//暂停本线程
				Thread.yield(); //写在哪里 暂停谁
			}
			System.out.println("main...."+i);
		}
	}
	
	
	public void run(){
		for(int i=0;i<100;i++){
			System.out.println("\tyield..."+i);
		}
	}

}
