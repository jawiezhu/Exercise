package ThreadCreate;

public class ProgrammerApp {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		//������ʵ��ɫ
		Programmer pro=new Programmer();
		
		//���������ɫ+��ʵ��ɫ����
		Thread proxy=new Thread(pro);
		
		//����.start()�����߳�
		proxy.start();
		
		for(int i=0;i<20;i++)
		{
			System.out.println("\tbyebyeworld~~~");
		}
	}

}
