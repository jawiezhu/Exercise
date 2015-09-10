package SynchronizedDemo;

public class SynDemo02 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
//		Jvm jvm1=Jvm.getInstance();
//		Jvm jvm2=Jvm.getInstance();
//		//���߳��е�ַ��ͬ
//		System.out.println(jvm1);
//		System.out.println(jvm2);
		
		//����ͬ�� ���������ַ��һ��
		JvmThread thread1=new JvmThread(100);
		JvmThread thread2=new JvmThread(500);
		thread1.start();
		thread2.start();
		
		
	}

}

class JvmThread extends Thread{
	private long time;
	public JvmThread(){
		
	}
	
	public JvmThread (long time){
		this.time=time;
	}
	
	@Override
	public void run() {
		// TODO Auto-generated method stub
		super.run();
		System.out.println(Thread.currentThread().getName()+
				"--->����:"+Jvm.getInstance(time));
	}
	
} 

/**
 * �������ģʽ
 * ȷ��һ����ֻ��һ������
 * ����ʽ
 * @author JawieZhu
 *������˽�л��������ⲿֱ�Ӵ�������
 *����һ��˽�еľ�̬����
 *����һ������Ĺ����ľ�̬���� ���ʸñ������������û�ж��󣬴����ö���
 */
class Jvm{
	//����һ��˽�еľ�̬����
	private static Jvm instance =null;
	
	//������˽�л��������ⲿֱ�Ӵ�������
	private Jvm(){
		
	}
	
	
	//���Ч��
	//˫�ؼ�� double-checking
	public static Jvm getInstance(long time){
		//����Ѿ����ڶ���ķ���Ч��
		if(null==instance){
		synchronized(Jvm.class){ //û��this����Ϊ��̬��ԭ��
				if(null==instance){
					try {
						Thread.sleep(time);//�Ŵ�������ĸ���
					} catch (InterruptedException e) {
						// TODO Auto-generated catch block
						e.printStackTrace();
					}
					instance =new Jvm();
				}
					return instance;
			}
		}
		return instance;
	}
	
	
	public static Jvm getInstance3(long time){
		//Ч�ʲ���
		synchronized(Jvm.class){ //û��this����Ϊ��̬��ԭ��
		if(null==instance){
			try {
				Thread.sleep(time);//�Ŵ�������ĸ���
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
			instance =new Jvm();
		}
		return instance;
	}
	}
	
	
	public static synchronized Jvm getInstance2(long time){
		if(null==instance){
			try {
				Thread.sleep(time);//�Ŵ�������ĸ���
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
			instance =new Jvm();
		}
		return instance;
	}
	
	
	
	//����һ������Ĺ����ľ�̬���� ���ʸñ������������û�ж��󣬴����öԶ���
	
	public static Jvm getInstance1(long time){
		if(null==instance){
			try {
				Thread.sleep(time);//�Ŵ�������ĸ���
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
			instance =new Jvm();
		}
		return instance;
	}
}
