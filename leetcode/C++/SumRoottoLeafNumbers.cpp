// Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.

// An example is the root-to-leaf path 1->2->3 which represents the number 123.

// Find the total sum of all root-to-leaf numbers.

// For example,

//     1
//    / \
//   2   3
// The root-to-leaf path 1->2 represents the number 12.
// The root-to-leaf path 1->3 represents the number 13.

// Return the sum = 12 + 13 = 25.

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
	int dfs(TreeNode* root,int sum)
	{
		if(root==NULL) return  0;
		if(root->left==NULL&&root->right==NULL)
			return sum*10+root->val;

		return dfs(root->left,sum*10+root->val)+dfs(root->right,sum*10+root->val);
	}
    int sumNumbers(TreeNode* root) {
        return dfs(root,0);
    }
};


class Solution {
public:
    int sumNumbers(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int sum=0;
        sumPath(root,0,sum);
        return sum;
    }
    void sumPath(TreeNode* root, int prevSum, int& sum)
    {
        if(root==NULL)
        {
            return;
        }
        prevSum=prevSum*10+root->val;
        
        if(root->left==NULL && root->right==NULL)
            sum+=prevSum;
        
        sumPath(root->left,prevSum,sum);
        sumPath(root->right,prevSum,sum);
    }
};



// 非递归方法，使用栈存放当前的路径进行深度搜索，并设置部分和记录栈中的数值。

// 结合进栈与出栈进行部分和调整：

// 进栈：部分和*10+当前值

// 出栈：(部分和-当前值)/10

// 如果遍历到叶节点，则将部分和加入总和。

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
    int sumNumbers(TreeNode* root) {
        if(root == NULL)
            return 0;
        int ret = 0;
        int cur = 0;
        stack<TreeNode*> stk;
        unordered_map<TreeNode*, bool> visited;
        stk.push(root);
        visited[root] = true;
        cur += root->val;
        while(!stk.empty())
        {
            TreeNode* top = stk.top();
            if(top->left != NULL && visited[top->left] == false)
            {
                stk.push(top->left);
                visited[top->left] = true;
                cur = cur*10 + top->left->val;
                continue;
            }
            if(top->right != NULL && visited[top->right] == false)
            {
                stk.push(top->right);
                visited[top->right] = true;
                cur = cur*10 + top->right->val;
                continue;
            }
            if(top->left == NULL && top->right == NULL)
            {
                ret += cur;
            }
            stk.pop();
            cur = (cur - top->val) / 10;
        }
        return ret;
    }
};