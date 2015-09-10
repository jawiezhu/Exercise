package leetcode;

public class MergeTwoSortedLists {
	public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        
		ListNode dummy=new ListNode(0);
		ListNode p=dummy;
		
		while(l1!=null && l2!=null){
			if(l1.val>l2.val)
			{
				p.next=l2;
				l2=l2.next;
			}else{
				p.next=l1;
				l1=l1.next;
			}
			p=p.next;
		}
		
		if(l1!=null) p.next=l1;
		if(l2!=null) p.next=l2;
		return dummy.next;
		
    }
}
