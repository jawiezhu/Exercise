package SetDemo;

public class Worker implements Comparable<Worker> {
	private String type;
	private double salary;
	public String getType() {
		return type;
	}
	public void setType(String type) {
		this.type = type;
	}
	public double getSalary() {
		return salary;
	}
	public void setSalary(double salary) {
		this.salary = salary;
	}
	public Worker(String type, double salary) {
		super();
		this.type = type;
		this.salary = salary;
	}
	public Worker() {
		super();
		// TODO Auto-generated constructor stub
	}
	
	@Override
	public int compareTo(Worker o) {
		// TODO Auto-generated method stub
		
		return -(this.salary>o.salary?1:(this.salary==o.salary?0:-1));
	}
	@Override
	public String toString() {
		return "1."+this.type+"---"+this.salary+"\n";
	}
	
	
}
