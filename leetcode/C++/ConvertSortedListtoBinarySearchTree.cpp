//Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
	int listlen(ListNode * node)
	{
		int len=0;
		while(node)
		{
			++len;
			node=node->next;
		}
		return len;
	}

	TreeNode * createBST(ListNode *node,int left,int right)
	{
		if(left>right) return NULL;

		int mid=(left+right)/2;

		ListNode *p=node;

		for(int i=left;i<mid;i++)
			p=p->next;

		TreeNode *leftNode=createBST(node,left,mid-1);
		TreeNode *rightNode=createBST(p->next,mid+1,right);

		TreeNode *root=new TreeNode(p->val);
		root->left=leftNode;
		root->right=rightNode;

		return root;
	}

    TreeNode* sortedListToBST(ListNode* head) {
        int len=listlen(head);
        return createBST(head,0,len-1);
    }
};

// 找出当前链表的中间节点，然后再递归左右的子链表，
// 开始的时候程序先计算链表总厂，然后传入两个前后索引指针，最后每次递归找出中间节点即可。

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode *sortedListToBST(ListNode *head) {
        if(head == NULL)
            return NULL;
        else if(head->next == NULL)
            return new TreeNode(head->val);
        ListNode* mid = findMid(head);
        TreeNode* root = new TreeNode(mid->val);
        root->left = sortedListToBST(head);
        root->right = sortedListToBST(mid->next);
        return root;
    }
    ListNode* findMid(ListNode* head)
    {
        ListNode* preslow = NULL;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != NULL)
        {
            fast = fast->next;
            if(fast != NULL)
            {
                fast = fast->next;
                preslow = slow;
                slow = slow->next;
            }
        }
        //break the list into two parts
        preslow->next = NULL;
        return slow;
    }
};



//深度搜索的顺序恰巧是链表的顺序，通过设置好递归函数的参数，可以在深度搜索时候便可以遍历了。
class Solution {
public:
    TreeNode *sortedListToBST(ListNode *head) {
        int len=0;
        ListNode * p = head;
        while(p!=NULL){
            len++;
            p=p->next;
        }
//        cout<<len<<endl;
        return help_f(head,0,len-1);
    }

    TreeNode * help_f(ListNode *&curList,int lft,int rgt)
    {
        if(lft>rgt) return  NULL;
        int mid=(lft+rgt)/2;
        TreeNode *lftCld = help_f(curList,lft,mid-1);
        TreeNode *parent =new TreeNode(curList->val);
        parent->left=lftCld;
        curList=curList->next;
        parent->right=help_f(curList,mid+1,rgt);
        return parent;
    }
};

// 有了前面的Convert Sorted Array List to Binary Search Tree那道题的启发，
// 总的思路就是，把这个LinkedList先放到一个ArrayList里面去，然后和那道题的解法就一样了：
public class Solution {
    public TreeNode sortedListToBST(ListNode head) {
        if (null==head)
            return null;
            
        List<TreeNode> list = new ArrayList<>();
        ListNode node = head;
        while(node!=null) {
            TreeNode n = new TreeNode(node.val);
            list.add(n);
            node = node.next;
        }
        
        return buildTree(0, list.size()-1, list);
    }
    
    private TreeNode buildTree(int start, int end, List<TreeNode> list) {
        int mid = (start+end)/2;
        TreeNode root = list.get(mid);
        if (start<=mid-1)
            root.left = buildTree(start, mid-1, list);
        if (end>=mid+1)
            root.right = buildTree(mid+1, end, list);
        
        return root;
    }
}//

//单链表不能随机访问，而自顶向下的二分法必须需要RandomAccessIterator，因此前面的方法不适用本题。
// LeetCode, Convert Sorted List to Binary Search Tree
// 分治法，类似于 Convert Sorted Array to Binary Search Tree，
// 自顶向下，时间复杂度O(n^2)，空间复杂度O(logn)
class Solution {
public:
    TreeNode* sortedListToBST (ListNode* head) {
        return sortedListToBST (head, listLength (head));
    }

    TreeNode* sortedListToBST (ListNode* head, int len) {
        if (len == 0) return nullptr;
        if (len == 1) return new TreeNode (head->val);

        TreeNode* root = new TreeNode (nth_node (head, len / 2 + 1)->val);
        root->left = sortedListToBST (head, len / 2);
        root->right = sortedListToBST (nth_node (head, len / 2 + 2), 
                (len - 1) / 2);

        return root;
    }

    int listLength (ListNode* node) {
        int n = 0;

        while(node) {
            ++n;
            node = node->next;
        }

        return n;
    }

    ListNode* nth_node (ListNode* node, int n) {
        while (--n)
            node = node->next;

        return node;
    }
};


// LeetCode, Convert Sorted List to Binary Search Tree
// bottom-up，时间复杂度O(n)，空间复杂度O(logn)
class Solution {
public:
    TreeNode *sortedListToBST(ListNode *head) {
        int len = 0;
        ListNode *p = head;
        while (p) {
            len++;
            p = p->next;
        }
        return sortedListToBST(head, 0, len - 1);
    }
private:
    TreeNode* sortedListToBST(ListNode*& list, int start, int end) {
        if (start > end) return nullptr;

        int mid = start + (end - start) / 2;
        TreeNode *leftChild = sortedListToBST(list, start, mid - 1);
        TreeNode *parent = new TreeNode(list->val);
        parent->left = leftChild;
        list = list->next;
        parent->right = sortedListToBST(list, mid + 1, end);
        return parent;
    }
};


