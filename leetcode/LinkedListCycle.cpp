// Given a linked list, determine if it has a cycle in it.

// Follow up:
// Can you solve it without using extra space?




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
    bool hasCycle(ListNode *head) {
        if(head==NULL||head->next==NULL) return 0;

        ListNode *p=head;
        ListNode *q=head;
        int flag=0;
        while(p->next)
        {
            if(p->next==q)
            {
                flag=1;
                break;
            }
            p=p->next;
            if(p->next==NULL)
                break;
            p=p->next;
            q=q->next;
        }
        if(flag==1)
            return 1;
        else
            return 0;
    }
};