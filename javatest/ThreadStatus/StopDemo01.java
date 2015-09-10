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
	//线程类中定义线程体使用的标识
	private boolean flag=true;
		
	@Override
	public void run() {
		// 线程体使用该标识
		while(flag){
			System.out.println("Study thread....");
		}
	}
	
	//对外提供方法，改变标识
	public void stop(){
		this.flag=false;
	}
	
}