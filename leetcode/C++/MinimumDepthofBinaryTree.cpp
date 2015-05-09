// Given a binary tree, find its minimum depth.

// The minimum depth is the number of nodes along 
// the shortest path from the root node down to the nearest leaf node.

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
    int minDepth(TreeNode *root) {
        if(root==NULL) return 0;
        if(root->left==NULL&&root->right==NULL) return 1;
        int i=minDepth(root->left);
        int j=minDepth(root->right);
       
       if(i==0)
            return j+1;
        if(j==0)
            return i+1;
            
        if(i<=j)
            return i+1;
        else
            return j+1;
    }
};



// LeetCode, Minimum Depth of Binary Tree
// 递归版，时间复杂度O(n)，空间复杂度O(logn)
class Solution {
public:
    int minDepth(const TreeNode *root) {
        return minDepth(root, false);
    }
private:
    static int minDepth(const TreeNode *root, bool hasbrother) {
        if (!root) return hasbrother ? INT_MAX : 0;

        return 1 + min(minDepth(root->left, root->right != NULL),
                minDepth(root->right, root->left != NULL));
    }
};


// LeetCode, Minimum Depth of Binary Tree
// 迭代版，时间复杂度O(n)，空间复杂度O(logn)
class Solution {
public:
    int minDepth(TreeNode* root) {
        if (root == nullptr)
            return 0;

        int result = INT_MAX;

        stack<pair<TreeNode*, int>> s;
        s.push(make_pair(root, 1));

        while (!s.empty()) {
            auto node = s.top().first;
            auto depth = s.top().second;
            s.pop();

            if (node->left == nullptr && node->right == nullptr)
                result = min(result, depth);

            if (node->left && result > depth) // 深度控制，剪枝
                s.push(make_pair(node->left, depth + 1));

            if (node->right && result > depth) // 深度控制，剪枝
                s.push(make_pair(node->right, depth + 1));
        }

        return result;
    }
};



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
    int minDepth(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (root == NULL)
            return 0;
            
        if (root->left == NULL && root->right == NULL)
            return 1;
            
        int leftDepth = minDepth(root->left);
        int rightDepth = minDepth(root->right);
        
        if (leftDepth == 0)
            return rightDepth + 1;
        else if (rightDepth == 0)
            return leftDepth + 1;
        else
            return min(leftDepth, rightDepth) + 1;
    }
};



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

    void minDepthInternal(TreeNode *root, std::vector<TreeNode *> &treeVector, int &minDepth)
    {
        if (!root)
            return;
            
        treeVector.push_back(root);
        
        if (root->left == NULL && root->right == NULL)
        {
            if (treeVector.size() < minDepth)
            {
                minDepth = treeVector.size();
            }
            treeVector.pop_back();
            return;
        }
        
        minDepthInternal(root->left, treeVector, minDepth);
        minDepthInternal(root->right, treeVector, minDepth);
        
        treeVector.pop_back();
        
    }

    int minDepth(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        if (!root)
            return 0;
            
        vector<TreeNode *> treeVector;
        int minDepth = 10000;
        
        minDepthInternal(root, treeVector, minDepth);
        
        return minDepth;
    }
};

// DFS. 同时定义一个变量作为当前最小值,
//  每次求的一条路径, 就和改变量做比较, 最后所有的路径都遍历完之后,就可求得最小值.
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
    int minDepth(TreeNode *root) {
		if(!root){
			return 0;
		}
		int depth = 0, min = -1;
		return binTreePreTravel(root, depth, min);
    }
	int binTreePreTravel(TreeNode* root, int depth, int& min){
		depth++;
		if(root->left){
			binTreePreTravel(root->left, depth, min);
		}
		if(root->right){
			binTreePreTravel(root->right, depth, min);
		}
		if(!root->left && !root->right){
			if(min != -1){
				min = (min < depth? min: depth);
			}
			else if(min == -1){
				min = depth;
			}
		}
		return min;
	}
};


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
    int minDepth(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (root == NULL) return 0;
        
        int left = minDepth(root->left) + 1;
        int right = minDepth(root->right) + 1;
        // 叶子节点
        if (left == 1 || right == 1)
            return left > right ? left : right;
            
        return left < right ? left : right;
    }
};

