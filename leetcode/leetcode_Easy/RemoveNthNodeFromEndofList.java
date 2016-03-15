package leetcode_Easy;

public class RemoveNthNodeFromEndofList {
	public ListNode removeNthFromEnd(ListNode head, int n) {
        ListNode pa=head;
        ListNode pb=head;
        
        for(int i=0;i<n && pa!=null;i++){
        	pa=pa.next;
        }
        
        if(pa==null){
        	head=head.next;
        	return head;
        }
        
        while(pa.next!=null){
        	pa=pa.next;
        	pb=pb.next;
        }
        
        pb.next=pb.next.next;
        return head;
        
    }
}
