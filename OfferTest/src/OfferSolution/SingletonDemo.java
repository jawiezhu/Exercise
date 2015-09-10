package OfferSolution;


/**
 * һ����˵����һ�ֲ��㵥���������ֺ͵����־���һ�֣�
 * �����Ļ���������Ҳ���Էֿ�д�ˡ�
 * ����˵��һ�㵥����������д����
 * �������񺺣�˫��У������ö�ٺ;�̬�ڲ��ࡣ
 * @author JawieZhu
 *
 */

public class SingletonDemo {
	
}

//�������̲߳���ȫ
class Singleton{
	private static Singleton instance;
	private Singleton(){
		
	}
	
	public static Singleton getInstance(){
		if(instance==null){
			instance=new Singleton();
		}
		return instance;
	}
}

//�������̰߳�ȫ ����Ч�ʵ��£�99%���������ͬ��
class Singleton2{
	private static Singleton2 instance;
	private Singleton2(){
		
	}
	
	public static synchronized Singleton2 getInstance(){
		if(instance==null){
			instance=new Singleton2();
		}
		return instance;
	}
	
}


/**
 * ����
 * ����classloder���Ʊ����˶��̵߳�ͬ�����⣬������instance
 * ����װ��ʱ��ʵ��������Ȼ������װ�ص�ԭ���кܶ��֣�
 * �ڵ���ģʽ�д�������ǵ���getInstance������ 
 * ����Ҳ����ȷ���������ķ�ʽ�����������ľ�̬������������װ�أ�
 * ��ʱ���ʼ��instance��Ȼû�дﵽlazy loading��Ч����
 */
class Singleton3{
	private static Singleton3 instance=new Singleton3();
	private Singleton3(){
		
	}
	
	public static Singleton3 getInscence(){
		return instance;
	}
}


//���� ����
class Singleton4{
	private static Singleton4 instance=null;
	static{
		instance=new Singleton4();
	}
	
	private Singleton4(){
		
	}
	
	public static Singleton4 getInstance(){
		return instance;
	}
	
}



/**
 * ��̬�ڲ���
 * ���ַ�ʽͬ��������classloder�Ļ�������֤��ʼ��instanceʱֻ��һ���̣߳�
 * ���������ֺ͵����ַ�ʽ��ͬ���ǣ���ϸ΢�Ĳ�𣩣�
 * �����ֺ͵����ַ�ʽ��ֻҪSingleton�౻װ���ˣ�
 * ��ôinstance�ͻᱻʵ������û�дﵽlazy loadingЧ������
 * �����ַ�ʽ��Singleton�౻װ���ˣ�instance��һ������ʼ����
 * ��ΪSingletonHolder��û�б�����ʹ�ã�ֻ����ʾͨ������getInstance����ʱ��
 * �Ż���ʾװ��SingletonHolder�࣬�Ӷ�ʵ����instance��
 * ����һ�£����ʵ����instance��������Դ�����������ӳټ��أ�����һ���棬
 * �Ҳ�ϣ����Singleton�����ʱ��ʵ������
 * ��Ϊ�Ҳ���ȷ��Singleton�໹�����������ĵط�������ʹ�ôӶ������أ�
 * ��ô���ʱ��ʵ����instance��Ȼ�ǲ����ʵġ�
 * ���ʱ�����ַ�ʽ��ȵ����͵����ַ�ʽ���Եúܺ���
 */
class Singleton5{
	private static class SingletonHolder{
		private static final Singleton5 INSTANCE=new Singleton5();
	}
	
	private Singleton5(){
		
	}
	
	public static final Singleton5 getInstance(){
		return SingletonHolder.INSTANCE;
	}
	
}


/**
 * ö��
 * ���ַ�ʽ��Effective Java����Josh Bloch �ᳫ�ķ�ʽ��
 * �������ܱ�����߳�ͬ�����⣬
 * ���һ��ܷ�ֹ�����л����´����µĶ��󣬿�ν�Ǻܼ�ǿ�ı��ݰ���������
 * ������Ϊ����1.5�вż���enum���ԣ������ַ�ʽд�������˸о����裬
 * ��ʵ�ʹ����У���Ҳ���ٿ���������ôд����
 */
enum Singleton6{
	INSTANCE;
	public void whateverMethod(){
		
	}
}


/**
 * ˫��У����
 * 
 */
class Singleton7{
	private volatile static Singleton7 singleton;
	private Singleton7(){
		
	}
	
	public static Singleton7 getSingleton(){
		if(singleton==null){
			synchronized (Singleton7.class){
				if(singleton==null){
					singleton=new Singleton7();
				}
			}
		}
		return singleton;
	}
	
}


