package ThreadCreate;

public class RabbitApp {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		//�����������
		Rabbit rab=new Rabbit();
		Tortoise tor=new Tortoise();
		
		
		
		//����start���� ��������߳�����  
		//��δ������ֻ��վ���������ϣ���cpu������ʼ����
		rab.start(); //��Ҫ����run�������ɸ����start����run����
		tor.start();
		
		//����run�������� �ǰ�˳��ִ��
		
		
		//main+gc+�쳣+rab+torһ������߳�
		
		for(int i=0;i<100;i++){
			System.out.println("\t\tmain:"+i);
		}
	}

}
