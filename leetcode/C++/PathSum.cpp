// Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.

// For example:
// Given the below binary tree and sum = 22,
//               5
//              / \
//             4   8
//            /   / \
//           11  13  4
//          /  \      \
//         7    2      1
// return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.


// 题目只要求返回{true}或者{false}，因此不需要记录路径。

// 由于只需要求出一个结果，因此，当左、右任意一棵子树求到了满意结果，都可以及时return。

// 由于题目没有说节点的数据一定是正整数，必须要走到叶子节点才能判断，因此中途没法剪枝，只能进行朴素深搜。
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
    bool pathsum(TreeNode *root,int sum,int val)
    {
        if(root==NULL)return 0;
        val+=root->val;
        if(root->left==NULL&&root->right==NULL)
        {
            if(sum==val)return 1;
            return 0;
            
        }
        
        return pathsum(root->left,sum,val)||pathsum(root->right,sum,val);
        
        
    }
    bool hasPathSum(TreeNode *root, int sum) {
        
        return pathsum(root,sum,0);
    }
};



// LeetCode, Path Sum
// 时间复杂度O(n)，空间复杂度O(logn)
class Solution {
public:
    bool hasPathSum(TreeNode *root, int sum) {
        if (root == nullptr) return false;

        if (root->left == nullptr && root->right == nullptr) // leaf
            return sum == root->val;

        return hasPathSum(root->left, sum - root->val)
                || hasPathSum(root->right, sum - root->val);
    }
};

