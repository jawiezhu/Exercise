package RefDemo;

import java.lang.ref.WeakReference;

/**
 * ���õķ���
 * ǿ������
 * @author JawieZhu
 *
 */
public class RefDemo {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		//�ַ����ڳ����� ���� ���ܱ�����
		//String str="azhuazhuazhu";
		String str=new String("azhuazhuazhu");//���У����Ա�����
		WeakReference<String> wr=new WeakReference<String>(str);
		System.out.println("before gc:"+wr.get());
		
		str=null;
		
		System.gc();
		System.runFinalization();
		System.out.println("after gc:"+wr.get());
	}

}
