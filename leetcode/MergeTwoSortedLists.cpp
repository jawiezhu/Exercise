// Merge two sorted linked lists and return it as a new list. 
// The new list should be made by splicing together the nodes of the first two lists.
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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if(l1==NULL)return l2;
        if(l2==NULL)return l1;
        
        ListNode *ret=NULL;
        if(l1->val<l2->val)
        {
            ret=l1;
            ret->next=mergeTwoLists(l1->next,l2);
        }else
        {
            ret=l2;
            ret->next=mergeTwoLists(l1,l2->next);
        }
        
        return ret;
        
    }
};

//=====================归并排序的合并部分
class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode *helper=new ListNode(0);
        ListNode *head=helper;
        while(l1 && l2)
        {
             if(l1->val<l2->val) helper->next=l1,l1=l1->next;
             else helper->next=l2,l2=l2->next;
             helper=helper->next;
        }
        if(l1) helper->next=l1;
        if(l2) helper->next=l2;
        return head->next;
    }
};


//============
//思路很简单，就是遍历两个链表，每次取最小值
class Solution {  
public:  
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {  
        ListNode * head = new ListNode(0);  
        ListNode * ptr = head;  
          
        while(l1 != NULL || l2 != NULL){  
            ListNode * cur = NULL;  
            if(l1 == NULL){  
                cur = l2;  
                l2 = l2->next;  
            }  
            else if(l2 == NULL){  
                cur = l1;  
                l1 = l1->next;  
            }  
            else{  
                if(l1->val < l2->val){  
                    cur = l1;  
                    l1 = l1->next;  
                }  
                else{  
                    cur = l2;  
                    l2 = l2->next;  
                }  
            }  
            ptr->next = cur;  
            ptr = ptr->next;  
        }  
          
        return head->next;  
    }  
};

//这个题目中的链表和书中的链表稍有差别，书中有头指针，但是这里却没有头指针，
// 有头指针的链表结构和没有头指针的链表差别在，有头指针的链表在插入删除时，所有的操作是一样的，
// 相反，没有头指针的，第一个节点操作跟后面的节点是不一样的。
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        ListNode p,q,r,head;
        if(l1 == null && l2 == null){
           return null;
        }
         if(l1 == null){
             return l2;
        }
         if(l2 == null){
            return l1;
        }
        // if(p == null && q == null){
        //     return l1;
        // }
        p = l1;
        q = l2;
        head = null;
        if(p.val <= q.val){
               // r->next = p;
                head = p;
                p = p.next;
            }
        else{
                head = q;
                q = q.next;
                // r->next = q;
                // r-next = p;
            }
            r = head;
        while(p != null && q != null){
            if(p.val <= q.val){
               // r->next = p;
                r.next = p;
                r = p;
                p = p.next;
            }
            else{
                r.next = q;
                r = q;
                
                q = q.next;
                // r->next = q;
                // r-next = p;
                
            }
        }
        if(p == null){
            while(q != null){
                r.next = q;
                r = q;
                q = q.next;
            }
        }
        else{
            while(p != null){
                r.next = p;
                r = p;
                p = p.next;
            }
        }
        return head;
    }
};

