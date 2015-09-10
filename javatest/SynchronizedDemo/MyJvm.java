package SynchronizedDemo;

/**
 * ���������ķ�ʽ
 * ����ʽ
 * 		������˽�л�
 * 		����˽�еľ�̬����
 * 		�����ṩ�������Եľ�̬������ȷ���ö�����
 * ������
 * 		������˽�л�
 * 		����˽�еľ�̬����,ͬʱ�����ö���
 * 		�����ṩ�������Եľ�̬����
 * 
 * 
 * @author JawieZhu
 *
 */
public class MyJvm {
	private static MyJvm instance;
	private MyJvm(){
		
	}
	
	public static MyJvm getInstance(){
		if(null==instance){ //���Ч��
			synchronized(MyJvm.class){
			if(null==instance){
				instance =new MyJvm();
			}
				
			}
		}
		return instance;
	}
}
	
	
class MyJvm2 {
		private static MyJvm2 instance=new MyJvm2();
		private MyJvm2(){
			
		}
		
		public static MyJvm2 getInstance(){
			if(null==instance){ //���Ч��
				synchronized(MyJvm2.class){
				if(null==instance){
					instance =new MyJvm2();
				}
					
				}
			}
			return instance;
		}

}
	
	/**
	 * ����ʹ�õ�ʱ����� �ӻ��˼���ʱ��
	 * @author JawieZhu
	 *
	 */
	class MyJvm3 {
		private static class JVMholder{
			private static MyJvm3 instance=new MyJvm3();
		}
		
		private MyJvm3(){
			
		}
		
		public static MyJvm3 getInstance(){
			return JVMholder.instance;
			}
		}


	

