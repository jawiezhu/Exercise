package ThreadCreate;
/**
 * ģ���������
 * @author JawieZhu
 *�������߳�
 *�̳� Thread�� ��дrun(�߳���) һ�д�run��ʼ
 *ʹ���̣߳������������ ���ö���.start()����
 *
 */
public class Rabbit extends Thread{
	
	
	@Override
	public void run() {
		// �߳���
		for(int i=0;i<100;i++){
			System.out.println("\t��������"+i+"��");
		}
	}
}

class Tortoise extends Thread{
	@Override
	public void run() {
		// �߳���
		for(int i=0;i<100;i++){
			System.out.println("�ڹ�����"+i+"��");
		}
	}
}
