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




// 最容易想到的方法是，用一个哈希表{unordered_map<int, bool> visited}，
// 记录每个元素是否被访问过，一旦出现某个元素被重复访问，说明存在环。
// 空间复杂度$O(n)$，时间复杂度$O(N)$。
//LeetCode, Linked List Cycle
// 时间复杂度O(n)，空间复杂度O(1)
class Solution {
public:
    bool hasCycle(ListNode *head) {
        // 设置两个指针，一个快一个慢
        ListNode *slow = head, *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) return true;
        }
        return false;
    }
};
