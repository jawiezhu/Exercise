package OfferSolution;

public class MergeSortedList {
	public ListNode merge(ListNode l1,ListNode l2){
		if(l1==null && l2==null) return null;
		
		ListNode dummyHead=new ListNode(0);
		ListNode p=dummyHead;
		
		while(l1!=null&&l2!=null){
			if(l1.value>l2.value){
				p.next=l1;
				l1=l1.next;
			}else if(l1.value<l2.value){
				p.next=l2;
				l2=l2.next;
			}
			p=p.next;
		}
		
		if(l1!=null) p.next=l1;
		if(l2!=null) p.next=l2;
		
		return dummyHead.next;
	}
	
	
	public ListNode mergeRecursion(ListNode l1,ListNode l2){
		if(l1==null)
			return l2;
		else if(l2==null)
			return l1;
		
		ListNode newHead=null;
		
		if(l1.value<l2.value){
			newHead=l1;
			newHead.next=mergeRecursion(l1.next,l2);
		}else{
			newHead=l2;
			newHead.next=mergeRecursion(l1,l2.next);
		}
		
		return newHead;
	}
}
