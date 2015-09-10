package leetcode;

import java.util.Stack;

public class PalindromeLinkedList {
	//solution
	//�ҵ������е㣬��ֺ���ת��������Ȼ����������ͬʱ˳�����һ�Ρ�
	//��������Ϊ��������ĩβ��Ԫ�ؿ��Ժ��ԡ�

	//ʱ�临�Ӷ�O(n)���ռ临�Ӷ�O(n)
	public boolean isPalindrome(ListNode head) {
			if(head==null) return true;
	        ListNode p=head;
	        Stack<ListNode> s=new Stack<ListNode>();
	        boolean flag=true;
	        
	        while(p!=null){
	        	s.push(p);
	        	p=p.next;
	        }
	        
	        ListNode q=head;
	        
	        while(!s.isEmpty()&&q!=null){
	        	if(q.val!=s.peek().val){
	        		flag=false;
	        		break;
	        	}
	        	s.pop();
	        	q=q.next;
	        }
	        
	        return flag;
	        
	}
	
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}
	
}
