package ProductAndConsumeDemo;

/**
 * һ������ ��ͬ��Դ
 * 
 * �źŵƷ�
 * @author JawieZhu
 *wait() �ȴ����ͷ��� 
 *sleep() ���ͷ���
 *
 *notify() ����
 */
public class Movie {

	private String pic;
	
	//flag-T �����������������ߵȴ���������ɺ� ֪ͨ����
	//flag-F ���������ѣ������ߵȴ���������ɺ� ֪ͨ����
	private boolean flag=true;
	
	public synchronized void play(String pic){
		if(!flag){//�����ߵȴ�
			try {
				this.wait();
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
	}
		//��ʼ����
		try {
			Thread.sleep(500);
		} catch (InterruptedException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		System.out.println("������"+pic);
		//�������
		this.pic=pic;
		
		//֪ͨ����
		this.notify();
		
		//������ͣ��
		this.flag=false;
	}
	
	public synchronized void watch(){
		if(flag){ //�����ߵȴ�
			try {
				this.wait();
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
		//��ʼ����
		try {
			Thread.sleep(200);
		} catch (InterruptedException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		
		//�������
		System.out.println("������"+pic);
		
		//֪ͨ����
		this.notifyAll();
		
		//����ֹͣ
		this.flag=true;
	}
	
	
	
	
	
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

}
