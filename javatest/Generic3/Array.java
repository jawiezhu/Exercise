package Generic3;

public class Array {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		MyArrayList<String> strList=new MyArrayList<String>();
		strList.add(0, "aaa");
		String elem=strList.getElem(0);
		
	}
	


}


class MyArrayList<E>{
	Object[] cap=new Object[10]; //用object接受
	
	//参考 ArrayList源码
	//E[] cap=new E[10]  ERROR
	public void add(int index,E e){
		cap[index]=e;
	}
	
	@SuppressWarnings("unchecked")
	public E[] getAll(){
		return (E[]) cap;
	}
	
	@SuppressWarnings("unchecked")
	public E getElem(int index){
		return (E) cap[index];
	}
}