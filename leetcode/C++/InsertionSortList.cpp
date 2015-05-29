// Sort a linked list using insertion sort.

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
    ListNode *insertionSortList(ListNode *head) {
        if(head==NULL)
        {
            return NULL;
        }
        else
        {
            ListNode* cur = head->next;
            head->next = NULL;
            while(cur!=NULL)
            {
                ListNode* p = head;
                if(cur->val < p->val)
                {
                    head = cur;
                    cur=cur->next;
                    head->next=p;
                }
                else
                {
                    while(p!=NULL)
                    {
                        if(p->next ==NULL)
                        {
                            p->next = cur;
                            cur=cur->next;
                            p->next->next = NULL;
                            break;
                        }
                        else
                        {
                            if(cur->val < p->next->val)
                            {
                                ListNode* tmp = p->next;
                                p->next = cur;
                                cur=cur->next;
                                p->next->next = tmp;
                                break;
                            }
                            p=p->next;
                        }
                    }
                }
            }
            return head;
        }
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
    ListNode *insertionSortList(ListNode *head) {
        ListNode* p = head;
        ListNode* result = new ListNode(0);
        while(p != NULL){
            ListNode* cur = p;
            p = p->next;
            insertSort(result, cur);
        }
        return result->next;
    }
    
    void insertSort(ListNode* head, ListNode* newNode){
        while(head->next != NULL){
            if(newNode->val < head->next->val){
                newNode->next = head->next;
                head->next = newNode;
                return;
            }
            head = head->next;
        }
        
        if(head->next == NULL){
            head->next = newNode;
            newNode->next = NULL;
        }
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
    ListNode *insertionSortList(ListNode *head) {
        if (head == nullptr) return head;
        
        ListNode* curr = head -> next;
        head -> next = nullptr;
        
        while(curr != nullptr){
            ListNode* tmpHead = head;
            ListNode* prev = nullptr;
            ListNode* next = curr -> next;
            while(tmpHead != nullptr && tmpHead -> val <= curr -> val)
            {
                prev = tmpHead;
                tmpHead = tmpHead -> next;
            }
            
            if(prev != nullptr){
                //insert
                if(prev -> next){
                    curr -> next = prev -> next;
                    prev -> next = curr;
                }else
                {
                    prev -> next = curr;
                    curr -> next = nullptr;
                }
            }else{
                curr -> next = head;
                head = curr;
            }
            curr = next;
        }
        return head;
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
    ListNode *insertionSortList(ListNode *head) {
        if (head == nullptr) return head;
        ListNode* sort_head = head;
        ListNode* prev = nullptr;
        head = head->next;
        sort_head->next = nullptr;
        while(head) {
            prev = nullptr;
            ListNode* tmp = sort_head;
            ListNode* now = head;
            ListNode* next = head->next;
            while(tmp) {
                if (tmp->val > now->val) break;
                prev = tmp;
                tmp = tmp->next;
            }
            if (prev) {
                ListNode* next = prev->next;
                prev->next = now;
                now->next = next;
            } else {
                now->next = sort_head;
                sort_head = now;
            }
            head = next;
        }
        return sort_head;
    }
};


//
ListNode *insertionSortList(ListNode *head) {
        if(head == NULL) return head;
        ListNode *p = new ListNode(-1);
        p->next = head;
        ListNode *pre = head;
        ListNode *cur = pre->next;
        while(cur){
            
            if(cur->val >= pre->val){
                pre = cur;
                cur = cur->next;
            }else{
                ListNode *insertPre = p;
                ListNode *insertCur = p->next;
                while(insertCur->val < cur->val){
                    insertPre = insertCur;
                    insertCur = insertCur->next;
                }
                pre->next = cur->next;
                cur->next = insertCur;
                insertPre->next = cur;
                cur = pre->next;
            }
            
        }
        head = p->next;
        return head;
    }

//
    //题目要求我们用插入排序来实现链表排序。我们构建一个当前排好序的链表，然后维护一个变量，不断指向链表中的下一个节点。
    //用变量cur表示当前要插入的节点，每次循环找到cur节点在当前排好序的链表中对应的位置，然后插入进去，
    //然后指向原链表中下一个节点，继续进行插入过程，直到原链表的所有节点都完成，既经过N次迭代后，就得到了排序好的结果。
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
    ListNode *insertionSortList(ListNode *head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode* dummyhead = new ListNode(0);
        ListNode* pre = dummyhead;
        ListNode* cur = head;
        
        while(cur != NULL)
        {
            ListNode* next = cur->next;  //维护链表的下一个结点
            pre = dummyhead;             //重置pre为新链表头开始
            
            //在当前排好的新链表中找到第一个大于cur->val的结点
            while(pre->next != NULL && pre->next->val <= cur->val)
            {
                pre = pre->next;
            }
            
            //当前pre的next结点的值大于cur的值,将cur插入到pre后
            cur->next = pre->next;
            pre->next = cur;
            cur = next;   //cur指向原链表的下一个节点
        }
        return dummyhead->next;
    }
};


//
ListNode *insertionSortList(ListNode *head) {
    ListNode *p = head;
    ListNode *q = head;
    ListNode *pre = NULL;
    if(!p || !p->next) return head;
    
    q = q->next;
    head->next = NULL;
    while(q){
        int v = q->val;
        p = head;
        ListNode *r = q->next;
        pre = NULL;//每轮开始pre都为空 
        while(p && p->val < v){
            pre = p;
            p = p->next;
        }
        if(pre){
            q->next = pre->next;
            pre->next = q;
        }
        else{
            q->next = p;
            head = q;//新节点放在第一位，调整head 
        }
        q = r;
    }
    p = head;
    return p;
}

//


//链表排序
class Solution {
public:
    ListNode *insertionSortList(ListNode *head) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if(head == NULL || head->next == NULL)return head;
        ListNode *p = head->next, *pstart = new ListNode(0), *pend = head;
        pstart->next = head; //为了操作方便，添加一个头结点
        while(p != NULL)
        {
            ListNode *tmp = pstart->next, *pre = pstart;
            while(tmp != p && p->val >= tmp->val) //找到插入位置
                {tmp = tmp->next; pre = pre->next;}
            if(tmp == p)pend = p;
            else
            {
                pend->next = p->next;
                p->next = tmp;
                pre->next = p;
            }
            p = pend->next;
        }
        head = pstart->next;
        delete pstart;
        return head;
    }
};

