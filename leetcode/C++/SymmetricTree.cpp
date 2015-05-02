// Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

// For example, this binary tree is symmetric:

//     1
//    / \
//   2   2
//  / \ / \
// 3  4 4  3
// But the following is not:
//     1
//    / \
//   2   2
//    \   \
//    3    3
// Note:
// Bonus points if you could solve it both recursively and iteratively.

// confused what "{1,#,2,3}" means? > 
// read more on how binary tree is serialized on OJ.


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

 //递归
class Solution {
public:
	bool isSym(TreeNode* n1,TreeNode* n2)
	{
		if(n1==NULL&&n2!=NULL) return false;
		if(n1!=NULL&&n2==NULL) return false;
		if(n1==NULL&&n2==NULL) return true;
		if(n1->val!=n2->val) return false;

		return isSym(n1->left,n2->right)&&isSym(n1->right,n2->left);
	}

    bool isSymmetric(TreeNode* root) {
        if(root==NULL||(!root->left&&!root->right)) return true;
        return isSym(root->left,root->right);
    }
};


//利用中序遍历
public boolean isSymmetric(TreeNode root) {
        // Start typing your Java solution below
        // DO NOT write main() function
        if(root == null) return true;
        
        ArrayList<Integer> ret = new ArrayList<Integer>();
        inorder(root, ret);
        for(int i=0, j=ret.size()-1; i<j; i++, j--){
            if(ret.get(i) != ret.get(j))
                return false;
        }
        return true;
    }
    
    public void inorder(TreeNode root, ArrayList<Integer> ret){
        if(root == null) return;
        if(root.left!=null)
            inorder(root.left, ret);
        ret.add(root.val);
        if(root.right!=null)
            inorder(root.right, ret);
    }

//
//使用两个栈，分别对两个子树进行遍历，左子树先序遍历，右子树则反向的遍历
public boolean isSymmetricIter(TreeNode root) {
        if(root == null) return true;
        Stack<TreeNode> leftStack = new Stack<TreeNode>();
        Stack<TreeNode> rightStack = new Stack<TreeNode>();
        leftStack.push(root.left);
        rightStack.push(root.right);

        while (leftStack.size() > 0 && rightStack.size() > 0){
            TreeNode left = leftStack.pop();
            TreeNode right = rightStack.pop();
            if(left == null && right == null) continue;
            if(left == null || right == null) return false;
            if(left.val == right.val) {
                leftStack.push(left.right);
                leftStack.push(left.left);
                rightStack.push(right.left);
                rightStack.push(right.right);
            }else{
                return false;
            }
        }
        return true;
    }

// 递归判断，根节点单独判断，然后递归左结点和右结点，
// 之后每次一起递归左结点的左结点和右结点的右结点比较，左结点的右结点和右结点的左结点比较
class Solution {
public:
    bool dfs(TreeNode *left,TreeNode *right)
    {
        if(!left && !right) return true;//需要先判断这个，不然val那个可能会出现RE
        if((left && !right) || (!left && right) || (left->val!=right->val)) return false;
        return dfs(left->left,right->right) && dfs(left->right,right->left);
    }
    bool isSymmetric(TreeNode *root) {
        if(root==NULL || (!root->left && !root->right)) return true;
        return dfs(root->left,root->right);
    }
};


//非迭代
public class Solution {

    public boolean isSymmetric(TreeNode root) {
    if (root == null || root.left == null && root.right == null) return true;
	if (root.left != null && root.right == null) return false;
	if (root.right != null && root.left == null) return false;
	LinkedList<TreeNode> upperLevel = new LinkedList<TreeNode>(); 
    LinkedList<TreeNode> lowerLevel = new LinkedList<TreeNode>();
	TreeNode nullNode = new TreeNode(-1);
	upperLevel.add(root.left);
	upperLevel.add(root.right);

	while (upperLevel.size() != 0) {
		int length = upperLevel.size();
		for (int i = (length - 1) / 2; i >= 0; i--) {
			if (upperLevel.get(i) == nullNode && upperLevel.get(length - i - 1) == nullNode) {

			} else if (upperLevel.get(i).val == upperLevel.get(length - i - 1).val) {
				insertElement(upperLevel.get(i).right, lowerLevel, 0, nullNode);
				insertElement(upperLevel.get(i).left, lowerLevel, 0, nullNode);
				insertElement(upperLevel.get(length - i - 1).left, lowerLevel, nullNode);
				insertElement(upperLevel.get(length - i - 1).right, lowerLevel, nullNode);
			} else {
				return false;
			}			
		}
		LinkedList<TreeNode> temp = upperLevel;
		upperLevel = lowerLevel;
		lowerLevel = temp;
		lowerLevel.clear();
		
	}
	return true;
    }

	public void insertElement(TreeNode node, LinkedList<TreeNode> list, int i, TreeNode nullNode) {
		if (node == null) {
			list.add(i, nullNode);
		} else {
			list.add(i, node);
		}
	}

	public void insertElement(TreeNode node, LinkedList<TreeNode> list, TreeNode nullNode) {
		if (node == null) {
			list.add(nullNode);
		} else {
			list.add(node);
		}
	}

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(int x) { val = x; }
}