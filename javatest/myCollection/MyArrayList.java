package myCollection;

/**
 * 
 * @author JawieZhu
 *
 */

public class MyArrayList {
	
	private Object[] value;
	private int size;
	
	
	public int getSize() {
		return size;
	}

	public void setSize(int size) {
		this.size = size;
	}

	public MyArrayList(){
		//value=new Object[16];
		this(16);
		
	}
	
	public MyArrayList(int size){
		if(size<0){
			try{
				throw new Exception();
			}catch(Exception e){
				e.printStackTrace();
			}
		}
		value=new Object[size];
	}
	
	public void add(Object obj){
		//value[0]=obj;
		
		value[size]=obj;
		size++;
		
		if(size >= value.length){
			int newCapacity=value.length*2;
			Object[] newList=new Object[newCapacity];
			
			for(int i=0;i<value.length;i++){
				newList[i]=value[i];
			}
			value=newList;
		}
	}
	
	
	public Object get(int index){
		if(index<0||index>size-1){
			try{
				throw new Exception();
			}catch(Exception e){
				e.printStackTrace();
			}
		}
		
		return value[index];
	}
	
	public boolean isEmpty(){
		return size==0;
	}
	
	public int indexOf(Object obj){
		if(obj==null){
			return -1;
		}else{
			for(int i=0;i<value.length;i++){
				if(obj==value[i])
					return i;
			}
			
			return -1;
		}
	}
	
	public Object set(int index,Object object){
		rangeCheck(index);
		Object old=value[index];
		value[index]=object;
		return old;
	}
	
	public void rangeCheck(int index){
		if(index<0||index>size-1){
			try{
				throw new Exception();
			}catch(Exception e){
				e.printStackTrace();
			}
		}
	}
	
	public static void main(String[] args){
		MyArrayList list=new MyArrayList(2);
		list.add("addd");
		list.add(new Human("azhu"));
		list.add("bbb");
		
		Human h=(Human)list.get(1);
		System.out.println(h.getName());
		System.out.println(list.getSize());
		//System.out.println(list.get(2));
	}
	
	
}
