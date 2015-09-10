package OfferSolution;

public class DeleteNodeInList {
	
	
	public ListNode DeleteNode(ListNode head,ListNode Deleted){
		if(head==null || Deleted==null) return null;
		ListNode dummyNode=new ListNode(0);
		dummyNode.next=head;
		ListNode p=head;
		
		if(Deleted.next!=null){ 	//ɾ���м�ĳһ�ڵ�
			Deleted.value=Deleted.next.value;
			Deleted.next=Deleted.next.next;
		}else if(p==Deleted){	//ֻ��һ���ڵ�
			dummyNode.next=null;
		}else{					//ɾ��β�ڵ�
			while(p.next!=Deleted){
				p=p.next;
			}
			
			p.next=null;
		}
		
		return dummyNode.next;
		
		
	}
}

class ListNode{
	public ListNode(int x){
		this.value=x;
	}
	
	public ListNode() {
		// TODO Auto-generated constructor stub
	}

	int value;
	ListNode next;
}