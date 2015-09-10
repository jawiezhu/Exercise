package OfferSolution;

public class KthNodeFromEnd {
	public ListNode FindK(ListNode head,int k){
		if(head==null||k==0) return null;
		
		ListNode p=head;
		ListNode q=head;
		
		for(int i=0;i<k-1;i++){
			if(q.next!=null){
				q=q.next;
			}else{
				return null;
			}
		}
		
		while(q.next!=null){
			q=q.next;
			p=p.next;
		}
		
		return p;
	}
}
