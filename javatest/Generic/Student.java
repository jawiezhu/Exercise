package Generic;

/*
 * Object���Խ����������ͣ���Ϊ �� ��̬
 */
public class Student {
	private Object javese;
	private Object oracle;
	
	
	
	
	public Student() {
		super();
	}
	
	public Student(Object javese, Object oracle) {
		super();
		this.javese = javese;
		this.oracle = oracle;
	}
	public Object getJavese() {
		return javese;
	}
	public void setJavese(Object javese) {
		this.javese = javese;
	}
	public Object getOracle() {
		return oracle;
	}
	public void setOracle(Object oracle) {
		this.oracle = oracle;
	}
	
	
}
