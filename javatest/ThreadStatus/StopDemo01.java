package ThreadStatus;

public class StopDemo01 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Study s=new Study();
		new Thread(s).start();
		
		for(int i=0;i<100;i++){
			if(i==50){
				s.stop();
			}
			System.out.println("qqqq------->"+i);
		}
	}

}


class Study implements Runnable{
	//�߳����ж����߳���ʹ�õı�ʶ
	private boolean flag=true;
		
	@Override
	public void run() {
		// �߳���ʹ�øñ�ʶ
		while(flag){
			System.out.println("Study thread....");
		}
	}
	
	//�����ṩ�������ı��ʶ
	public void stop(){
		this.flag=false;
	}
	
}