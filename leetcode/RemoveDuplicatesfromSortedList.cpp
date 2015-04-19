// Given a sorted linked list, delete all duplicates such that each element appear only once.

// For example,
// Given 1->1->2, return 1->2.
// Given 1->1->2->3->3, return 1->2->3.


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
    ListNode *deleteDuplicates(ListNode *head) {
        if(head == NULL || head->next == NULL)
            return head; 
        ListNode *p;
        ListNode *q;
        q=head;
        p=head->next; 
        while(p!=NULL)
        {
            if(p->val==q->val)
            {
                q->next=p->next;
                p=q->next;
            }else{
           		p=p->next;
            	q=q->next;
            }    
        }    
        return head;  
    }
};