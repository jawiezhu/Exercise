// Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

// For example:
// Given binary tree {3,9,20,#,#,15,7},
//     3
//    / \
//   9  20
//     /  \
//    15   7
// return its bottom-up level order traversal as:
// [
//   [15,7],
//   [9,20],
//   [3]
// ]

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
    vector<vector<int> > levelOrderBottom(TreeNode* root) {
        vector<vector<int> >ret;
        ret.clear();
        if(root==NULL)
        	return ret;
        queue<TreeNode*> Q;
        Q.push(root);
        Q.push(NULL);
        vector<int> tmp;
        while(!Q.empty())
        {
        	TreeNode *p=Q.front();
        	Q.pop();
        	if(p!=NULL)
        	{
        		tmp.push_back(p->val);
        		if(p->left)
        			Q.push(p->left);
        		if(p->right)
        			Q.push(p->right);
        	}else{
        		if(!tmp.empty())
        		{
        			S.push(NULL);
        			ret.push_back(tmp);
        			tmp.clear();
        		}
        	}
        }
        reverse(ret.begin(),ret.end());
        return ret;
    }
};


//
// LeetCode, Binary Tree Level Order Traversal II
// 递归版，时间复杂度O(n)，空间复杂度O(n)
class Solution {
public:
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        vector<vector<int>> result;
        traverse(root, 1, result);
        std::reverse(result.begin(), result.end()); // 比上一题多此一行
        return result;
    }

    void traverse(TreeNode *root, size_t level, vector<vector<int>> &result) {
        if (!root) return;

        if (level > result.size())
            result.push_back(vector<int>());

        result[level-1].push_back(root->val);
        traverse(root->left, level+1, result);
        traverse(root->right, level+1, result);
    }
};


//
// LeetCode, Binary Tree Level Order Traversal II
// 迭代版，时间复杂度O(n)，空间复杂度O(1)
class Solution {
public:
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        vector<vector<int> > result;
        if(root == nullptr) return result;

        queue<TreeNode*> current, next;
        vector<int> level; // elments in level level

        current.push(root);
        while (!current.empty()) {
            while (!current.empty()) {
                TreeNode* node = current.front();
                current.pop();
                level.push_back(node->val);
                if (node->left != nullptr) next.push(node->left);
                if (node->right != nullptr) next.push(node->right);
            }
            result.push_back(level);
            level.clear();
            swap(next, current);
        }
        reverse(result.begin(), result.end()); // 比上一题多此一行
        return result;
    }
};


//
// discuss 中有另外一个历史dfs 实现的，思路其实差不多，
// dfs 中每次遍历的值先填写到vector<vector<int> >  ret正确位置，
// 即一列一列地填，而bfs 则是一行一行地填ret，最后反向一下，仍然是不能避免反向。
vector<vector<int> > res;

void DFS(TreeNode* root, int level)
{
    if (root == NULL) return;
    if (level == res.size()) // The level does not exist in output
    {
        res.push_back(vector<int>()); // Create a new level
    }

    res[level].push_back(root->val); // Add the current value to its level
    DFS(root->left, level+1); // Go to the next level
    DFS(root->right,level+1);
}

vector<vector<int> > levelOrderBottom(TreeNode *root) {
    DFS(root, 0);
    return vector<vector<int> > (res.rbegin(), res.rend());
}