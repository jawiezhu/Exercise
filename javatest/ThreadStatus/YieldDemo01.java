package ThreadStatus;

/**
 * yield ��ͣ�Լ����̣߳��ó�cpu�������߳�
 * @author JawieZhu
 *
 */
public class YieldDemo01 extends Thread {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		YieldDemo01 demo=new YieldDemo01();
		Thread t=new Thread(demo);//����
		t.start();//����
		
		
		for(int i=0;i<1000;i++){
			if(i%20==0){
				//��ͣ���߳�
				Thread.yield(); //д������ ��ͣ˭
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
