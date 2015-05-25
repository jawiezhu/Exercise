//Sort a linked list in O(n log n) time using constant space complexity.

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
	ListNode *sortList(ListNode *head)
	{
		if(!head||!head->next) return head;
		return mergeSort(head);
	}
    ListNode* mergeSort(ListNode* head) {
        if(head==NULL||head->next==NULL) return head;

        ListNode *p=head;
        ListNode *q=head;
        ListNode *pre=NULL;

        while(q&&q->next!=NULL)
        {
        	q=q->next->next;
        	pre=p;
        	p=p->next;
        }

        pre->next=NULL;

        ListNode *left=mergeSort(head);
        ListNode *right=mergeSort(p);

        return merge(left,right);
    }

    ListNode *merge(ListNode *left,ListNode *right)
    {
    	ListNode *tmp=new ListNode(0);
    	ListNode *p=tmp;
    	while(left&&right)
    	{
    		if(left->val<=right->val)
    		{
    			p->next=left;
    			left=left->next;
    		}else
    		{
    			p->next=right;
    			right=right->next;
    		}

    		p=p->next;
    	}

    		if(!left)
    			p->next=right;
    		else
    			p->next=left;

    		p=tmp->next;
    		tmp->next=NULL;
    		delete tmp;
    		return p;
    	}
    
};



//常数空间且$O(nlogn)$，单链表适合用归并排序，双向链表适合用快速排序。本题可以复用 "Merge Two Sorted Lists" 的代码。

// LeetCode, Sort List
// 归并排序，时间复杂度O(nlogn)，空间复杂度O(1)
class Solution {
public:
    ListNode *sortList(ListNode *head) {
        if (head == NULL || head->next == NULL)return head;

        // 快慢指针找到中间节点
        ListNode *fast = head, *slow = head;
        while (fast->next != NULL && fast->next->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;
        }
        // 断开
        fast = slow;
        slow = slow->next;
        fast->next = NULL;

        ListNode *l1 = sortList(head);  // 前半段排序
        ListNode *l2 = sortList(slow);  // 后半段排序
        return mergeTwoLists(l1, l2);
    }

    // Merge Two Sorted Lists
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode dummy(-1);
        for (ListNode* p = &dummy; l1 != nullptr || l2 != nullptr; p = p->next) {
            int val1 = l1 == nullptr ? INT_MAX : l1->val;
            int val2 = l2 == nullptr ? INT_MAX : l2->val;
            if (val1 <= val2) {
                p->next = l1;
                l1 = l1->next;
            } else {
                p->next = l2;
                l2 = l2->next;
            }
        }
        return dummy.next;
    }
};


//
// 解题报告：就是对一个链表进行归并排序。
// 主要考察3个知识点，
// 知识点1：归并排序的整体思想
// 知识点2：找到一个链表的中间节点的方法
// 知识点3：合并两个已排好序的链表为一个新的有序链表

// 归并排序的基本思想是：找到链表的middle节点，然后递归对前半部分和后半部分分别进行归并排序，最后对两个以排好序的链表进行Merge。
/**
 * Definition for singly-linked list.
 * class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
     //use the fast and slow pointer to get the middle of a ListNode
     ListNode getMiddleOfList(ListNode head) {
        ListNode slow = head;
        ListNode fast = head;
        while(fast.next!=null&&fast.next.next!=null) {
        	slow = slow.next;
        	fast = fast.next.next;
        }
        return slow;
    }
    
    public ListNode sortList(ListNode head) {
        if(head==null||head.next==null) {
            return head;
        }
    	ListNode middle = getMiddleOfList(head);
    	ListNode next   = middle.next;
    	    middle.next = null;
    	return mergeList(sortList(head), sortList(next));
    }
    
    //merge the two sorted list
    ListNode mergeList(ListNode a, ListNode b) {
    	ListNode dummyHead = new ListNode(-1);
    	ListNode curr = dummyHead;
    	while(a!=null&&b!=null) {
    		if(a.val<=b.val) {
    			curr.next=a;a=a.next;
    		} else {
    			curr.next=b;b=b.next;
    		}
    		curr  = curr.next;
    	}
    	curr.next = a!=null?a:b;
    	return dummyHead.next;
    }
}//

//
// 要求时间复杂度为O(nlogn)，那么不能用quickSort了（最坏O(n^2)），所以使用mergeSort.
// 通常写排序算法都是基于数组的，这题要求基于链表。所以需要自己设计函数获得middle元素，从而进行切分。
// 参考Linked List Cycle II中的“龟兔赛跑”思想：兔子前进两步，龟前进一步，从而可以获得middle元素。
class Solution {
public:
    ListNode *getMiddle(ListNode *head)
    {
        ListNode *fast = head;
        ListNode *slow = head;

        while(true)
        {
            if(fast->next != NULL)
            {
                fast = fast->next;
                if(fast->next != NULL)
                    fast = fast->next;
                else
                    break;
                slow = slow->next;
            }
            else
                break;
        }

        return slow;
    }
    ListNode *merge(ListNode *list1, ListNode *list2)
    {// merge sorted list
        ListNode *newhead = new ListNode(0);
        ListNode *head = newhead;

        while(list1 != NULL && list2 != NULL)
        {

            if(list1->val < list2->val)
            {
                newhead->next = list1;
                list1 = list1->next;
            }
            else
            {
                newhead->next = list2;
                list2 = list2->next;
            }
            newhead = newhead->next;
        }

        if(list1 == NULL)
            newhead->next = list2;
        else
            newhead->next = list1;

        return head->next;
    }
    ListNode *sortList(ListNode *head) 
    {
        if(head == NULL || head->next == NULL)
            return head;
        ListNode *mid = getMiddle(head);
        ListNode *head2 = mid->next;
        mid->next = NULL;    //attention!

        return merge(sortList(head), sortList(head2));
    }
};

//
// 对一个链表进行排序，且时间复杂度要求为 O(n log n) ，空间复杂度为常量。一看到 O(n log n) 的排序，首先应该想到归并排序和快速排序，
// 但是通常我们使用这两种排序方法时都是针对数组的，现在是链表了。
// 归并排序法：在动手之前一直觉得空间复杂度为常量不太可能，因为原来使用归并时，都是 O(N)的，需要复制出相等的空间来进行赋值归并。
// 对于链表，实际上是可以实现常数空间占用的。利用归并的思想，递归地将当前链表分为两段，然后merge，分两段的方法是使用 fast-slow 法，
// 用两个指针，一个每次走两步，一个走一步，知道快的走到了末尾，然后慢的所在位置就是中间位置，这样就分成了两段。merge时，把两段头部节点值比较，
// 用一个 p 指向较小的，且记录第一个节点，然后 两段的头一步一步向后走，p也一直向后走，总是指向较小节点，直至其中一个头为NULL，处理剩下的元素。
// 最后返回记录的头即

// 快速排序：使用快排也行，就是每次利用头节点作为基准，将小于它的交换到链表左侧，大于它的放在右侧，最后把它换到中间某个位置，
// 然后递归处理左侧和右侧。但是相对于归并来说，它的元素交换次数太多了，可能会超时。




//方法一：第一想法是模拟数组的快速排序，参考了算法导论，于是思路被牵到了如何处理交换节点上，几经波折总算实现，不过提交的结果TLE。

