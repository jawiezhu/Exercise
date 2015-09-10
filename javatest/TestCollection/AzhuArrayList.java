package TestCollection;

public class AzhuArrayList {
	private Object[] elementData;
	private int size;
	
	public int getSize(){
		return size;
		
	}
	
	public AzhuArrayList(){
		this(16);
	}

	public AzhuArrayList(int initialCapacity) {
		// TODO Auto-generated constructor stub
		if(initialCapacity<0)
		{
			try{
				throw new Exception();
			}catch(Exception e){
				e.printStackTrace();
			}
		}
		elementData=new Object[initialCapacity];
	}
	
	public boolean isEmpty(){
		return size==0;
	}
	
	public Object get(int index){
		rangeCheck(index);
		return elementData[index];
	}

	private void rangeCheck(int index) {
		if(index>=size){
			try{
				throw new Exception();
			}catch(Exception e){
				e.printStackTrace();
			}
		}
	}
	
	public Object set(int index,Object obj){
		rangeCheck(index);
		Object oldObj=elementData[index];
		elementData[index]=obj;
		return oldObj;
	}
	
	public void remove(int index){
		rangeCheck(index);
		int numMoved=size-index-1;
		if(numMoved>0)
			System.arraycopy(elementData, index+1, elementData, index, numMoved);
		elementData[--size]=null;
	}
	
	public void remove(Object obj){
		for(int i=0;i<size;i++){
			if(this.get(i).equals(obj))
				remove(i);
		}
	}
	
	public void add(Object obj){
		ensureCapacity();
		elementData[size]=obj;
		size++;
	}

	private void ensureCapacity() {
		// TODO Auto-generated method stub
		if(size==elementData.length){
			Object[] newArray=new Object[size*2+1];
			System.arraycopy(elementData, 0, newArray, 0, elementData.length);
			elementData=newArray;
		}
	}
	
	public void add(int index,Object obj){
		rangeCheck(index);
		ensureCapacity();
		System.arraycopy(elementData, index, elementData, index, size-index);
		elementData[index]=obj;
		size++;
	}
	
}
