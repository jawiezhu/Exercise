package QueueDemo;

import java.util.ArrayDeque;
import java.util.Queue;

/*
 * 模拟银行存款业务
 */
public class Demo01 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Queue<Request> que=new ArrayDeque<Request>();
		//模拟排队情况
		for(int i=0;i<10;i++){
			final int num=i;
			que.offer(new Request(){

				@Override
				public void deposit() {
					// TODO Auto-generated method stub
					System.out.println("No:"+num+" ....."+(int)(Math.random()*10000));
				}
				
			});
			
		}
		
		dealWith(que);
	}
	//处理业务
	public static void dealWith(Queue<Request> que){
		Request req=null;
		while(null!=(req=que.poll())){
			req.deposit();
		}
	}
	

}

interface Request{
	void deposit();
	
}