package SchedualDemo;

import java.util.Date;
import java.util.Timer;
import java.util.TimerTask;

/**
 * QUARTZ 第三方jar包 任务调度
 * @author JawieZhu
 *
 */
public class TimeDemo01 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Timer timer=new Timer();
		timer.schedule(new TimerTask(){

			@Override
			public void run() {
				// TODO Auto-generated method stub
				System.out.println("so easy~");
			}
			
		},new Date(System.currentTimeMillis()+1000),200);
	}

}
