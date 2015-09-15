package leetcode_Easy;

public class ReverseLinkedList {
	 public ListNode reverseList(ListNode head) {
		 //ͷ�巨
	      ListNode root=new ListNode(0);
	      ListNode nextNode;
	      while(head!=null){
	    	  nextNode=head.next;
	    	  head.next=root.next;
	    	  
	    	  root.next=head;
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
}