class Solution {
public:
    ListNode *selectSortList(ListNode *head) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        //选择排序
        if(head == NULL || head->next == NULL)return head;
        ListNode *pstart = new ListNode(0);
        pstart->next = head; //为了操作方便，添加一个头结点
        ListNode*sortedTail = pstart;//指向已排好序的部分的尾部
             
        while(sortedTail->next != NULL)
        {
            ListNode*minNode = sortedTail->next, *p = sortedTail->next->next;
            //寻找未排序部分的最小节点
            while(p != NULL)
            {
                if(p->val < minNode->val)
                    minNode = p;
                p = p->next;
            }
            swap(minNode->val, sortedTail->next->val);
            sortedTail = sortedTail->next;
        }
             
        head = pstart->next;
        delete pstart;
        return head;
    }
};

//
void quicksort(vector<int>&arr, int low, int high)
     
{
     
  if(low < high)
     
  {
     
   int middle = mypartition(arr, low, high);
     
   quicksort(arr, low, middle-1);
     
   quicksort(arr, middle+1, high);
     
  }
     
}

class Solution {
public:
    ListNode *quickSortList(ListNode *head) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        //链表快速排序
        if(head == NULL || head->next == NULL)return head;
        qsortList(head, NULL);
        return head;
    }
    void qsortList(ListNode*head, ListNode*tail)
    {
        //链表范围是[low, high)
        if(head != tail && head->next != tail)
        {
            ListNode* mid = partitionList(head, tail);
            qsortList(head, mid);
            qsortList(mid->next, tail);
        }
    }
    ListNode* partitionList(ListNode*low, ListNode*high)
    {
        //链表范围是[low, high)
        int key = low->val;
        ListNode* loc = low;
        for(ListNode*i = low->next; i != high; i = i->next)
            if(i->val < key)
            {
                loc = loc->next;
                swap(i->val, loc->val);
            }
        swap(loc->val, low->val);
        return loc;
    }
};

