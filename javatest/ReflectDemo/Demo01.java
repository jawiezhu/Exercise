package ReflectDemo;

//��ȡ�ṹ��Ϣclass����Դͷ��
public class Demo01 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		String str="abc";
		//����.getClass()
		
		Class<?> clz=str.getClass();
		
		clz=String.class;
		
		try {
			clz=Class.forName("java.lang.String");
		} catch (ClassNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
	}

}
