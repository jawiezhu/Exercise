// Given a binary tree, determine if it is height-balanced.

// For this problem, 
// a height-balanced binary tree is defined as 
// a binary tree in which the depth of the two subtrees 
// of every node never differ by more than 1.

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// 分析：树上的任意结点的左右子树高度差不超过1，则为平衡二叉树。
// 搜索递归，记录i结点的左子树高度h1和右子树高度h2，则i结点的高度为max(h1,h2)=1，
// |h1-h2|>1则不平衡
class Solution {
public:
	int maxDepth(TreeNode * root)
	{	
		if(root==NULL)
			return 0;
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
    bool isBalanced(TreeNode *root) {
        if(root==NULL) return 1;
        
        int leftDepth=maxDepth(root->left);
        int rightDepth=maxDepth(root->right);

        if(leftDepth-rightDepth>1||leftDepth-rightDepth<-1)
        	return false;
        else
        	return isBalanced(root->left)&&isBalanced(root->right);
    }
};


//========================
class Solution {
public:
    int flag=true;
    int dfs(TreeNode *root)
    {
         if(root==NULL) return true;
         int h1,h2;
         if(root->left==NULL) h1=0;
         else h1=dfs(root->left);
         if(root->right==NULL) h2=0;
         else h2=dfs(root->right);
         if(abs(h1-h2)>1) flag=0;
         return max(h1,h2)+1;
    }
    bool isBalanced(TreeNode *root) {
        dfs(root);
        return flag;
    }
};

//==================
// LeetCode, Balanced Binary Tree
// 时间复杂度O(n)，空间复杂度O(logn)
class Solution {
public:
    bool isBalanced (TreeNode* root) {
        return balancedHeight (root) >= 0;
    }

    /**
     * Returns the height of `root` if `root` is a balanced tree,
     * otherwise, returns `-1`.
     */
    int balancedHeight (TreeNode* root) {
        if (root == nullptr) return 0;  // 终止条件

        int left = balancedHeight (root->left);
        int right = balancedHeight (root->right);

        if (left < 0 || right < 0 || abs(left - right) > 1) return -1;  // 剪枝

        return max(left, right) + 1; // 三方合并
    }
};



//将时间复杂度优化到O(N)，但是空间复杂度同样是O(N).
public class CheckTreeBalanced {
    
    HashMap<TreeNode, Integer> heights = new HashMap<TreeNode, Integer>();

    // The idea is to run DFS once
    boolean isBalanced(TreeNode root){
        if(root == null){
            heights.put(null, 0);
            return true;
        }
        
        if( isBalanced(root.left) && isBalanced(root.right) ){
            if(Math.abs(heights.get(root.left) - heights.get(root.right)) > 1){
                return false;
                
            }else{
                int currentHeight = Math.max(heights.get(root.left),
                        heights.get(root.right)) + 1;
                heights.put(root, currentHeight);
                return true;
            }
            
        }else{
            return false;
        }
    }
};

// Cracking the coding interview上看到另一种解法，time complexity O(N), space complexity O(logN). 之所以占用logN的空间是因为这是DFS的特点，整棵树的高度H=logN，DFS必然会占用O(H), explicitly or implicitly.

// 该算法的思路是基于Solution #1的一种改进，把每个节点的height信息和isBalanced信息融合到一起个变量中：

// 如果该变量>=0，那么该节点是balanced并且该变量就是节点的height；

// 如果该变量<0，那么该节点是unbalanced，但同时我们失去了它的height信息。
public class CheckTreeBalanced2 {
    
    public int checkHeight(TreeNode root){
        if(root == null){
            return 0;
        }
        
        int leftHeight = checkHeight(root.left);
        if(leftHeight == -1){
            return -1;
        }
        
        int rightHeight = checkHeight(root.right);
        if(rightHeight == -1){
            return -1;
        }
        
        int heightDiff = leftHeight - rightHeight;
        if(Math.abs(heightDiff) > 1){
            return -1;
        }else{
            return Math.max(leftHeight, rightHeight);
        }
    }
    
    public boolean isBalance(TreeNode root){
        if(checkHeight(root) == -1){
            return false;
        }else{
            return true;
        }
    }
};

//重复访问了结点，优化下，改成后序遍历即可
class Solution {  
public:  
    bool isBalanced(TreeNode *root) {  
        // Note: The Solution object is instantiated only once and is reused by each test case.  
        int depth = 0;  
        return isbalance(root, depth);  
           
    }  
    bool isbalance(TreeNode *root, int &depth)  
    {  
        if(root == NULL)  
        {  
            depth = 0;  
            return true;  
        }  
        int ld,rd;  
        if( isbalance(root->left,ld) && isbalance(root->right,rd))  
        {  
            if( abs(ld - rd) > 1)  
            {  
                return false;  
            }  
            depth = ld > rd ? ld + 1 : rd + 1;  
            return true;  
        }  
    } 
       
};

