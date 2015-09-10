package Map;

import java.util.ArrayList;
import java.util.List;

public class ClassRoom {
	private String number;
	private List<Student> stus;//所有学生
	private double total;

	public ClassRoom() {
		//super();
		stus=new ArrayList<Student>();
		
		// TODO Auto-generated constructor stub
	}
	
	public ClassRoom(String number) {
		this();
		this.number = number;
	}
	public String getNumber() {
		return number;
	}
	public void setNumber(String number) {
		this.number = number;
	}
	public List<Student> getStus() {
		return stus;
	}
	public void setStus(List<Student> stus) {
		this.stus = stus;
	}
	public double getTotal() {
		return total;
	}
	public void setTotal(double total) {
		this.total = total;
	}
	
	
	
}
