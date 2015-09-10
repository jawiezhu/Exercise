package TestCollection;

public class MyLinkedList {
	private Node first;
	private Node last;
	private int size;
	
	public MyLinkedList(){
		super();
	}
	
	public void add(Object obj){
		Node n=new Node();
		if(first==null){
			//Node n=new Node();
			n.setPrevious(null);
			n.setObj(obj);
			n.setNext(null);
			
			first=n;
			last=n;
		}else{
			//Node n=new Node();
			n.setPrevious(last);
			n.setObj(obj);
			n.setNext(null);
			
			last.setNext(n);
			last=n;
		}
		size++;
	}
	
	public int size(){
		return size;
	}
	
	public Object get(int index){
		rangeCheck(index);
		Node temp=node(index);
		if(temp!=null){
			return temp.obj;
		}
		return null;
	}
	
	/*
	 * can not remove the head or tail.
	 */
	public void remove(int index){
		rangeCheck(index);
		Node temp=node(index);
		if(temp!=null){
			Node up=temp.previous;
			Node down=temp.next;
			up.next=down;
			down.previous=up;
		}
		size--;
	} 
	
	public Node node(int index){
		Node temp=null;
		if(first!=null){
			temp=first;
			for(int i=0;i<index;i++){
				temp=temp.next;
			}
		}
		
		return temp;
	}
	
	public void add(int index,Object obj){
		Node temp=node(index);
		
		Node newNode=new Node();
		newNode.obj=obj;
		if(temp!=null){
			Node up=temp.previous;
			//Node down=temp.next;
			
			up.next=newNode;
			newNode.previous=up;
			
			newNode.next=temp;
			temp.previous=newNode;
		}
		size++;
	}
	
	public void rangeCheck(int index){
		if(index<0||index>=size){
			try{
				throw new Exception();
			}catch(Exception e){
				e.printStackTrace();
			}
		}
	}
	
	public static void main(String[] args){
		MyLinkedList list=new MyLinkedList();
		list.add("aaaa");
		list.add("bbb");
		list.add("cccc");
		//list.remove(0);
		//list.remove(1);
		list.add(1,"azhu");
		System.out.println(list.size());
		System.out.println(list.get(0));
		System.out.println(list.get(1));
		
	}
}


