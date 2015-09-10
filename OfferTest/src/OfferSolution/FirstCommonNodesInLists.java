package OfferSolution;

public class FirstCommonNodesInLists {
	public ListNode FindCommon(ListNode head1,ListNode head2){
		ListNode p=head1;
		ListNode q=head2;
		
		int cnt1=0;
		while(p!=null)
		{
			cnt1++;
			p=p.next;
		}
		
		int cnt2=0;
		while(q!=null)
		{
			cnt2++;
			q=q.next;
		}
		
		
		ListNode p1=head1;
		ListNode q1=head2;
		
		int k=0;
		if(cnt1>cnt2){
			k=cnt1-cnt2;
			while(k>0)
			{
				p1=p1.next;
				k--;
			}
		}else{
			k=cnt2-cnt1;
			while(k>0)
			{
				q1=q1.next;
				k--;
			}
		}
		
		while(p1!=q1){
			p1=p1.next;
			q1=q1.next;
		}
		return p1;
	}
	
	
	public ListNode FindCommonNode(ListNode head1,ListNode head2){
		int len1=GetListLength(head1);
		int len2=GetListLength(head2);
		
		int lenDif=len1-len2;
		ListNode Long=head1;
		ListNode Short=head2;
		
		if(len2>len1){
			Long=head2;
			Short=head1;
			lenDif=len2-len1;
		}
		
		for(int i=0;i<lenDif;i++){
			Long=Long.next;
		}
		
		while(Long!=null && Short!=null && Long!=Short){
			Long=Long.next;
			Short=Short.next;
		}
		
		ListNode CommonNode=Long;
		return CommonNode;
	}


	private int GetListLength(ListNode head) {
		int length=0;
		ListNode p=head;
		while(p!=null){
			length++;
			p=p.next;
		}
		
		return length;
	}
}
