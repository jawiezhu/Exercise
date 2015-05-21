// Given inorder and postorder traversal of a tree, construct the binary tree.

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
 //递归构造
class Solution {
public:
	TreeNode* createTree(vector<int>& inorder,int instart,int inend,vector<int> &postorder,int poststart,int postend)
	{
		if(instart>inend) return NULL;

		int root=postorder[postend];

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
		TreeNode *left=createTree(inorder,instart,index-1,postorder,poststart,poststart+len-1);
		TreeNode *right=createTree(inorder,index+1,inend,postorder,poststart+len,postend-1);

		TreeNode *node=new TreeNode(root);
		node->left=left;
		node->right=right;

		return node;
	}
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        if(inorder.size()==0) return NULL;

        TreeNode *head=createTree(inorder,0,inorder.size()-1,postorder,0,postorder.size()-1);
        return head;
    }
};



// LeetCode, Construct Binary Tree from Inorder and Postorder Traversal
// 递归，时间复杂度O(n)，空间复杂度O(\logn)
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return buildTree(begin(inorder), end(inorder),
                begin(postorder), end(postorder));
    }

    template<typename BidiIt>
    TreeNode* buildTree(BidiIt in_first, BidiIt in_last,
            BidiIt post_first, BidiIt post_last) {
        if (in_first ==in_last) return nullptr;
        if (post_first == post_last) return nullptr;

        const auto val = *prev(post_last);
        TreeNode* root = new TreeNode(val);

        auto in_root_pos = find(in_first, in_last, val);
        auto left_size = distance(in_first, in_root_pos);
        auto post_left_last = next(post_first, left_size);

        root->left = buildTree(in_first, in_root_pos, post_first, post_left_last);
        root->right = buildTree(next(in_root_pos), in_last, post_left_last,
                prev(post_last));

        return root;
    }
};



//
// 根据定义，后序遍历postorder的最后一个元素为根。
// 由于元素不重复，通过根可以讲中序遍历inorder划分为左子树和右子树。
// 递归下去即可求解。
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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        return Helper(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1);
    }
    TreeNode* Helper(vector<int>& inorder, int begin1, int end1, vector<int>& postorder, int begin2, int end2)
    {
        if(begin1 > end1)
            return NULL;
        else if(begin1 == end1)
            return new TreeNode(inorder[begin1]);
        
        TreeNode* root = new TreeNode(postorder[end2]);
        int i = begin1;
        for(; i <= end1; i ++)
        {
            if(inorder[i] == postorder[end2])
                break;
        }
        int leftlen = i-begin1;
        
        root->left = Helper(inorder, begin1, begin1+leftlen-1, postorder, begin2, begin2+leftlen-1);
        root->right = Helper(inorder, begin1+leftlen+1, end1, postorder, begin2+leftlen, end2-1);
        return root;
    }
};


// //
// 不过草稿纸上随便画了一个简单的二叉树：1 / 2 3 / 4 5 6 7，

// 它的中序遍历是：4 2 5 1 6 3 7

// 它的后序遍历是：4 5 2 6 7 3 1

// 可以获知的是，对于这样的情形下，根节点是后序遍历序列的最后一个数——1，
// 既然题中说没有重复的数，那么把这个1放到中序遍历的序列中去找，找到了以后，
// 1的左侧的子序列[4,2,5]和后序遍历相应的前三个数[4,5,2]就可以继续构造左子树，
// 而1的右侧的子序列[6,3,7]和后序遍历的接下去的三个数[6,7,3]可以继续构造右子树。
public class Solution {
    public TreeNode buildTree(int[] inorder, int[] postorder) {
        TreeNode fakeRoot = new TreeNode(0);
        buildTree(inorder, 0, inorder.length-1, postorder, 0, postorder.length-1, fakeRoot, true);
        return fakeRoot.left;
    }
    
    private void buildTree(int[] inorder, int istart, int iend, int[] postorder, int pstart, int pend, TreeNode parent, boolean leftOrRight) {
        if (iend<istart)
            return;
        
        // root == postorder[pend]
        for (int i=istart; i<=iend; i++) {
            if (postorder[pend]==inorder[i]) {
                TreeNode root = new TreeNode(postorder[pend]);
                if (leftOrRight)
                    parent.left = root;
                else
                    parent.right = root;
                    
                buildTree(inorder, istart, i-1, postorder, pstart, pstart + (i-1-istart), root, true);
                buildTree(inorder, i+1, iend, postorder, pend-1 - (iend-i-1), pend - 1, root, false);
            }
        }
    }
}//

