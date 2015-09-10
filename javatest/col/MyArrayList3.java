package col;

import java.util.Iterator;



public class MyArrayList3 implements java.lang.Iterable<String>{
	private String[] elem={"a","b","c","d","e","f","g"};
	private int size=elem.length;
	
	//�������ô����֮ǰ�ķ��� ֻ����һ�Σ���һ��֮�� cursor������-1
	//����������ÿ�ε��ã���ÿ�����µ�cursor

	//�����ڲ���
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
			//����remove
		}
		
		//��ǿfor ����ʵ��java.lang.Iterable�ӿڣ���дIterator����
		//����ɾ��Ԫ��remove
		for(String temp:list){
			System.out.println(temp);
			//it.remove();
		}
	}

}
