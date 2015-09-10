package OfferSolution;

public class DeleteNodeInList {
	
	
	public ListNode DeleteNode(ListNode head,ListNode Deleted){
		if(head==null || Deleted==null) return null;
		ListNode dummyNode=new ListNode(0);
		dummyNode.next=head;
		ListNode p=head;
		
		if(Deleted.next!=null){ 	//删除中间某一节点
			Deleted.value=Deleted.next.value;
			Deleted.next=Deleted.next.next;
		}else if(p==Deleted){	//只有一个节点
			dummyNode.next=null;
		}else{					//删除尾节点
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