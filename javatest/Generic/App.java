package Generic;

/*
 * 获取值 需要强制类型转换
 * 可能转换错误 java.lang.ClassCastException
 * 则需要进行手动类型检查 instanceof
 * 
 * 因此需要使用 泛型
 */
public class App {
	public static void main(String[] args){
		
		//
		Object obj=80;
		int score= (Integer) obj;
		//int score=(int)obj; //jdk1.7 之后可以
		System.out.println(score);
		
		
		//存入整数 int->Integer->Object
		Student stu=new Student(80,90);
		stu.getJavese();
		int javaseScore=(Integer)stu.getJavese();
		String oracleScore=null;
		if(stu.getOracle() instanceof String){
			oracleScore=(String)stu.getOracle();
		}
		
		
	}
}
