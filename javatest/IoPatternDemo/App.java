package IoPatternDemo;

/**
 * ������֮��Ĺ�ϵ
 * 1 ���� �β�|�ֲ�����
 * 2 ���� ����
 * 		 �ۺ� ���� �����벿�� ��һ�µ���������
 * 		 ��� ���� �����벿�� һ�µ���������
 * 3 �̳� ������Ĺ�ϵ
 * 4 ʵ�� �ӿ���ʵ����Ĺ�ϵ
 * 
 * װ�����ģʽ
 * @author JawieZhu
 *
 */
public class App {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Voice v=new Voice();
		v.say();
		Amplifier am=new Amplifier(v);
		am.say();
	}

}
