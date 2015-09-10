package OfferSolution;

public class ReverseList {
	public ListNode ReverseList(ListNode head){
		
		if(head==null) return null;
		ListNode pNode=head;
		ListNode pPrev=null;
		ListNode pNext=null;
		ListNode newHead=null;
		
		
		while(pNode!=null){
			pNext=pNode.next;
			if(pNext==null)
				newHead=pNode;
			pNode.next=pPrev;
			
			pPrev=pNode;
			pNode=pNext;
		}
		
		return newHead;	
	}
	
	
	public ListNode ReverseRecursion(ListNode head){
		if(head==null||head.next==null) return head;
		
		ListNode newhead=ReverseRecursion(head.next);
		head.next.next=head;
		head.next=null;
		return newhead;
		
	}
	
}	
