package Generic;

/*
 * ��ȡֵ ��Ҫǿ������ת��
 * ����ת������ java.lang.ClassCastException
 * ����Ҫ�����ֶ����ͼ�� instanceof
 * 
 * �����Ҫʹ�� ����
 */
public class App {
	public static void main(String[] args){
		
		//
		Object obj=80;
		int score= (Integer) obj;
		//int score=(int)obj; //jdk1.7 ֮�����
		System.out.println(score);
		
		
		//�������� int->Integer->Object
		Student stu=new Student(80,90);
		stu.getJavese();
		int javaseScore=(Integer)stu.getJavese();
		String oracleScore=null;
		if(stu.getOracle() instanceof String){
			oracleScore=(String)stu.getOracle();
		}
		
		
	}
}
