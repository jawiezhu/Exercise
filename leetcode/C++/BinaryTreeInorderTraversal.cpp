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
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int>path;
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
};