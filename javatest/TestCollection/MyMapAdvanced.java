package TestCollection;

import java.util.LinkedList;

/*
 * 提高查询效率
 */

public class MyMapAdvanced {
	LinkedList[] arr=new LinkedList[999];//Map底层 数组+链表
	int size;
	
	
	public void put(Object key,Object value){
		Entry e=new Entry(key,value);
		
		//以免hashcode为负值
		int hash=key.hashCode();
		hash=hash<0?-hash:hash;
		
		int a=key.hashCode()%arr.length;
		
		if(arr[a]==null){
			LinkedList list=new LinkedList();
			arr[a]=list;
			list.add(e);
		}else{
			LinkedList list=arr[a];
			for(int i=0;i<list.size();i++){
				Entry e2=(Entry) list.get(i);
				if(e2.key.equals(key)){
					e2.value=value; //键值重复 ，覆盖
					return;
				}
			}
			arr[a].add(e); 
		}
		//arr[a]=e;
		
	}
	
	public Object get(Object key){
		//return arr[key.hashCode()%999];
		int a=key.hashCode()%arr.length;
		if(arr[a]!=null){
			LinkedList list=arr[a];
			for(int i=0;i<list.size();i++){
				Entry e=(Entry) list.get(i);
				if(e.key.equals(key)){
					return e.value;
				}
			}
		}
		return null;
	}
	
	public static void main(String[] args){
		MyMapAdvanced map=new MyMapAdvanced();
		map.put("aaa", "aaadog");
		map.put("bbb", "bbbdog");
		map.put("bbb","ccccc");
		
		System.out.println(map.get("bbb"));
	}
	
}


class EntryAdvanced{
	Object key;
	Object value;
	
	public EntryAdvanced(Object key,Object value){
		super();
		this.key=key;
		this.value=value;
	}
}
