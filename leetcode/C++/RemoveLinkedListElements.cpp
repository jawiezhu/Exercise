// Remove all elements from a linked list of integers that have value val.

// Example
// Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
// Return: 1 --> 2 --> 3 --> 4 --> 5

//MY ERROR
// class Solution {
// public:
//     ListNode* removeElements(ListNode* head, int val) {
//         if(head==NULL) return NULL;

//   		if(head->val==val&&head->next==NULL)
//         	return NULL;
//         if(head->val==val)
//         	head=head->next;
//         ListNode * p=head;
      
//         while(p->next)
//         {
//         	if(p->next->next==NULL&&p->next->val==val)
//         	{
//         		p->next=NULL;
//         		break;
//         	}
        	
//         	if(p->next->val==val)
//         	{
//         		p->next=p->next->next;
        		
//         	}

//         	p=p->next;
//         }

//         return head;
//     }
// };
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
    ListNode* removeElements(ListNode* head, int val) {
        if(head==NULL) return NULL;

  		
     
        ListNode * p=head;
        ListNode * q=head->next;
      
        while(q)
        {
        	if(q->val==val)
        	{
        		p->next=q->next;
        		delete q;
        		q=p->next;
        	}else{
        		p=p->next;
        		q=q->next;
        	}
        
        }

        if(head->val==val)
        {
        	p=head;
        	head=head->next;
        	delete p;
        }
        return head;
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
    ListNode* removeElements(ListNode* head, int val) {
        if (head == NULL)
        {
            return NULL;
        }

        ListNode *result = head;
        ListNode *p = head;
        while (p && p->val == val)
        {
            ListNode *temp = p;
            p = p->next;
            delete temp;
        }
        result = p;

        while (p)
        {
            if (p->next && p->next->val == val)
            {
                ListNode *temp = p->next;
                p->next = p->next->next;
                delete temp;
                continue;
            }
            p = p->next;
        }

        return result;
    }
};


//遇到val则删除，否则继续前进，直到链表结尾。
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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* newhead = new ListNode(-1);
        newhead->next = head;
        ListNode* pre = newhead;
        ListNode* cur = head;
        while(cur != NULL)
        {
            if(cur->val == val)
            {
                cur = cur->next;
                pre->next = cur;
            }
            else
            {
                pre = cur;
                cur = cur->next;
            }
        }
        return newhead->next;
    }
};

// 第一种：
// 直接两个指针pre和cur，一前一后，相互挨着，cur指针遇到val后，pre的next直接指向cur的下一个指针，同时cur也向后移动一个。
// 第二种：
// 把指定的元素看成雷区，cur指针进入雷区后，pre停止并等待cur出雷区，同时pre的next指针指向出雷区的第一个元素。但是这种方法得有一个是否进入雷区的标志，但是我觉得可以优化。
// 第三种方法：
// 优雅的递归调用
ListNode* removeElements(ListNode* head, int val) 
{
	ListNode *pre;
	ListNode *cur;
	ListNode *temp;
	
	pre = head;
	while(pre != NULL && pre->val == val)
	{
		temp = pre;
		pre = pre->next;
		delete temp;
	}
	if(pre == NULL)
	{
		return NULL;
	}
	
	head = pre;
	cur = pre->next;
	while(cur != NULL)
	{
		if(cur->val == val)
		{
			temp = cur;
			pre->next = cur->next;
			delete temp;
		}
		else
		{
			pre = cur;
		}
		cur = cur->next;
	}//while
	
	return head;
}

ListNode* removeElements(ListNode* head, int val) 
{
	ListNode *temp = NULL;
	if(head && head->val == val)
	{
		temp = head;
		head = removeElements(head->next, val);
		delete temp;
	}
	if(head && head->next)
	{
		head->next = removeElements(head->next, val);
	}

	return head;
}



/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode removeElements(ListNode head, int val) {
        ListNode dummy = new ListNode(0);
        dummy.next = head;
        ListNode p = dummy;
        ListNode q = head;
        while(q!=null) {
            if(q.val == val) {
                p.next = q.next;
            } else {
                p = p.next;
            }
            q = q.next;
        }
        
        return dummy.next;
    }
}