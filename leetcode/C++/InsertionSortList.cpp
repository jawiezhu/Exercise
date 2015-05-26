//Sort a linked list using insertion sort.

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
    ListNode* insertionSortList(ListNode* head) {
        ListNode *newhead=new ListNode(-1);
        while(head!=NULL)
        {
        	//保存head位置
        	ListNode *tmp=head->next;
        	ListNode *cur=newhead;

        	while(cur->next!=NULL&&cur->next->val<head->val)
        	{
        		cur=cur->next;
        	}
        	//插入
        	head->next=cur->next;
        	cur->next=head;
        	//恢复head
        	head=tmp;
        }

        return newhead->next;
    }
};

//本题是插入排序的链表版本。
//传统数组版本做法就是两重循环，第一重是遍历所有元素，第二重是遍历已排序部分进行插入。
//链表版本类似，在遍历每个元素过程中，遍历已排序部分进行插入。



// LeetCode, Insertion Sort List
// 时间复杂度O(n^2)，空间复杂度O(1)
class Solution {
public:
    ListNode *insertionSortList(ListNode *head) {
        ListNode dummy(INT_MIN);
        //dummy.next = head;

        for (ListNode *cur = head; cur != nullptr;) {
            auto pos = findInsertPos(&dummy, cur->val);
            ListNode *tmp = cur->next;
            cur->next = pos->next;
            pos->next = cur;
            cur = tmp;
        }
        return dummy.next;
    }

    ListNode* findInsertPos(ListNode *head, int x) {
        ListNode *pre = nullptr;
        for (ListNode *cur = head; cur != nullptr && cur->val <= x;
            pre = cur, cur = cur->next)
            ;
        return pre;
    }
};


