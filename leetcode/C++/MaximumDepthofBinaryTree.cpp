//Given a binary tree, find its maximum depth.
//The maximum depth is the number of nodes along the longest path from the root 
//node down to the farthest leaf node.
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
    int maxDepth(TreeNode *root) {
        if(root==NULL) return 0;
        if(root&&root->left==NULL&&root->right==NULL) return 1;
        int i=1;
        int j=1;
        i=maxDepth(root->left);
        j=maxDepth(root->right);
        
        if(i>j)
            return i+1;
        else
            return j+1;
    }
};

//Queue
class Solution{
public:
    //二叉树最大深度（层次遍历，遍历一层高度加1）
    int maxDepth(TreeNode *root){
        int height=0;
        int rowCount=1;
        if(root==NULL) return 0;

        queue<TreeNode*> queue;
        queue.push(root);
        //层次遍历
        while(!queue.empty()){
            TreeNode *node=queue.front();
            queue.pop();
            rowCount--;
            if(node->left)
            {
                queue.push(node->left);
            }
            if(node->right)
            {
                queue.push(node->right);
            }
            //一层遍历完
            if(rowCount==0)
            {
                height++;
                rowCount=queue.size();
            }
        }

        return height;
    }
};

//Stack
class Solution{
public:
    int maxDepth(TreeNode *root){
        if(root==NULL) return 0;

        stack<TreeNode*> S;
        int maxDepth=0;
        TreeNode *prev=NULL;
        S.push(root);
        while(!S.empty()){
            TreeNode *curr=S.top();

            if(prev==NULL||prev->left==curr||prev->right==curr)
            {
                if(curr->left)
                    S.push(curr->left);
                else if(curr->right)
                    S.push(curr->right);
            }else if(curr->left==prev){
                if(curr->right)
                    S.push(curr->right);
            }else{
                S.pop();
            }
            prev=curr;
            if(S.size()>maxDepth)
                maxDepth=S.size();
        }
    return maxDepth;
    }
};

//DFS
class Solution{
public:
    int maxDepth(TreeNode *root){
        if(root==NULL) return 0;
        int res=INT_MIN;
        dfs(root,1,res);
        return res;
    }
    void dfs(TreeNode *root,int depth,int &res)
    {
        if(root->left==NULL&&root->right==NULL&&res<depth)
        {
            res=depth;
            return ;
        }
        if(root->left)
            dfs(root->left,depth+1,res);
        if(root->right)
            dfs(root->right,depth+1,res);
    }
};

//BFS
class Solution{
public:
    int maxDepth(TreeNode *root){
        //层次遍历树的层数，NULL为每一层节点的分割标识
        if(root==NULL) return 0;
        int res=0;
        queue<TreeNode *>Q;
        Q.push(root);
        Q.push(NULL);
        while(Q.empty()==false)
        {
            TreeNode *p=Q.front();
            Q.pop();
            if(p!=NULL)
            {
                if(p->left) Q.push(p->left);
                if(p->right)Q.push(p->right);
            }
            else
            {
                res++;
                if(Q.empty()==false)Q.push(NULL);
            }
        }
        return res;
    }
}