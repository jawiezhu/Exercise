package leetcode_Easy;

public class DeleteNodeinaLinkedList {
	 public void deleteNode(ListNode node) {
	        if(node==null) return;
	        
	        node.val=node.next.val;
	        node.next=node.next.next;
	    }
}
