package col;

import java.util.Iterator;

/*
 * 简化迭代器  加入接口提供方法
 */
public class MyArrayList2 {
	private String[] elem={"a","b","c","d","e","f","g"};
	private int size=elem.length;
	
	//如果不这么做，之前的方法 只能用一次，用一次之后 cursor不再是-1
	//现在这样，每次调用，就每次是新的cursor
	private class MyIt implements Iterator<String>{
	
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
	}
	
	public Iterator<String> iterator(){
		return new MyIt();
	}
	
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		MyArrayList2 list=new MyArrayList2();
		Iterator<String> it=list.iterator();
		while(it.hasNext()){
			System.out.println(it.next());
		}
		
		it=list.iterator();
		while(it.hasNext()){
			System.out.println(it.next());
		}
	}
}
