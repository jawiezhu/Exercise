// Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

// For example:
// Given the below binary tree and sum = 22,
//               5
//              / \
//             4   8
//            /   / \
//           11  13  4
//          /  \    / \
//         7    2  5   1
// return
// [
//    [5,4,11,2],
//    [5,8,4,5]
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
private:
	vector<vector<int> > ret;
public:
	void dfs(TreeNode *node,int sum,int curSum,vector<int> tmp)
	{
		if(node==NULL) return;

		if(node->left==NULL &&node->right==NULL)
		{
			if(curSum+node->val==sum)
			{
				tmp.push_back(node->val);
				ret.push_back(tmp);
			}
			return ;
		}

		tmp.push_back(node->val);
		dfs(node->left,sum,curSum+node->val,tmp);
		dfs(node->right,sum,curSum+node->val,tmp);
	}

    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        ret.clear();
        vector<int> tmp;
        dfs(root,sum,0,tmp);
        return ret;
    }
};


//
class Solution {
public:
    int SUM;
    vector<vector<int> > result;
 
    void dfs(TreeNode *root, const int &curSum, vector<int> party) {
        party.push_back(root->val);
        if(curSum + root->val == SUM) {
            if(root->left == NULL && root->right == NULL) {
                result.push_back(party);
                return;
            }
        }
        if(root->left != NULL ) {
            dfs(root->left, curSum+root->val, party);
        }
        if(root->right != NULL ) {
            dfs(root->right, curSum+root->val, party);
        }
         
    }
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
      SUM = sum;
      result.clear();
      if(root != NULL) {
          vector<int> temp;
          dfs(root, 0, temp);
      }
      return result;
    }
};

//=====================
#include<iostream>
#include<new>
#include<vector>
using namespace std;

//Definition for binary tree
struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
  vector<vector<int> > pathSum(TreeNode *root, int sum)
  {
    vector<vector<int> > path;
    vector<int> tmp;
    hasPathSum(root,sum,path,tmp);
    return path;
  }
  void hasPathSum(TreeNode *root, int sum,vector<vector<int> > &path,vector<int> tmp)
  {
    if(root==NULL)
      return;
    tmp.push_back(root->val);
    if(root->left==NULL&&root->right==NULL&&(sum-root->val)==0)
    {
      path.push_back(tmp);
    }
    if(root->left)
      hasPathSum(root->left,sum-root->val,path,tmp);
    if(root->right)
      hasPathSum(root->right,sum-root->val,path,tmp);
  }
  void createTree(TreeNode *&root)
  {
    int i;
    cin>>i;
    if(i!=0)
    {
      root=new TreeNode(i);
      if(root==NULL)
        return;
      createTree(root->left);
      createTree(root->right);
    }
  }
};
int main()
{
  Solution s;
  TreeNode *root;
  s.createTree(root);
  vector<vector<int> > path=s.pathSum(root,6);
  for(auto a:path)
  {
    for(auto v:a)
      cout<<v<<" ";
    cout<<endl;
  }
}//




// LeetCode, Path Sum II
// 时间复杂度O(n)，空间复杂度O(logn)
class Solution {
public:
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        vector<vector<int> > result;
        vector<int> cur; // 中间结果
        pathSum(root, sum, cur, result);
        return result;
    }
private:
    void pathSum(TreeNode *root, int gap, vector<int> &cur,
            vector<vector<int> > &result) {
        if (root == nullptr) return;

        cur.push_back(root->val);

        if (root->left == nullptr && root->right == nullptr) { // leaf
            if (gap == root->val)
                result.push_back(cur);
        }
        pathSum(root->left, gap - root->val, cur, result);
        pathSum(root->right, gap - root->val, cur, result);

        cur.pop_back();
    }
};


//
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
    int targetSum;
    int depthSum;
    vector<vector<int> > res;
    vector<int> cur;
    void depthSearch(TreeNode* root)
    {
        if(root)
        {
            if(root->left == NULL && root->right == NULL)
            {
                if(root->val + depthSum == targetSum)
                {
                    cur.push_back(root->val);
                    res.push_back(cur);
                    cur.pop_back();
                }
                return;
            }
            depthSum += root->val;
            cur.push_back(root->val);
            depthSearch(root->left);
            depthSearch(root->right);
            depthSum -= root->val;
            cur.pop_back();
        }
    }
public:
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        res.clear();
        cur.clear();
        depthSum = 0;
        targetSum = sum;
        depthSearch(root);
        return res;
    }
};

//
void findPathSum(TreeNode* root, vector<int> &path, vector<vector<int>> &allpath, int sum)
    {
    	path.push_back(root->val);
		if(root->left == NULL && root->right == NULL){
			vector<int>::iterator it = path.begin();
			int tmpsum = 0;
			for(; it != path.end(); ++it)
				tmpsum += *it;
			if(tmpsum == sum){
				allpath.push_back(path);}
			path.pop_back();
			return;
		}

		if(root->left)
			findPathSum(root->left,path,allpath,sum);
		if(root->right)
			findPathSum(root->right,path,allpath,sum);
		path.pop_back();
	}
	vector<vector<int> > pathSum(TreeNode *root, int sum) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int>> allpath;
		if(root == NULL)
			return allpath;
		vector<int> path;
		findPathSum(root, path, allpath, sum);
		return allpath;
    }

//

    