class Solution {
public:
    ListNode *quickSortList(ListNode *head) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        //链表快速排序
        if(head == NULL || head->next == NULL)return head;
        ListNode tmpHead(0); tmpHead.next = head;
        qsortList(&tmpHead, head, NULL);
        return tmpHead.next;
    }
    void qsortList(ListNode *headPre, ListNode*head, ListNode*tail)
    {
        //链表范围是[low, high)
        if(head != tail && head->next != tail)
        {
            ListNode* mid = partitionList(headPre, head, tail);//注意这里head可能不再指向链表头了
            qsortList(headPre, headPre->next, mid);
            qsortList(mid, mid->next, tail);
        }
    }
    ListNode* partitionList(ListNode* lowPre, ListNode* low, ListNode* high)
    {
        //链表范围是[low, high)
        int key = low->val;
        ListNode node1(0), node2(0);//比key小的链的头结点，比key大的链的头结点
        ListNode* little = &node1, *big = &node2;
        for(ListNode*i = low->next; i != high; i = i->next)
            if(i->val < key)
            {
                little->next = i;
                little = i;
            }
            else
            {
                big->next = i;
                big = i;
            }
        big->next = high;//保证子链表[low,high)和后面的部分连接
        little->next = low;
        low->next = node2.next;
        lowPre->next = node1.next;//为了保证子链表[low,high)和前面的部分连接
        return low;
    }
};

//

class Solution {
public:
    ListNode *mergeSortList(ListNode *head) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        //链表归并排序
        if(head == NULL || head->next == NULL)return head;
        else
        {
            //快慢指针找到中间节点
            ListNode *fast = head,*slow = head;
            while(fast->next != NULL && fast->next->next != NULL)
            {
                fast = fast->next->next;
                slow = slow->next;
            }
            fast = slow;
            slow = slow->next;
            fast->next = NULL;
            fast = sortList(head);//前半段排序
            slow = sortList(slow);//后半段排序
            return merge(fast,slow);
        }
              
    }
    // merge two sorted list to one
    ListNode *merge(ListNode *head1, ListNode *head2)
    {
        if(head1 == NULL)return head2;
        if(head2 == NULL)return head1;
        ListNode *res , *p ;
        if(head1->val < head2->val)
            {res = head1; head1 = head1->next;}
        else{res = head2; head2 = head2->next;}
        p = res;
              
        while(head1 != NULL && head2 != NULL)
        {
            if(head1->val < head2->val)
            {
                p->next = head1;
                head1 = head1->next;
            }
            else
            {
                p->next = head2;
                head2 = head2->next;
            }
            p = p->next;
        }
        if(head1 != NULL)p->next = head1;
        else if(head2 != NULL)p->next = head2;
        return res;
    }
};

//
class Solution {
public:
    ListNode *bubbleSortList(ListNode *head) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        //链表快速排序
        if(head == NULL || head->next == NULL)return head;
        ListNode *p = NULL;
        bool isChange = true;
        while(p != head->next && isChange)
        {
            ListNode *q = head;
            isChange = false;//标志当前这一轮中又没有发生元素交换，如果没有则表示数组已经有序
            for(; q->next && q->next != p; q = q->next)
            {
                if(q->val > q->next->val)
                {
                    swap(q->val, q->next->val);
                    isChange = true;
                }
            }
            p = q;
        }
        return head;
    }
};

//


