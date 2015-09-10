package OfferSolution;

public class CopyComplexList {
	public  ComplexListNode Clone(ComplexListNode Head){
		CloneNodes(Head);
		ConnectSiblingNodes(Head);
		return ReconnectNodes(Head);
	}

	private ComplexListNode ReconnectNodes(ComplexListNode head) {
		// TODO Auto-generated method stub
		ComplexListNode pNode=head;
		ComplexListNode pCloneHead=null;
		ComplexListNode pCloneNode=null;
		
		if(pNode!=null)
		{
			pCloneHead=pCloneNode=pNode.next;
			pNode.next=pCloneNode.next;
			pNode=pNode.next;
		}
		
		while(pNode!=null){
			pCloneNode.next=pNode.next;
			pCloneNode=pCloneNode.next;
			pNode.next=pCloneNode.next;
			pNode=pNode.next;
		}
		return pCloneHead;
	}

	private void ConnectSiblingNodes(ComplexListNode head) {
		// TODO Auto-generated method stub
		ComplexListNode pNode=head;
		while(pNode!=null){
			ComplexListNode pCloned=pNode.next;
			if(pNode.sibling!=null){
				pCloned.sibling=pNode.sibling.next;
			}
			pNode=pCloned.next;
		}
		
	}

	private void CloneNodes(ComplexListNode head) {
		// TODO Auto-generated method stub
		ComplexListNode pNode=head;
		while(pNode!=null){
			ComplexListNode pCloned=new ComplexListNode();
			pCloned.value=pNode.value;
			pCloned.next=pNode.next;
			pCloned.sibling=null;
			
			pNode.next=pCloned;
			pNode=pCloned.next;
		}
		
	}
	
	
}



class ComplexListNode{
	int value;
	ComplexListNode next;
	ComplexListNode sibling;
}