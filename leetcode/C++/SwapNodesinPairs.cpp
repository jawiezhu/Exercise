// Given a linked list, swap every two adjacent nodes and return its head.

// For example,
// Given 1->2->3->4, you should return the list as 2->1->4->3.

// Your algorithm should use only constant space. 
// You may not modify the values in the list, only nodes itself can be changed.



/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 *ERROR**/
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
       if(head==NULL) return NULL;
       if(head->next==NULL) return head;
       
        ListNode * p=head->next;
        ListNode * tmp=head->next;
        ListNode * q=head;
        ListNode * qq=head;
        
        ListNode * start=head->next;
        tmp->next=q;
        while(tmp->next!=NULL)
        {	
        	tmp=tmp->next->next;
        	qq=qq->next->next;
        	if(tmp->next!=NULL)
        	    q->next=tmp;
        	 else
        	    q->next=NULL;
        	p=tmp;
        	p->next=qq;
        
        }
        q->next=NULL;
        return start;
        
    }
};



// 考察一个对于单链表轮换的问题，只要弄清楚指针指向对象的顺序问题，然后调用递归就可以解决问题了。

// 注意点：1.链表问题一定要考虑head指向的是一个空链表，既NULL，必须先加以判断，同样这是递归的终止条件。

// 2.考虑到链表的元素的奇、偶性，如果最后只剩一个元素，也是终止递归，返回这个元素的值。
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
    ListNode *swapPairs(ListNode *head) {
       if (head == NULL)
            return NULL;
       if (head -> next == NULL)
            return head;
       ListNode *tmp = head -> next;
       head -> next = swapPairs(tmp -> next);
       tmp -> next = head;
       return tmp;
    }
};
//ERROR
class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
       if (head == NULL)
            return NULL;
       if (head -> next == NULL)
            return head;
       ListNode *tmp = head -> next;
       head -> next -> next = head; //这里已经改变了tmp指向内容的next
       head -> next = swapPairs(tmp -> next);//这里会形成一个循环指向自己的情况，根本跳不出递归。
       return tmp;
    }
};

// //建立新链表每次插入ret->next后在插入ret，
// 需要在判断下若最后只有一个结点不需要交换，注意每次交换了结点要把尾结点的下一个指向空

class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
        if(head==NULL || head->next==NULL) return head;
        ListNode *helper=new ListNode(0);
        ListNode *ret=head;
        ListNode *cur=helper;
        while(ret  && ret->next)
        {
            ListNode *next=ret->next->next;
            cur->next=ret->next;
            cur=cur->next;
            cur->next=ret;
            cur=cur->next;
            cur->next=NULL;
            ret=next;
        }
        if(ret) cur->next=ret;
        return helper->next;
    }
};


//================
class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        //check null list
        if(head==NULL) return head;
        //check single-node list;
        if(head->next==NULL) return head;
        
        ListNode *prev;
        ListNode *p1;
        ListNode *p2;
        p1=head;
        prev=head;
        do{
            p2=p1->next;
            p1->next=p2->next;
            p2->next=p1;
            if(prev!=head)
                prev->next=p2;
            else
                head=p2;
            prev=p1;
            p1=p1->next;
        }while(p1!=NULL && p1->next!=NULL);
        
        return head;
    }
};

//
// LeetCode, Swap Nodes in Pairs
// 时间复杂度O(n)，空间复杂度O(1)
class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
        if (head == nullptr || head->next == nullptr) return head;
        ListNode dummy(-1);
        dummy.next = head;

        for(ListNode *prev = &dummy, *cur = prev->next, *next = cur->next;
                next;
                prev = cur, cur = cur->next, next = cur ? cur->next: nullptr) {
            prev->next = next;
            cur->next = next->next;
            next->next = cur;
        }
        return dummy.next;
    }
};

//
// LeetCode, Swap Nodes in Pairs
// 时间复杂度O(n)，空间复杂度O(1)
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* p = head;

        while (p && p->next) {
            swap(p->val, p->next->val);
            p = p->next->next;
        }

        return head;
    }
};
