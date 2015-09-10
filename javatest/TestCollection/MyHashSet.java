package TestCollection;

import java.util.HashMap;

public class MyHashSet {
	HashMap map;
	private static final Object PRESENT=new Object();
	int size;
	
	public MyHashSet(){
		map=new HashMap();
	}
	
	public int size(){
		return	map.size();
	}
	
	public void add(Object obj){
		map.put(obj, PRESENT); //set的不可重复性 键对象的不可重复
		size++; //需判断是否重复
	}
	
	public void remove(Object obj){
		map.remove(obj);
	}
	
	
	public static void main(String[] args){
		MyHashSet s=new MyHashSet();
		s.add("aaa");
		s.remove("aaa");
		System.out.println(s.size());
		
	}
}
