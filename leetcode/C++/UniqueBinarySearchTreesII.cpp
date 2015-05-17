// Given n, generate all structurally unique BST's (binary search trees) that store values 1...n.

// For example,
// Given n = 3, your program should return all 5 unique BST's shown below.

//    1         3     3      2      1
//     \       /     /      / \      \
//      3     2     1      1   3      2
//     /     /       \                 \
//    2     1         2                 3
// confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.

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
    vector<TreeNode*> generateTrees(int n) {
        return createTree(1,n);
    }

    vector<TreeNode*> createTree(int start,int end)
    {
    	vector<TreeNode *> result;
    	if(start>end)
    	{
    		result.push_back(NULL);
    		return result;
    	}


    	for(int i=start;i<=end;i++)
    	{
    		vector<TreeNode*> left=createTree(start,i-1);
    		vector<TreeNode*> right=createTree(i+1,end);
    		for(int j=0;j<left.size();j++)
    		{
    			for(int k=0;k<right.size();k++)
    			{
    				TreeNode *root=new TreeNode(i);
    				root->left=left[j];
    				root->right=right[k];
    				result.push_back(root);
    			}
    		}
    	}

    	return result;
    }
};


// LeetCode, Unique Binary Search Trees II
// 时间复杂度TODO，空间复杂度TODO
class Solution {
public:
    vector<TreeNode *> generateTrees(int n) {
        if (n == 0) return generate(1, 0);
        return generate(1, n);
    }
private:
    vector<TreeNode *> generate(int start, int end) {
        vector<TreeNode*> subTree;
        if (start > end) {
            subTree.push_back(nullptr);
            return subTree;
        }
        for (int k = start; k <= end; k++) {
            vector<TreeNode*> leftSubs = generate(start, k - 1);
            vector<TreeNode*> rightSubs = generate(k + 1, end);
            for (auto i : leftSubs) {
                for (auto j : rightSubs) {
                    TreeNode *node = new TreeNode(k);
                    node->left = i;
                    node->right = j;
                    subTree.push_back(node);
                }
            }
        }
        return subTree;
    }
};
