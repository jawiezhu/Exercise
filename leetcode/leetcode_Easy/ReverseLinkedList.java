package leetcode_Easy;

public class ReverseLinkedList {
	 public ListNode reverseList(ListNode head) {
		 //ͷ�巨
	      ListNode root=null;
	      ListNode nextNode;
	      while(head!=null){
	    	  nextNode=head.next;
	    	  head.next=root;
	    	  
	    	  root=head;
	    	  head=nextNode;
	      }
	      
	      return root.next;
	 }
	 
	 
	 public ListNode reverseList2(ListNode head) {
		 if(head==null || head.next==null) return head;
		 
		 ListNode second=head.next;
		 
		 head.next=null;
		 
		 ListNode res=reverseList2(second);
		 
		 second.next=head;
		 return res;
	 }
	 
	 
	 public ListNode reverseList3(ListNode head) {
		    return reverseListInt(head, null);
		}

		public ListNode reverseListInt(ListNode head, ListNode newHead) {
		    if(head == null)
		        return newHead;
		    ListNode next = head.next;
		    head.next = newHead;
		    return reverseListInt(next, head);
		}
}
