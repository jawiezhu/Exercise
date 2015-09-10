package OfferSolution;

public class EntryNodeInListLoop {
	public static ListNode meetingNode(ListNode head){
		ListNode fast=head;
		ListNode slow=head;
		
		while(fast!=null && fast.next!=null){
			fast=fast.next.next;
			slow=slow.next;
			if(fast==slow){
				break;
			}
		}
		
		if(fast==null || fast.next==null){
			return null;
		}
		
		fast=head;
		while(fast!=slow){
			fast=fast.next;
			slow=slow.next;
		}
		return fast;
	}
	
	  public static void main(String[] args) {
	        test01();
	        test02();
	        test03();
	    }

	    // 1->2->3->4->5->6
	    private static void test01() {
	        ListNode n1 = new ListNode(1);
	        ListNode n2 = new ListNode(2);
	        ListNode n3 = new ListNode(3);
	        ListNode n4 = new ListNode(4);
	        ListNode n5 = new ListNode(5);
	        ListNode n6 = new ListNode(6);

	        n1.next = n2;
	        n2.next = n3;
	        n3.next = n4;
	        n4.next = n5;
	        n5.next = n6;

	        System.out.println(meetingNode(n1));
	    }

	    // 1->2->3->4->5->6
	    //       ^        |
	    //       |        |
	    //       +--------+
	    private static void test02() {
	        ListNode n1 = new ListNode(1);
	        ListNode n2 = new ListNode(2);
	        ListNode n3 = new ListNode(3);
	        ListNode n4 = new ListNode(4);
	        ListNode n5 = new ListNode(5);
	        ListNode n6 = new ListNode(6);

	        n1.next = n2;
	        n2.next = n3;
	        n3.next = n4;
	        n4.next = n5;
	        n5.next = n6;
	        n6.next = n3;

	        System.out.println(meetingNode(n1));
	    }

	    // 1->2->3->4->5->6 <-+
	    //                |   |
	    //                +---+
	    private static void test03() {
	        ListNode n1 = new ListNode(1);
	        ListNode n2 = new ListNode(2);
	        ListNode n3 = new ListNode(3);
	        ListNode n4 = new ListNode(4);
	        ListNode n5 = new ListNode(5);
	        ListNode n6 = new ListNode(6);

	        n1.next = n2;
	        n2.next = n3;
	        n3.next = n4;
	        n4.next = n5;
	        n5.next = n6;
	        n6.next = n6;

	        System.out.println(meetingNode(n1));
	    }
}


class SolutioninBook{
	public ListNode MeetingNode(ListNode pHead){
		if(pHead==null) return null;
		
		ListNode pSlow=pHead.next;
		if(pSlow==null) return null;
		
		ListNode pFast=pSlow.next;
		while(pFast!=null && pSlow!=null){
			if(pFast==pSlow) return pFast;
			
			pSlow=pSlow.next;
			pFast=pFast.next;
			
			if(pFast!=null)
				pFast=pFast.next;
		}
		return null;
		
	}
	
	public ListNode EntryNodeOfLoop(ListNode pHead){
		ListNode meetingNode=MeetingNode(pHead);
		if(meetingNode==null) return null;
		
		//get the number of nodes in loop
		int nodesInLoop=1;
		ListNode pNode1=meetingNode;
		while(pNode1.next!=meetingNode){
			pNode1=pNode1.next;
			nodesInLoop++;
		}
		
		//move pNode1
		pNode1=pHead;
		for(int i=0;i<nodesInLoop;i++){
			pNode1=pNode1.next;
		}
		
		//move pNode1 and pNode2
		ListNode pNode2=pHead;
		while(pNode1!=pNode2){
			pNode1=pNode1.next;
			pNode2=pNode2.next;
		}
		
		return pNode1;
	}
}
