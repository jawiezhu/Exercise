// Follow up for problem "Populating Next Right Pointers in Each Node".

// What if the given tree could be any binary tree? Would your previous solution still work?

// Note:

// You may only use constant extra space.
// For example,
// Given the following binary tree,
//          1
//        /  \
//       2    3
//      / \    \
//     4   5    7
// After calling your function, the tree should look like:
//          1 -> NULL
//        /  \
//       2 -> 3 -> NULL
//      / \    \
//     4-> 5 -> 7 -> NULL



/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(root==NULL) return ;

        TreeLinkNode * p=root;
        TreeLinkNode * q=NULL;
        TreeLinkNode * nextNode=NULL;

        while(p)
        {
        	if(p->left)
        	{
        		if(q)
        			q->next=p->left;
        		q=p->left;
        		if(nextNode==NULL)
        			nextNode=q;
        	}

        	if(p->right)
        	{
        		if(q)
        			q->next=p->right;
        		q=p->right;
        		if(nextNode==NULL)
        			nextNode=q;
        	}

        	p=p->next;
        }

       	connect(nextNode);
    }
};


//
// 用O（1）的空间

// 那就利用next节点，一层一层的来遍历好了
// 首先是root，我们把它的left和right连起来
// 然后root切换到下一层

// 然后遍历下一层的每个节点（因为next连了的
// 再分别把他们的left，right什么的连起来

// 用两个变量就ok了
// 一个prev记录当前层前一节点是啥（用来连接的
// 一个next记录下一层的开始（用户切换到下一层
/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        TreeLinkNode* prev = nullptr;
        TreeLinkNode* next = nullptr;
        
        while(root) {
            prev = nullptr;
            next = nullptr;
            //if(next == nullptr) next = root->left ? root->left : root->right;
            for( ; root ; root = root->next) {
                if(next == nullptr) next = root->left ? root->left : root->right;
                if(root->left) {
                    if(prev) prev->next = root->left;
                    prev = root->left;
                }
                if(root->right) {
                    if(prev) prev->next = root->right;
                    prev = root->right;
                }
            }
            root = next;
        }
    }
};



// 题意是说给你一棵二叉树，每个树节点中增加了一个next指针，指向了其同一层的相邻的右边的节点。
// 一开始由于考虑到使用层次遍历的方法，因此维护一个队列，队列中的每个节点记录其所属的深度，于是对同一层的节点使其next指针指向该节点在队列中的下一个节点就可以了。花费的时间复杂度是O(n)，空间复杂度为O(n)。
// 然而由于题目中要求使用const space，于是考虑优化空间的方法。
// 无论如何是要进行层次遍历的，当我们进行第i层遍历的时候，其实第i-1层的next指针我们已经构建完成了，也就是说我们沿着上一层的next指针走就能遍历完上一层的所有节点。同时由于第i层的节点我们可以通过第i-1层的left、right指针进行访问，因此我们可以省略掉之前使用的队列，从而达到空间复杂度为O(1)，时间复杂度为O(n)的解法。
// 程序中cur指向当前层的当前节点，head指向下一层的头指针，
// prev指向下一层的还未进行next指针设置的最后一个节点，也就是将要设置next指针的那个节点。




// 要处理一个节点，可能需要最右边的兄弟节点，首先想到用广搜。但广搜不是常数空间的，本题要求常数空
// LeetCode, Populating Next Right Pointers in Each Node II
// 时间复杂度O(n)，空间复杂度O(1)
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (root == nullptr) return;

        TreeLinkNode dummy(-1);
        for (TreeLinkNode *curr = root, *prev = &dummy; 
                curr; curr = curr->next) {
            if (curr->left != nullptr){
                prev->next = curr->left;
                prev = prev->next;
            }
            if (curr->right != nullptr){
                prev->next = curr->right;
                prev = prev->next;
            }
        }
        connect(dummy.next);
    }
};

// LeetCode, Populating Next Right Pointers in Each Node II
// 时间复杂度O(n)，空间复杂度O(1)
class Solution {
public:
    void connect(TreeLinkNode *root) {
        while (root) {
            TreeLinkNode * next = nullptr; // the first node of next level
            TreeLinkNode * prev = nullptr; // previous node on the same level
            for (; root; root = root->next) {
                if (!next) next = root->left ? root->left : root->right;

                if (root->left) {
                    if (prev) prev->next = root->left;
                    prev = root->left;
                }
                if (root->right) {
                    if (prev) prev->next = root->right;
                    prev = root->right;
                }
            }
            root = next; // turn to next level
        }
    }
};


