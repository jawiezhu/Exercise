package TestCollection;

import java.util.ArrayList;
import java.util.List;



public class MyArrayList {
	
	private Object[] elementData;
	
	private int size;
	
	public int size(){
		return size;
	}
	
	public MyArrayList(){
		this(10);
	}
	
	public boolean isEmpty(){
		return size==0;
		
	}
	
	public Object get(int index){
		RangeCheck(index);
		return elementData[index];
	}
	
	private void RangeCheck(int index){
		if(index>=size){
			try {
				throw new Exception();
			} catch (Exception e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
	}
	
//	//MySet
//	public void set(int index,Object obj){
//		RangeCheck(index);
//		elementData[index]=obj;
//	}
//	
	
	public Object set(int index,Object obj){
		RangeCheck(index);
		Object oldValue=elementData[index];
		elementData[index]=obj;
		return oldValue;
		
	}
	
	public void remove(int index){
		RangeCheck(index);
//		//MyRemove	
//		for(int i=1;i<size-index;i++)
//		{
//			elementData[index+i-1]=elementData[index+i];
//		}
//		size--;
		
		int numMoved=size-index-1;
		if(numMoved>0)
			System.arraycopy(elementData, index+1, elementData, index, numMoved);
		
		elementData[--size]=null;
	}
	
	public void remove(Object obj){
		for(int i=0;i<size;i++)
		{
			if(this.get(i).equals(obj)){
				remove(i);
			}
		}
	}
	
	public MyArrayList(int initialCapacity){
		if(initialCapacity<0){
			try{
				throw new Exception();
			}catch(Exception e){
				e.printStackTrace();
			}
		}
		elementData=new Object[initialCapacity];
	}
	
	
	public void add(Object obj){
		/*
		 * À©ÈÝ
		 */
		ensureCapacity();
		elementData[size]=obj;
		size++;
	}
	
	private void ensureCapacity(){
		if(size==elementData.length){
			Object[] newArray=new Object[size*2+1];
			System.arraycopy(elementData, 0, newArray, 0, elementData.length);
//			for(int i=0;i<elementData.length;i++)
//			{
//				newArray[i]=elementData[i];
//			}
			elementData=newArray;
		}
	}
	
	public void add(int index,Object obj){
		RangeCheck(index);
		ensureCapacity();
		System.arraycopy(elementData, index, elementData, index+1, size-index);
		elementData[index]=obj;
		size++;
	}
	
	public static void main(String[] args){
		MyArrayList list=new MyArrayList(3);
		List list2=new ArrayList(5);
		
		list.add("0333");
		list.add("1444");
		list.add("2aaaaaa");
		list.add("34444");
		list.add("4aaa");
		list.add("5444");
		list.add("6aaa");
		list.set(4, new String("huihui"));
		list.add(new String("azhu"));
		
		
		System.out.println(list.size());
		System.out.println(list.get(1));
		list.remove(1);
		System.out.println(list.size());
		System.out.println(list.get(1));
		list.remove(new String("azhu"));
		list.remove(new String("huihui"));
		
		
		for(int i=0;i<list.size();i++)
		{
			System.out.println(list.get(i));
		}
		//System.out.println(list.get(2));
		//System.out.println(list.size());
		//System.out.println(list.get(6));
	}
	
}
