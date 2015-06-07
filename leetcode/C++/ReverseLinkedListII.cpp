// Reverse a linked list from position m to n. Do it in-place and in one-pass.

// For example:
// Given 1->2->3->4->5->NULL, m = 2 and n = 4,

// return 1->4->3->2->5->NULL.

// Note:
// Given m, n satisfy the following condition:
// 1 ≤ m ≤ n ≤ length of list.

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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(head==NULL||m<0||n<0) return head;
        if(head->next==NULL||m==n) return head;

        ListNode *p=head;
        int i=1;

        while(i<m)
        {
        	p=p->next;
        	i++;
        }

        for(int j=m;j<n;j++)
        {
        	ListNode *q=p;
        	for(int k=j;k<n;k++)
        	{
        		q=q->next;
        	}
        	swap(p->val,q->val);

        	n--;
        	p=p->next;
        }

        return head;

    }
};


// LeetCode, Reverse Linked List II
// 迭代版，时间复杂度O(n)，空间复杂度O(1)
class Solution {
public:
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        ListNode dummy(-1);
        dummy.next = head;

        ListNode *prev = &dummy;
        for (int i = 0; i < m-1; ++i)
            prev = prev->next;
        ListNode* const head2 = prev;

        prev = head2->next;
        ListNode *cur = prev->next;
        for (int i = m; i < n; ++i) {
            prev->next = cur->next;
            cur->next = head2->next;
            head2->next = cur;  // 头插法
            cur = prev->next;
        }

        return dummy.next;
    }
};


//
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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (head == NULL)
            return NULL;
            
        ListNode *q = NULL;
        ListNode *p = head;
        for(int i = 0; i < m - 1; i++)
        {
            q = p;
            p = p->next;
        }
        
        ListNode *end = p;
        ListNode *pPre = p;
        p = p->next;
        for(int i = m + 1; i <= n; i++)
        {
            ListNode *pNext = p->next;
            
            p->next = pPre;
            pPre = p;
            p = pNext;
        }
        
        end->next = p;
        if (q)
            q->next = pPre;
        else
            head = pPre;
        
        return head;
    }
};



//=====================
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
    public ListNode reverseBetween(ListNode head, int m, int n) {
        ListNode newHead = new ListNode(0);
        newHead.next = head;
        
        ListNode prevNode = getMthNode(newHead, m);
        ListNode current = prevNode.next;
        ListNode tail = prevNode.next;
        int count = 1;
        
        ListNode prev = null;
        ListNode next = null;
        while (count <= (n - m + 1)) {
            next = current.next;
            current.next = prev;
            prev = current;
            current = next;
            count++;
        }
        prevNode.next = prev;
        tail.next = next;        
        
        return newHead.next;
    }
    
    public ListNode getMthNode(ListNode newHead, int m) {
        for (int i = 1; i < m; i++) {
            newHead = newHead.next;
        }
        return newHead;
    }
}//

//==================
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
    ListNode *reverse(ListNode* start){
        ListNode* prev = nullptr;
        ListNode* now = start;
        while(now != nullptr){
            ListNode* next = now -> next;
            now -> next = prev;
            prev = now;
            now = next;
        }
        return prev;
    }
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        if(m == n) return head;
        if(head == nullptr) return head;
        
        int cnt = 1;
        ListNode* prev = nullptr;
        ListNode* breakNode = head;
        // m is head
        while(cnt < m){
            prev = breakNode;
            breakNode = breakNode -> next;
            cnt ++;
        }
        ListNode* last = breakNode;
        cnt = n - m; // pre of last
        //last is tail
        while(cnt > 0){
            last = last -> next;
            cnt --;
        }
        //do reverse
        ListNode* next = last -> next;
        last -> next = nullptr;
        ListNode * newList = reverse(breakNode);
        if(prev){
            prev -> next = newList;
        }else{
            head = newList;
        }
        breakNode -> next = next;
        return head;
    }
};

//
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
    // Divide the list to three parts: 
    // 1)Nodes before m keep still; 
    // 2)Traverse m~n nodes;
    // 3)Nodes after n keep still.
    public ListNode reverseBetween(ListNode head, int m, int n) {
        if (m == n) return head;
        
        ListNode preHead = new ListNode(0);
        preHead.next = head;
        
        // The (m-1) node is the tail of first tail.
        ListNode firstTail = preHead;
        int k = m - 1;
        while (k-- > 0) {
            firstTail = firstTail.next;
        }
        
        // The m-th node is the traversed tail.
        ListNode secondTail = firstTail.next;
        
        // Traverse m~n nodes, and get the traversed head.
        ListNode tmpHead = null;
        ListNode tmpNext = null;
        ListNode node = firstTail.next;
        k = n - m + 1;
        while (k-- > 0) {
            tmpHead = node;
            node = node.next;
            
            tmpHead.next = tmpNext;
            tmpNext = tmpHead;
        }
        
        // Connect three parts.
        firstTail.next = tmpHead;
        secondTail.next = node;
        
        return preHead.next;
    }
}//

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
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return head;
        else if(head->next->next == NULL)
        {
            ListNode* newhead = head->next;
            newhead->next = head;
            head->next = NULL;
            return newhead;
        }
        else
        {
            ListNode* pre = head;
            ListNode* cur = pre->next;
            pre->next = NULL;
            ListNode* post = cur->next;
            
            while(post != NULL)
            {
                cur->next = pre;
                pre = cur;
                cur = post;
                post = post->next;
            }
            cur->next = pre;
            return cur;
        }
    }
};

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
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return head;
        ListNode* newhead = head;
        while(newhead->next != NULL)
            newhead = newhead->next;
        reverse(head);
        return newhead;
    }
    ListNode* reverse(ListNode* head)
    {
        if(head->next == NULL)
            return head;
        else
        {
            ListNode* tail = reverse(head->next);
            tail->next = head;
            tail = tail->next;
            tail->next = NULL;
            return tail;
        }
    }
};


