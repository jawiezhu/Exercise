// Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

// You should preserve the original relative order of the nodes in each of the two partitions.

// For example,
// Given 1->4->3->2->5->2 and x = 3,
// return 1->2->2->4->3->5.

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
    ListNode* partition(ListNode* head, int x) {
        if(head==NULL) return NULL;

        ListNode * less=new ListNode(0);
        ListNode * greater=new ListNode(0);
        ListNode * greaterhead=greater;
        ListNode * lesshead=less;
        ListNode * p=head;

        while(p)
        {
        	if(p->val<x)
        	{
        		less->next=p;
        		p=p->next;
        		less=less->next;
        		less->next=NULL;
        	}

        	else //if(p->val>=x) 不能这么写，不然 上面 p指向空了 就无法判断是否大于x
        	{
        		greater->next=p;
        		p=p->next;
        		greater=greater->next;
        		greater->next=NULL;
        	}
        }

        less->next=greaterhead->next;
        return lesshead->next;
    }
};




// LeetCode, Partition List
// 时间复杂度O(n)，空间复杂度O(1)
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode left_dummy(-1); // 头结点
        ListNode right_dummy(-1); // 头结点

        auto left_cur = &left_dummy;
        auto right_cur = &right_dummy;

        for (ListNode *cur = head; cur; cur = cur->next) {
            if (cur->val < x) {
                left_cur->next = cur;
                left_cur = cur;
            } else {
                right_cur->next = cur;
                right_cur = cur;
            }
        }

        left_cur->next = right_dummy.next;
        right_cur->next = nullptr;

        return left_dummy.next;
    }
};



//1. 空间复杂度为 o(n) 解法. 创建两个链表, 分别记录大于 x 和小于 x 的节点, 最后合并
//2. o(1) 的空间复杂度解法. 四个指针, 分别指向小于 x 部分链表的头, 尾, 
//指向大于 x 部分链表的头, 尾
//使用 dummyNode 减少判断
class Solution {
public:
    ListNode *partition(ListNode *head, int x) {
        ListNode *first, *second, *third, *fourth;
        if(head == NULL)
            return head;
 
        ListNode *cursor = head;
        ListNode *dummyNode = new ListNode(0);
        dummyNode->next = head;
        first = second =  dummyNode;
        while(cursor && cursor->val < x) {
            second = cursor;
            cursor = cursor->next;
        }
        if(cursor && cursor->val >= x) {
            third = cursor;
            fourth = cursor;
        }
        while(cursor) {
            if(cursor->val < x) {
                second->next = cursor;
                fourth->next = cursor->next;
                cursor->next = third;
                second = cursor;
            }else{
                fourth = cursor;
            }
            cursor = cursor->next;
        }
        return dummyNode->next;
    }
};





