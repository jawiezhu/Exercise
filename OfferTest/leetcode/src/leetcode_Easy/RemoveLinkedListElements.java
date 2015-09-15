package leetcode_Easy;

public class RemoveLinkedListElements {
	 public ListNode removeElements(ListNode head, int val) {
	        ListNode root=new ListNode(1);
	        root.next=head;
	        
	        ListNode prev=root;
	        
	        while(prev.next!=null){
	        	if(prev.next.val==val){
	        		prev.next=prev.next.next;
	        	}else{
	        		prev=prev.next;
	        	}
	        }
	        
	        return root.next;
	 }
}
