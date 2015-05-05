// Reverse a singly linked list.

// click to show more hints.

// Hint:
// A linked list can be reversed either iteratively or recursively. Could you implement both?


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

 //递归
 //如果只有一个节点，直接返回。否则，将当前链表 a1,a2,...an 的子链表 
 //a2,...an 进行逆转，返回逆转后的第一个节点的指针，再将 a1 节点加到 a2 节点后面。
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head==NULL||head->next==NULL) return head;

        ListNode *p=head->next;
        ListNode *newhead=reverseList(head->next);
        head->next=NULL;
        p->next=head;
        return newhead;

       } 
};




    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return head;
            
        ListNode *new_head = NULL;
        while(head != NULL) {
            ListNode *temp_old_head = head->next;
            if(new_head == NULL) {
                new_head = head;
                head->next = NULL;
            } else {
                ListNode *temp_new_head = new_head;
                new_head = head;
                new_head->next = temp_new_head;
            }
            head = temp_old_head;
        }
        
        return new_head;
    }


//头插法 迭代法
ListNode* reverseList(ListNode* head) {
    ListNode node(0);
    ListNode* L = &node;
    L->next = NULL;

    while(head!=NULL)
    {
        ListNode* q = head->next;
        head->next = L->next;
        L->next = head;  
        head = q;
    }

    return L->next;
}