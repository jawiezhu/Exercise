// Given a binary tree, return the preorder traversal of its nodes' values.

// For example:
// Given binary tree {1,#,2,3},
//    1
//     \
//      2
//     /
//    3
// return [1,2,3].

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
    void preorder(TreeNode * root, vector<int> &path)
    {   
    	if(root)
        {
        	path.push_back(root->val);
        	preorder(root->left,path);
        	preorder(root->right,path);
        }
    }
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> path;
        if(root==NULL) return path;
        preorder(root,path);
        return path;
    }
};


class Solution{
public:
    vector<int> preorderTraversal(TreeNode *root){
        vector<int> path;
        stack<TreeNode*> stk;
        while(root!=NULL||!stk.empty())
        {
            if(root!=NULL)
            {
                while(root)
                {
                    path.path_back(root->val);
                    stk.push(root);
                    root=root->left;
                }
            }else{
                root=stk.top()->right;
                stk.pop();
            }
        }
        return path;
    }
};

vector<int> preorderTraversal(TreeNode *root){
    vector<int> path;
    stack<TreeNode*>stk;
    if(root!=NULL)
    {
        stk.push(root);
        while(!stk.empty())
        {
            root=stk.top();
            stk.pop();
            path.push_back(root->val);
            if(root->right) stk.push(root->right);
            if(root->left) stk.push(root->left);
        }
    }
    return path;
}

vector<int> InorderTraversal(TreeNode *root){
    vector<int> path;
    stack<TreeNode*>stk;
    while(root!=NULL||!stk.empty())
    {
        while(root!=NULL)
        {
            stk.push(root);
            root=root->left;
        }
        if(!stk.empty())
        {
            root=stk.top();
            path.push_back(root->val);
            stk.pop();
            root=root->right;
        }
    }
    return path;
}

//=======================

struct TNode{
    int val;
    TNode *left;
    TNode *right;
    bool isVisited;
    TNode(int a):val(a),left(NULL),right(NULL),isVisited(false){};
};
vector<int> PostOrderTraversal(TNode *root){
    vector<int> path;
    stack<TNode*> stk;
    if(root!=NULL)
    {
        root->isVisited=false;
        stk.push(root);
    }
    TNode* cur=NULL;
    while(!stk.empty())
    {
        cur=stk.top();
        if(cur->isVisited)
        {
            path.push_back(cur->val);
            stk.pop();
        }else{
            cur->isVisited=true;
            if(cur->right)
            {
                cur->right->isVisited=false;
                stk.push(cur->right);
            }
            if(cur->left)
            {
                cur->left->isVisited=false;
                stk.push(cur->left);
            }
        }
    }
    return path;
}
