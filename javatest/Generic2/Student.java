package Generic2;

/**
 * 
 * @author JawieZhu
 *
 * @param <T>
 */
public class Student<T1,T2> {
	private T1 javaScore;
	private T2 oracleScore;
	
	public T1 getJavaScore() {
		return javaScore;
	}
	public void setJavaScore(T1 javaScore) {
		this.javaScore = javaScore;
	}
	public T2 getOracleScore() {
		return oracleScore;
	}
	public void setOracleScore(T2 oracleScore) {
		this.oracleScore = oracleScore;
	}
	
	
	public static void main(String[] args){
		//使用时指定类型,只能为引用类型
		Student<String,Integer>stu=new Student<String,Integer>();
		stu.setJavaScore("good");
		stu.setOracleScore(111);
		int it=stu.getOracleScore();
	}
	
	
}
