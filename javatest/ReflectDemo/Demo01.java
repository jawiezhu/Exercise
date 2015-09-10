package ReflectDemo;

//获取结构信息class对象（源头）
public class Demo01 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		String str="abc";
		//对象.getClass()
		
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
