package ThreadStatus;

/**
 * join �ϲ��߳�
 * @author JawieZhu
 *
 */
public class JoinDemo01 extends Thread {

	public static void main(String[] args) throws InterruptedException {
		// TODO Auto-generated method stub
		
		JoinDemo01 demo=new JoinDemo01();
		Thread t=new Thread(demo);//����
		t.start();//����
		
		
		for(int i=0;i<1000;i++){
			if(50==i){
				t.join();//main���� ����ȴ�tִ���꣬���ܼ���ִ��
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
