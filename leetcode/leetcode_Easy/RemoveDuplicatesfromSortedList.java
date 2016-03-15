package leetcode_Easy;

public class RemoveDuplicatesfromSortedList {
	public ListNode deleteDuplicates(ListNode head) {
        if(head==null || head.next==null) return head;
        ListNode p=head;
        
        while(p!=null && p.next!=null){
        	if(p.val==p.next.val){
        		p.next=p.next.next;
        	}else{
        		p=p.next;
        	}
        }
        
        return head;
        
    }
	
	public ListNode deleteDuplicates2(ListNode head) {
        if(head == null)
            return null;
        if(head.next != null && head.next.val == head.val) {
            head.next = head.next.next;
            head = deleteDuplicates(head);
        }
        else
            head.next = deleteDuplicates(head.next);

        return head;
    } 
}
