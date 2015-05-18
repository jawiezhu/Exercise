// Given a linked list, remove the nth node from the end of list and return its head.

// For example,

//    Given linked list: 1->2->3->4->5, and n = 2.

//    After removing the second node from the end, the linked list becomes 1->2->3->5.
// Note:
// Given n will always be valid.
// Try to do this in one pass.



/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
    
        int i=0;
        int j;
          ListNode *s=new ListNode(0);
           s->next = head;
        ListNode *p=s;
      
        //ListNode* dumy = new ListNode(0);
       
        ListNode *q=s;
        //p=head;
        //q=head;
   
        while(i<n)
        {
            p=p->next;
            i++;
            
        }
        
        while(p->next!=NULL)
        {
            p=p->next;
            q=q->next;
        }

        q->next=q->next->next;

       
        return s->next;
    }
};


//两个指针，p先走n步，然后q开始走。当p走到末尾时，q正好到了待删除节点。

struct LinkNode
{
	int data;
	LinkNode *next;
	LinkNode(int x):data(x),next(NULL){}
};

LinkNode * removeNthNodeFromEnd(LinkNode *head,int n)
{
	if(head == NULL || n == 0)//防御性编程，增加健壮性
		return head;
	LinkNode *dummy = new LinkNode(-1);
	dummy->next = head;
	LinkNode *p,*q,*tmp;
	p = dummy;
	q = dummy;
	
	//p先走n步
	for(int i=0;i<n;i++)
	{
		if(p->next != NULL)
			p = p->next;
		else
			return head;//如果n超过链表的长度，直接返回head
	}

	//然后p,q一起走
	while(p->next)
	{
		p = p->next;
		q = q->next;
	}

	//此时q指向的是待删除节点的前驱
	tmp = q->next->next;
	delete q->next;
	q->next = tmp;

	head = dummy->next;
	delete dummy;
	return head;
}
//-----

//依然是双指针思想，两个指针相隔n-1，每次两个指针向后一步，当后面一个指针没有后继了，前面一个指针就是要删除的节点。
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (head == NULL)
            return NULL;
            
        ListNode *pPre = NULL;
        ListNode *p = head;
        ListNode *q = head;
        for(int i = 0; i < n - 1; i++)
            q = q->next;
            
        while(q->next)
        {
            pPre = p;
            p = p->next;
            q = q->next;
        }
        
        if (pPre == NULL)
        {
            head = p->next;
            delete p;
        }
        else
        {
            pPre->next = p->next;
            delete p;
        }
        
        return head;
    }
};

//
// 1 准备两个指针first, second
// 2 先让fisrt走n步
// 3 让fisrt和second同时走直到first遇到结尾
// 4 要用一个temp指针来记录second前一个node，用来删除second用。
ListNode *removeNthFromEnd(ListNode *head, int n) {
     ListNode *first = head, *second = head;
     ListNode *temp = second;
 
     for(int i = 0; i < n; i++) {
         first = first -> next;
     }
 
     while(first) {
         first = first -> next;
         temp = second;
         second = second -> next;
     }
 
     if(second == head) {
         head = head -> next;
     }
     else {
         temp -> next = second -> next;
     }
 
 
     return head;
 }
//



// LeetCode, Remove Nth Node From End of List
// 时间复杂度O(n)，空间复杂度O(1)
class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode dummy{-1, head};
        ListNode *p = &dummy, *q = &dummy;

        for (int i = 0; i < n; i++)  // q先走n步
            q = q->next;

        while(q->next) { // 一起走
            p = p->next;
            q = q->next;
        }
        ListNode *tmp = p->next;
        p->next = p->next->next;
        delete tmp;
        return dummy.next;
    }
};


