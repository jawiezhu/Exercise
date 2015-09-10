package leetcode;

public class BalancedBinaryTree {
	public boolean isBalanced(TreeNode root) {
        if(root==null) return true;
        if(Math.abs(maxDepth(root.left)-maxDepth(root.right))<=1 && isBalanced(root.left) && isBalanced(root.right)) return true;
        return false;
    }
	
	public static int maxDepth(TreeNode root){
		if(root==null) return 0;
		return Math.max(maxDepth(root.left), maxDepth(root.right))+1;
	}
}
