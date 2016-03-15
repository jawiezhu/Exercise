package leetcode_Easy;

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
	
	
	public ListNode mergeTwoLists2(ListNode l1, ListNode l2) {
        if(l1 == null){
            return l2;
        }
        if(l2 == null){
            return l1;
        }

        ListNode mergeHead;
        if(l1.val < l2.val){
            mergeHead = l1;
            mergeHead.next = mergeTwoLists(l1.next, l2);
        }
        else{
            mergeHead = l2;
            mergeHead.next = mergeTwoLists(l1, l2.next);
        }
        return mergeHead;
    }
}
