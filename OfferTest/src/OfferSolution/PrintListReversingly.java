package OfferSolution;

import java.util.Stack;

public class PrintListReversingly {

	public void iteratively(ListNode head){
		Stack<ListNode> stack=new Stack();
		ListNode p=head;
		while(p!=null)
		{
			stack.push(p);
			p=p.next;
		}
		
		while(!stack.isEmpty()){
			p=stack.peek();
			System.out.println(p.value);
			stack.pop();
		}
	}
	
	public void recursively(ListNode head){
		ListNode p=head;
		if(p!=null){
			if(p.next!=null){
				recursively(p.next);
			}
			System.out.println(p.value);
		}
	}
	
	public static void main(String[] args) {
		

	}

}
