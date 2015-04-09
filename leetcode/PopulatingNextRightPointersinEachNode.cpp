// Given a binary tree

//     struct TreeLinkNode {
//       TreeLinkNode *left;
//       TreeLinkNode *right;
//       TreeLinkNode *next;
//     }
// Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

// Initially, all next pointers are set to NULL.

// Note:

// You may only use constant extra space.
// You may assume that it is a perfect binary tree (ie, all leaves are at the same level, and every parent has two children).
// For example,
// Given the following perfect binary tree,
//          1
//        /  \
//       2    3
//      / \  / \
//     4  5  6  7
// After calling your function, the tree should look like:
//          1 -> NULL
//        /  \
//       2 -> 3 -> NULL
//      / \  / \
//     4->5->6->7 -> NULL

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
        
        if(root->left&&root->right)
        {
            root->left->next=root->right;
            if(root->next)
                root->right->next=root->next->left;
            else
                root->right->next=NULL;
        }
            
        connect(root->left);
        connect(root->right);
            
        
    }
};

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
        //NULL or has no children, nothing to do.
        if(root == NULL || root->left == NULL) 
          return;
        TreeLinkNode *p = root;
        while(p != NULL)
        {
          p->left->next = p->right;
          if(p->next)
          p->right->next = p->next->left;
          p = p->next;
        }
        connect(root->left);
    }
};

class Solution {
public:
    void connect(TreeLinkNode *root) {
        //NULL or has no children, nothing to do.
        if(root == NULL || root->left == NULL) 
          return;
        while(root){
        if(root->left == NULL) return;
        TreeLinkNode *p = root;
        while(p != NULL)
        {
          p->left->next = p->right;
          if(p->next)
          p->right->next = p->next->left;
          p = p->next;
        }
        root = root->left;
        }
    }
};

//（1）根据题述：左孩子为空，则右孩子一定为空，所以左孩子为空，则return
// （2）如果左孩子不为空，则右孩子一定不为空，所以链接左孩子和右孩子即可（左孩子的next赋值为右孩子）
// （3）由于先序遍历，所以父节点的next比子节点的next先被设置，故父节点不同的两个子节点进行连接，
// 就可以用到父节点的next，整题的精华便是：root->right->next = root->right