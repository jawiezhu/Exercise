

//Given two binary trees, write a function to check if they are equal or not.
//Two binary trees are considered equal if they are structurally identical and the nodes have the same value.

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
    bool isSameTree(TreeNode *p, TreeNode *q) {
        if(p==NULL&&q==NULL) 
            return 1;
        else if(!(q!=NULL&&p!=NULL&&q->val==p->val)) 
            return 0;
        return  isSameTree(p->left,q->left)&&isSameTree(p->right,q->right);
    }
};

class Solution {
public:
    bool isSameTree(TreeNode *p, TreeNode *q) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(!p&&!q) return true;
        if(!p&&q||p&&!q||p->val!=q->val) return false;
        
        bool left=isSameTree(p->left,q->left);
        bool right=isSameTree(p->right,q->right);
        
        return left&&right;
    }
};