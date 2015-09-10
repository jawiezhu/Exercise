package leetcode;

import java.util.Stack;

public class PalindromeLinkedList {
	//solution
	//找到链表中点，拆分后，逆转后半个链表，然后两个链表同时顺序遍历一次。
	//若链表长度为奇数，最末尾的元素可以忽略。

	//时间复杂度O(n)，空间复杂度O(n)
	public boolean isPalindrome(ListNode head) {
			if(head==null) return true;
	        ListNode p=head;
	        Stack<ListNode> s=new Stack<ListNode>();
	        boolean flag=true;
	        
	        while(p!=null){
	        	s.push(p);
	        	p=p.next;
	        }
	        
	        ListNode q=head;
	        
	        while(!s.isEmpty()&&q!=null){
	        	if(q.val!=s.peek().val){
	        		flag=false;
	        		break;
	        	}
	        	s.pop();
	        	q=q.next;
	        }
	        
	        return flag;
	        
	}
	
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}
	
}
