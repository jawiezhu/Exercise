package ThreadCreate;
/**
 * ʹ��Runnable�����߳�
 * 1. ��ʵ�� runnable�ӿ�+ ��д run����  ��ʵ��ɫ��
 * 2. �������߳� ʹ�þ�̬����
 *    ������ʵ��ɫ
 *    ���������ɫ+��ʵ��ɫ����
 *    ����.start����
 * @author JawieZhu
 *
 */
public class Programmer implements Runnable{

	@Override
	public void run() {
		// TODO Auto-generated method stub
		for(int i=0;i<20;i++){
			System.out.println("helloworld��");
		}
	}

}
