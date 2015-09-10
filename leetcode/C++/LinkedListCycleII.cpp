// Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

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
    ListNode *detectCycle(ListNode *head) {
        if(head==NULL||head->next==NULL) return NULL;
        ListNode *p=head;
        ListNode *q=head;
        while(p->next&&p->next->next)
        {
            q=q->next;
            p=p->next->next;
            if(q==p)
            {
                q=head;
                while(q!=p)
                {
                    p=p->next;
                    q=q->next;
                }
                
                return q;
            }
        }
        
        return NULL;
    }
};


// 当fast与slow相遇时，

// slow肯定没有遍历完链表，而fast已经在环内循环了$n$圈($1 \leq n$)。假设slow走了$s$步，
// 则fast走了$2s$步（fast步数还等于$s$加上在环上多转的$n$圈），设环长为$r$，则：

// 2s=s+nr
// s=nr
// 设整个链表长$L$，环入口点与相遇点距离为$a$，起点到环入口点的距离为$x$，则

// x+ax=nr=(n–1)r+r=(n−1)r+L–x
// x=(n−1)r+(L–x–a)
// $L – x – a$为相遇点到环入口点的距离，由此可知，从链表头到环入口点等于$n-1$圈内环+相遇点到环入口点，

// 于是我们可以从{head}开始另设一个指针{slow2}，两个慢指针每次前进一步，它俩一定会在环入口点相遇。

//LeetCode, Linked List Cycle II
// 时间复杂度O(n)，空间复杂度O(1)
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head, *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                ListNode *slow2 = head;

                while (slow2 != slow) {
                    slow2 = slow2->next;
                    slow = slow->next;
                }
                return slow2;
            }
        }
        return nullptr;
    }
};


