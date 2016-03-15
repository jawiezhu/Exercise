package leetcode_Easy;

public class MinStack {
	Node head;
	public void push(int x) {
        if(head==null){
        	head=new Node(x);
        }else{
        	Node tmp=new Node(x);
        	tmp.min=Math.min(head.min, x);
        	tmp.next=head;
        	head=tmp;
        }
    }

    public void pop() {
        if(head==null) return ;
        head=head.next;
    }

    public int top() {
        if(head==null) return Integer.MAX_VALUE;
        return head.value;
    }

    public int getMin() {
        if(head==null) return Integer.MAX_VALUE;
        return head.min;
    }
}


class Node{
	int value;
	int min;
	Node next;
	Node(int x){
		value=x;
		next=null;
		min=x;
	}
}