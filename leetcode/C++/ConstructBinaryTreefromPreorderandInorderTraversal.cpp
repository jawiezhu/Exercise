// Given preorder and inorder traversal of a tree, construct the binary tree.

// Note:
// You may assume that duplicates do not exist in the tree.

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
	TreeNode* createTree(vector<int>& preorder,int prestart,int preend,vector<int>& inorder,int instart,int inend)
	{
		if(instart>inend) return NULL;

		int root=preorder[prestart];
		int index;

		for(int i=instart;i<=inend;i++)
		{
			if(inorder[i]==root)
			{
				index=i;
				break;
			}
		}

		int len=index-instart;
		TreeNode * left=createTree(preorder,prestart+1,prestart+len,inorder,instart,index-1);
		//TreeNode * left=createTree(preorder,prestart+1,prestart+len-1,inorder,instart,index-1);
		//TreeNode * right=createTree(preorder,prestart+len,preend-1,inorder,index+1,inend);
		TreeNode * right=createTree(preorder,prestart+len+1,preend,inorder,index+1,inend);
		TreeNode *node=new TreeNode(root);
		node->left=left;
		node->right=right;

		return node;
	}


    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size()==0) return NULL;

        TreeNode* head=createTree(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1);
        return head;
    }
};


// 前序遍历第一个肯定是root
// 在inorder里面去找root
// 左边的是leftsubtree , 右边的是rightsubtree
// 然后preorder除去order,后面lifetsubtree.size 个是左边的, rightsubtree.size个是右边的
// 递归构造tree就好了
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
    template<typename Iter>
    TreeNode* make(Iter pFirst , Iter pLast , Iter iFirst , Iter iLast) {
        if(pFirst == pLast) return nullptr;
        if(iFirst == iLast) return nullptr;
        int val = *pFirst;
        auto iRoot = find(iFirst , iLast , val);
        TreeNode* root = new TreeNode(*iRoot);
        int leftSize = iRoot - iFirst;
        root -> left = make(pFirst+1 , pFirst+leftSize+1 , iFirst , iRoot);
        root -> right = make(pFirst+leftSize+1 , pLast , iRoot + 1 , iLast);
        return root;
    }
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        int size = inorder.size();
        if(size == 0) return nullptr;
        return make(preorder.begin() , preorder.end() , inorder.begin() , inorder.end());
    }
};


//
class Solution {
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (preorder.size() <= 0)
            return NULL;
            
        if (preorder.size() != inorder.size())
            return NULL;
            
        TreeNode* root = new TreeNode(0);
        root = buildTree(preorder, 0, preorder.size()-1, inorder,0, preorder.size()-1);
        
        return root;
    }
    
    
    TreeNode* buildTree(vector<int> &preorder, int preStart, int preEnd, vector<int> &inorder, int inStart, int inEnd){
        if (preEnd < preStart )
            return NULL;
            
        TreeNode* root = new TreeNode(0);
        root->val = preorder.at(preStart);
        if (preEnd== preStart)    
    		return root;
            
        int i;
        for(i = 0; i < inorder.size(); i++){
            if (inorder.at(inStart+i) == root->val)
                break;
        }
        
        root->left  = buildTree(preorder, preStart+1, preStart+i,inorder,inStart, inStart + i-1);
        root->right = buildTree(preorder, preStart+1+i, preEnd,inorder,inStart+ i+1, inEnd);
        return root;
    }
};

//

// LeetCode, Construct Binary Tree from Preorder and Inorder Traversal
// 递归，时间复杂度O(n)，空间复杂度O(\logn)
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildTree(begin(preorder), end(preorder),
                begin(inorder), end(inorder));
    }

    template<typename InputIterator>
    TreeNode* buildTree(InputIterator pre_first, InputIterator pre_last,
            InputIterator in_first, InputIterator in_last) {
        if (pre_first == pre_last) return nullptr;
        if (in_first == in_last) return nullptr;

        auto root = new TreeNode(*pre_first);

        auto inRootPos = find(in_first, in_last, *pre_first);
        auto leftSize = distance(in_first, inRootPos);

        root->left = buildTree(next(pre_first), next(pre_first,
                leftSize + 1), in_first, next(in_first, leftSize));
        root->right = buildTree(next(pre_first, leftSize + 1), pre_last,
                next(inRootPos), in_last);

        return root;
    }
};



