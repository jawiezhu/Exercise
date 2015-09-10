package col;

import java.util.Iterator;

/*
 * �򻯵�����  ����ӿ��ṩ����
 */
public class MyArrayList2 {
	private String[] elem={"a","b","c","d","e","f","g"};
	private int size=elem.length;
	
	//�������ô����֮ǰ�ķ��� ֻ����һ�Σ���һ��֮�� cursor������-1
	//����������ÿ�ε��ã���ÿ�����µ�cursor
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
