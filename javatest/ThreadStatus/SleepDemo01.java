package ThreadStatus;

import java.text.SimpleDateFormat;
import java.util.Date;

//����ʱ
//����10���� 1���ڴ�ӡһ��~
public class SleepDemo01 {

	public static void main(String[] args) throws InterruptedException {
		// TODO Auto-generated method stub
		Date endTime=new Date(System.currentTimeMillis()+10*1000);
		long end=endTime.getTime();
		
		while(true){
			//���
			System.out.println(new SimpleDateFormat("mm:ss").format(endTime));
			//������һ��ʱ��
			endTime=new Date(endTime.getTime()-1000);
			//�ȴ�1��
			Thread.sleep(1000);
			if(end-10000>endTime.getTime()){
				break;
			}
		}
	}
	
	
	
	
	
	
	public static void test1() throws InterruptedException{
		int num=10;
		while(true){
			System.out.println(num--);
			Thread.sleep(1000);
			if(num<=0){
				break;
			}
		}
	}

}
