package col;


public class MyArrayList {
	private String[] elem={"a","b","c","d","e","f","g"};
	private int size=elem.length;
	
	private int cursor=-1;
	
	public boolean hasNext(){
		return cursor+1<size;
	}
	
	public String next(){
		cursor++;
		return elem[cursor];
	}
	
	public void remove(){
		
	}
	
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

}
