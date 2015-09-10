package TestCollection;

public class Student {
	private int id;
	private String name;
	
	@Override
	public int hashCode() {
		final int prime = 31; //һ��ȡ����
		int result = 1;
		result = prime * result + id;
		return result;
	}
	@Override
	public boolean equals(Object obj) {
		if (this == obj)
			return true;
		if (obj == null)
			return false;
		if (getClass() != obj.getClass())
			return false;
		Student other = (Student) obj;
		if (id != other.id)
			return false;
		return true;
	}
	
	
}
