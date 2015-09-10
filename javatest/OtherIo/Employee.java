package OtherIo;

import java.io.Serializable;
/**
 * �սӿ� ��ʾ �������л�
 * @author JawieZhu
 *
 */
public class Employee implements Serializable {
	//����Ҫ���л��� ���� transient
	private  transient String name;
	private double salary;
	
	public Employee(String name, double salary) {
		super();
		this.name = name;
		this.salary = salary;
	}
	
	public Employee() {
		super();
		// TODO Auto-generated constructor stub
	}
	
	public String getName() {
		return name;
	}
	
	public void setName(String name) {
		this.name = name;
	}
	public double getSalary() {
		return salary;
	}
	public void setSalary(double salary) {
		this.salary = salary;
	}
	
	
}
