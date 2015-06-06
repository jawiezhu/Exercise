// Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

// For example:
// Given binary tree {3,9,20,#,#,15,7},
//     3
//    / \
//   9  20
//     /  \
//    15   7
// return its zigzag level order traversal as:
// [
//   [3],
//   [20,9],
//   [15,7]
// ]
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int> >res;
        if(root==NULL) return res;

        vector<int> level;
        queue<TreeNode* > q;
        q.push(root);

        int cnt=1;
        int curcnt=0;

        bool order=true;

        while(!q.empty())
        {
        	TreeNode *node=q.front();
        	q.pop();
        	level.push_back(node->val);
        	if(node->left)
        	{
        		q.push(node->left);
        		curcnt++;
        	}
        	if(node->right)
        	{
        		q.push(node->right);
        		curcnt++;
        	}

        	cnt--;
        	if(cnt==0)
        	{
        		if(order)
        		{
        			res.push_back(level);
        		}else{
        			reverse(level.begin(),level.end());
        			res.push_back(level);
        		}

        		order=!order;
        		level.clear();
        		cnt=curcnt;
        		curcnt=0;
        	}
        }
        return res;
    }
};


// LeetCode, Binary Tree Zigzag Level Order Traversal
// 递归版，时间复杂度O(n)，空间复杂度O(n)
class Solution {
public:
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        vector<vector<int>> result;
        traverse(root, 1, result, true);
        return result;
    }

    void traverse(TreeNode *root, size_t level, vector<vector<int>> &result,
            bool left_to_right) {
        if (!root) return;

        if (level > result.size())
            result.push_back(vector<int>());

        if (left_to_right)
            result[level-1].push_back(root->val);
        else
            result[level-1].insert(result[level-1].begin(), root->val);

        traverse(root->left, level+1, result, !left_to_right);
        traverse(root->right, level+1, result, !left_to_right);
    }
};



//LeetCode, Binary Tree Zigzag Level Order Traversal
//广度优先遍历，用一个bool记录是从左到右还是从右到左，每一层结束就翻转一下。
// 迭代版，时间复杂度O(n)，空间复杂度O(n)
class Solution {
public:
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        vector<vector<int> > result;
        if (nullptr == root) return result;

        queue<TreeNode*> q;
        bool left_to_right = true;  //left to right
        vector<int> level;  // one level's elements

        q.push(root);
        q.push(nullptr);  // level separator
        while (!q.empty()) {
            TreeNode *cur = q.front();
            q.pop();
            if (cur) {
                level.push_back(cur->val);
                if (cur->left) q.push(cur->left);
                if (cur->right) q.push(cur->right);
            } else {
                if (left_to_right) {
                    result.push_back(level);
                } else {
                    reverse(level.begin(), level.end());
                    result.push_back(level);
                }
                level.clear();
                left_to_right = !left_to_right;

                if (q.size() > 0) q.push(nullptr);
            }
        }

        return result;
    }
};


//=================
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
   vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
	vector<vector<int>>result;
	if (!root)
		return result;
	vector<int>vec;
	queue<TreeNode*>q1;
	TreeNode *temp = root;
	enum Dir{L,R};
	Dir dir = L;
	q1.push(root);
	
	while (!q1.empty())
	{
		queue<TreeNode *>q2;
		while (!q1.empty())
		{
			temp = q1.front();
			q1.pop();
			if (temp->left)
				q2.push(temp->left);
			if (temp->right)
				q2.push(temp->right);
			vec.push_back(temp->val);
		}
		if (dir == R)
		{
			reverse(vec.begin(), vec.end());
			dir = L;
		}
		else
			dir = R;
		result.push_back(vec);
		vec.clear();
		q1 = q2;
	}
	return result;
	}
};

//===========================
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

struct Node
{
    TreeNode *node;
    int level;
    Node(){}
    Node(TreeNode *n, int l):node(n), level(l){}
};

class Solution {
private:
    vector<vector<int> > ret;
public:
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ret.clear();
        
        if (root == NULL)
            return ret;
        
        queue<Node> q;
        
        q.push(Node(root, 0));
        
        int curLevel = -1;
        
        vector<int> a;
        
        while(!q.empty())
        {
            Node node = q.front();
            
            if (node.node->left)
                q.push(Node(node.node->left, node.level + 1));
            
            if (node.node->right)
                q.push(Node(node.node->right, node.level + 1));
                
            if (curLevel != node.level)
            {
                if (curLevel != -1)
                {
                    if (curLevel % 2 == 1)
                        reverse(a.begin(), a.end());
                        
                    ret.push_back(a);
                }
                a.clear();
                curLevel = node.level;
            }
            a.push_back(node.node->val);
            q.pop();
        }
        
        if (curLevel % 2 == 1)
            reverse(a.begin(), a.end());
            
        ret.push_back(a);
        
        return ret;
    }
};
