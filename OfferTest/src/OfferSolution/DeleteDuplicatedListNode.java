package OfferSolution;

public class DeleteDuplicatedListNode {
	public static ListNode deleteDuplication(ListNode pHead){
		if(pHead==null) return null;
		
		//��ʱͷ���
		ListNode root=new ListNode();
		root.next=pHead;
		//��¼ǰ�����
		ListNode prev=root;
		//��¼��ǰ����Ľ��
		ListNode node=pHead;
		while(node!=null && node.next!=null){
			// ���ظ���㣬��nodeֵ��ͬ�Ľ�㶼Ҫɾ��
			if(node.value==node.next.value){
				// �ҵ���һ����ֵͬ�Ľڵ㣬ע�����п���Ҳ���ظ��ڵ�
				while(node.next!=null && node.next.value==node.value){
					node=node.next;
				}
				
				// ָ����һ���ڵ㣬prev.nextҲ�������ظ����
                // ����prev��Ҫ�ƶ�����һ�����
				prev.next=node.next;
			}else{
				// ��������ֵ��ͬ��˵��node����ɾ����Ҫ����
				prev.next=node;
				prev=prev.next;
			}
			node=node.next;
		}
		return root.next;
	}
	
	  private static void print(ListNode head) {
	        while (head != null) {
	            System.out.print(head + "->");
	            head = head.next;
	        }
	        System.out.println("null");
	    }
	  
	  public static void main(String[] args) {
	        test01();
	        test02();
	        test03();
	        test04();
	        test05();
	        test06();
	        test07();
	        test08();
	        test09();
	        test10();
	    }
	  
	  // 1->2->3->3->4->4->5
	    private static void test01() {
	        ListNode n1 = new ListNode(1);
	        ListNode n2 = new ListNode(2);
	        ListNode n3 = new ListNode(3);
	        ListNode n4 = new ListNode(3);
	        ListNode n5 = new ListNode(4);
	        ListNode n6 = new ListNode(4);
	        ListNode n7 = new ListNode(5);

	        n1.next = n2;
	        n2.next = n3;
	        n3.next = n4;
	        n4.next = n5;
	        n5.next = n6;
	        n6.next = n7;

	        ListNode result = deleteDuplication(n1);
	        print(result);
	    }

	    // 1->2->3->4->5->6->7
	    private static void test02() {
	        ListNode n1 = new ListNode(1);
	        ListNode n2 = new ListNode(2);
	        ListNode n3 = new ListNode(3);
	        ListNode n4 = new ListNode(4);
	        ListNode n5 = new ListNode(5);
	        ListNode n6 = new ListNode(6);
	        ListNode n7 = new ListNode(7);

	        n1.next = n2;
	        n2.next = n3;
	        n3.next = n4;
	        n4.next = n5;
	        n5.next = n6;
	        n6.next = n7;

	        ListNode result = deleteDuplication(n1);
	        print(result);
	    }

	    // 1->1->1->1->1->1->2
	    private static void test03() {
	        ListNode n1 = new ListNode(1);
	        ListNode n2 = new ListNode(1);
	        ListNode n3 = new ListNode(1);
	        ListNode n4 = new ListNode(1);
	        ListNode n5 = new ListNode(1);
	        ListNode n6 = new ListNode(1);
	        ListNode n7 = new ListNode(2);

	        n1.next = n2;
	        n2.next = n3;
	        n3.next = n4;
	        n4.next = n5;
	        n5.next = n6;
	        n6.next = n7;

	        ListNode result = deleteDuplication(n1);
	        print(result);
	    }


	    // 1->1->1->1->1->1->1
	    private static void test04() {
	        ListNode n1 = new ListNode(1);
	        ListNode n2 = new ListNode(1);
	        ListNode n3 = new ListNode(1);
	        ListNode n4 = new ListNode(1);
	        ListNode n5 = new ListNode(1);
	        ListNode n6 = new ListNode(1);
	        ListNode n7 = new ListNode(1);

	        n1.next = n2;
	        n2.next = n3;
	        n3.next = n4;
	        n4.next = n5;
	        n5.next = n6;
	        n6.next = n7;

	        ListNode result = deleteDuplication(n1);
	        print(result);
	    }

	    // 1->1->2->2->3->3->4->4
	    private static void test05() {
	        ListNode n1 = new ListNode(1);
	        ListNode n2 = new ListNode(1);
	        ListNode n3 = new ListNode(2);
	        ListNode n4 = new ListNode(2);
	        ListNode n5 = new ListNode(3);
	        ListNode n6 = new ListNode(3);
	        ListNode n7 = new ListNode(4);
	        ListNode n8 = new ListNode(4);

	        n1.next = n2;
	        n2.next = n3;
	        n3.next = n4;
	        n4.next = n5;
	        n5.next = n6;
	        n6.next = n7;
	        n7.next = n8;

	        ListNode result = deleteDuplication(n1);
	        print(result);
	    }

	    // 1->1->2->3->3->4->5->5
	    private static void test06() {
	        ListNode n1 = new ListNode(1);
	        ListNode n2 = new ListNode(1);
	        ListNode n3 = new ListNode(2);
	        ListNode n4 = new ListNode(3);
	        ListNode n5 = new ListNode(3);
	        ListNode n6 = new ListNode(4);
	        ListNode n7 = new ListNode(5);
	        ListNode n8 = new ListNode(5);

	        n1.next = n2;
	        n2.next = n3;
	        n3.next = n4;
	        n4.next = n5;
	        n5.next = n6;
	        n6.next = n7;
	        n7.next = n8;

	        ListNode result = deleteDuplication(n1);
	        print(result);
	    }

	    // 1->1->2->2->3->3->4->5->5
	    private static void test07() {
	        ListNode n1 = new ListNode(1);
	        ListNode n2 = new ListNode(1);
	        ListNode n3 = new ListNode(2);
	        ListNode n4 = new ListNode(2);
	        ListNode n5 = new ListNode(3);
	        ListNode n6 = new ListNode(3);
	        ListNode n7 = new ListNode(4);
	        ListNode n8 = new ListNode(5);
	        ListNode n9 = new ListNode(5);

	        n1.next = n2;
	        n2.next = n3;
	        n3.next = n4;
	        n4.next = n5;
	        n5.next = n6;
	        n6.next = n7;
	        n7.next = n8;
	        n8.next = n9;

	        ListNode result = deleteDuplication(n1);
	        print(result);
	    }

	    // 1->2
	    private static void test08() {
	        ListNode n1 = new ListNode(1);
	        ListNode n2 = new ListNode(2);

	        n1.next = n2;

	        ListNode result = deleteDuplication(n1);
	        print(result);
	    }

	    // 1
	    private static void test09() {
	        ListNode n1 = new ListNode(1);
	        ListNode result = deleteDuplication(n1);
	        print(result);
	    }

	    // null
	    private static void test10() {
	        ListNode result = deleteDuplication(null);
	        print(result);
	    }
}
