package col;

import java.util.Iterator;



public class MyArrayList3 implements java.lang.Iterable<String>{
	private String[] elem={"a","b","c","d","e","f","g"};
	private int size=elem.length;
	
	//如果不这么做，之前的方法 只能用一次，用一次之后 cursor不再是-1
	//现在这样，每次调用，就每次是新的cursor

	//匿名内部类
	public Iterator<String> iterator(){
		return new Iterator<String>(){
			
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
		};
	}
	
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		MyArrayList3 list=new MyArrayList3();
		Iterator<String> it=list.iterator();
		while(it.hasNext()){
			System.out.println(it.next());
		}
		
		it=list.iterator();
		while(it.hasNext()){
			System.out.println(it.next());
			//可以remove
		}
		
		//增强for 必须实现java.lang.Iterable接口，重写Iterator方法
		//不能删除元素remove
		for(String temp:list){
			System.out.println(temp);
			//it.remove();
		}
	}

}
