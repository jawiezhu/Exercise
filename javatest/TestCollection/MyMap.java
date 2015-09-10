package TestCollection;

public class MyMap {
	
	Entry[] arr=new Entry[990];
	int size;
	
	public void put(Object key,Object value){
		Entry e=new Entry(key,value);
		
		/*
		 * 每次需要遍历，效率过低，需要改进
		 */
		for(int i=0;i<size;i++){
			if(arr[i].key.equals(key)){
				arr[i].value=value;
			}
		}
		arr[size++]=e;
	}
	
	public Object get(Object key){
		for(int i=0;i<size;i++){
			//not ==
			if(arr[i].key.equals(key)){
				return arr[i].value;
			}
		}
		
		return null;
	}
	
//	public void remove(Object key){
//		for(int i=0;i<size;i++){
//			if(arr[i].key.equals(key)){
//				System.arraycopy(arr, i, arr, i+1, size-i);
//			}
//			size--;
//		}
//	}
	
	public boolean containsKey(Object key){
		for(int i=0;i<size;i++){
			if(arr[i].key.equals(key)){
				return true;
			}
		}
		return false;
	}
	
	public boolean containsValue(Object value){
		for(int i=0;i<size;i++){
			if(arr[i].value.equals(value)){
				return true;
			}
		}
		return false;
	}
	
	public static void main(String[] args){
		MyMap map=new MyMap();
		map.put("azhu","gou");
		map.put("huihui", "dog");
		map.put("huihui", "dogggg");
		//map.remove("huihui");
		System.out.println(map.get("huihui"));
		System.out.println(map.size);
	}
}

class Entry{
	Object key;
	Object value;
	
	public Entry(Object key,Object value){
		super();
		this.key=key;
		this.value=value;
	}
}