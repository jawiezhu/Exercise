package SetDemo;

public class Person {
	private final String name;
	private final int handsome;
	public String getName() {
		return name;
	}
//	public void setName(String name) {
//		this.name = name;
//	}
	public int getHandsome() {
		return handsome;
	}
//	public void setHandsome(int handsome) {
//		this.handsome = handsome;
//	}
	public Person(String name, int handsome) {
		super();
		this.name = name;
		this.handsome = handsome;
	}
	public Person() {
		super();
		name=null;
		handsome=0;
		// TODO Auto-generated constructor stub
	}
	@Override
	public String toString() {
		return "name:"+this.name+" index:"+this.handsome+"\n";
	}
	
	
	
	
}
