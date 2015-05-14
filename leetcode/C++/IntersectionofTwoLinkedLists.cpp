// Write a program to find the node at which the intersection of two singly linked lists begins.


// For example, the following two linked lists:

// A:          a1 → a2
//                    ↘
//                      c1 → c2 → c3
//                    ↗            
// B:     b1 → b2 → b3
// begin to intersect at node c1.


// Notes:

// If the two linked lists have no intersection at all, return null.
// The linked lists must retain their original structure after the function returns.
// You may assume there are no cycles anywhere in the entire linked structure.
// Your code should preferably run in O(n) time and use only O(1) memory.


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//  可以将A,B两个链表看做两部分，交叉前与交叉后。

// 交叉后的长度是一样的，因此交叉前的长度差即为总长度差。

// 只要去除这些长度差，距离交叉点就等距了。

// 为了节省计算，在计算链表长度的时候，顺便比较一下两个链表的尾节点是否一样，

// 若不一样，则不可能相交，直接可以返回NULL
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA==NULL||headB==NULL) return NULL;

        int lenA=1;
        ListNode * curA=headA;
        while(curA->next)
        {
        	lenA++;
        	curA=curA->next;
        }

        int lenB=1;
        ListNode * curB=headB;
        while(curB->next)
        {
        	lenB++;
        	curB=curB->next;
        }

        //curA and curB is in the tail of the list.
        if(curA!=curB)
        	return NULL;
        else
        {
        	int diff=lenA-lenB;
        	//
        	if(diff>0)
        	{//A
        		while(diff)
        		{
        			headA=headA->next;
        			diff--;
        		}
        	}
        	else
        	{//B
        		while(diff)
        		{
        			headB=headB->next;
        			diff++;
        		}
        	}

        	while(1)
        	{//A and B
        		if(headA==headB)
        			return headA;
        		else
        		{
        			headA=headA->next;
        			headB=headB->next;
        		}
        	}
        }
    }
};


// 解题思路:
// 1.首先想到的是哈希，先将一个链表中结点都插入字典中，
// 然后遍历另一个链表中的结点看是否有结点在字典中;但这种方法需要开辟较大的内存空间来存储字典；
// 2.双指针法.首先对其中一个链表头尾连接.
// 那么问题就变成了看另一个链表是否存在环的问题了.但这种方法改变了原本链表的结构，需要在最后对其还原；
// 3.先计算两个链表的长度差，然后对长链表头结点开始移动长度差长的结点,找到位置对应的结点.然后逐个比较是否相等;


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
// public class Solution {
//     public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
//         if(headA == null ||headB == null)return null;
//         ListNode h1 = headA;
//         ListNode h2 = headB;
//         int count1 = 1, count2 = 1;
//         while(h1.next != null){
//             count1++;
//             h1 = h1.next;
//         }
//         while(h2.next != null){
//             count2++;
//             h2 = h2.next;
//         }
//         if(h1 != h2) return null;
//         else{
//             int count = Math.abs(count1 - count2);
//             if(count2 > count1){
//                 h1 = headB;
//                 h2 = headA; 
//             }
//             else{
//                 h1 = headA;
//                 h2 = headB;
//             }
//             while((count--) > 0){
//                 h1 = h1.next;
//             }
//             while(h1 != null&&h2 != null && h1 != h2){
//                 h1 = h1.next;
//                 h2 = h2.next;
//             }
//             return h1;
//         }
//     }
// }

// 两个单项链表，判断是否存在交集，如上图很清晰，最直观的方法是
// for  list1 begin to last
// 　　for list2 begin to last
// 　　　　if list2==list1 success
// 　　end
// end　　
//     时间是O(nm)，空间挺少的O(1)。如何提高呢？
// 遍历list1 ，将其节点存在hash_table
// 遍历list2，如果已经在hash_table中，那么存在
//     利用hash_table 可以提升时间到O(n+m)，可是空间变O(n)了
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_map<ListNode*,int> m;
        while(headA!=NULL){
            m[headA] = 1;
            headA=headA->next;
        }
        while(headB!=NULL){
            if(m[headB]==1) return headB;
            headB=headB->next;
        }
        return NULL;
    }
};

// list1:    O O O O O ⑴ ⑵ ⑶
// list2:    □ □ □ □ ⑴ ⑵ ⑶
// 　　假如list 如上，⑴ ⑵ ⑶ 为相同的节点，那么遍历list1 这样便是这样：
// O O O O O ⑴ ⑵ ⑶ □ □ □ □ ⑴ ⑵ ⑶
// 　　遍历list2 便是这样。
// □  □ □ □ ⑴ ⑵ ⑶ O O O O O ⑴ ⑵ ⑶
 
// 合在一起看看：
// O　　O　　O　　O　　O　　⑴　　⑵　　⑶　　□　　 □　　□　　□　　 ⑴　　⑵　　⑶
// □　　 □　　□ 　　□　　⑴　　⑵　　⑶　　O　　O　　O　　O　　O　　⑴　　⑵　　⑶
 
//     好了，现在规律出来了。这个逻辑出来明显，主要麻烦是在遍历一个结束后接上第二个，直接改链表不好，所以，使用flag 控制。
// 算法逻辑：
// 判断list 是否有NULL 情况
// 同时遍历 两个新链表
// 如果节点地址相同，返回
// 如果不相同继续遍历
// 遍历结束返回NULL
#include <iostream>
#include <unordered_map>
using namespace std;

/**
 * Definition for singly-linked list.
 */
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

/**
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_map<ListNode*,int> m;
        while(headA!=NULL){
            m[headA] = 1;
            headA=headA->next;
        }
        while(headB!=NULL){
            if(m[headB]==1) return headB;
            headB=headB->next;
        }
        return NULL;
    }
};
*/
class Solution{
public:
    ListNode* getIntersectionNode(ListNode *headA,ListNode * headB)
    {
        ListNode * h1=headA;
        ListNode * h2=headB;
        if(headA==NULL||headB==NULL)    return NULL;
        bool flag1=true,flag2=true;
        while(headA!=NULL&&headB!=NULL){
            if(headA==headB)    return headA;
            headA=headA->next;
            headB=headB->next;
            if(headA==NULL&&flag1){ headA=h2;   flag1 =false;}
            if(headB==NULL&&flag2){ headB=h1;   flag2 =false;}
        }
        return NULL;
    }
};

int main()
{
    ListNode head1(1);
    ListNode head2(2);
    ListNode node1(3);
    ListNode node2(4);
    head1.next = &node1;
    node1.next = &node2;
    head2.next = &node2;
    Solution sol;
    ListNode *ret = sol.getIntersectionNode(&head1,&head2);
    if(ret==NULL)   cout<<"NULL"<<endl;
    else    cout<<ret->val<<endl;
    return 0;
}