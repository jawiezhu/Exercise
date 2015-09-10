package ThreadStatus;

/**
 * join 合并线程
 * @author JawieZhu
 *
 */
public class JoinDemo01 extends Thread {

	public static void main(String[] args) throws InterruptedException {
		// TODO Auto-generated method stub
		
		JoinDemo01 demo=new JoinDemo01();
		Thread t=new Thread(demo);//新生
		t.start();//就绪
		
		
		for(int i=0;i<1000;i++){
			if(50==i){
				t.join();//main阻塞 必须等待t执行完，才能继续执行
			}
			System.out.println("main...."+i);
		}
	}
	
	public void run(){
		for(int i=0;i<100;i++){
			System.out.println("\tjoin..."+i);
		}
	}
}
