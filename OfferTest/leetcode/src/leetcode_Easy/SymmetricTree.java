package leetcode_Easy;

public class SymmetricTree {
	 public boolean isSymmetric(TreeNode root) {
	     return isSymmetical(root,root);
	 }

	private boolean isSymmetical(TreeNode root1, TreeNode root2) {
		// TODO Auto-generated method stub
		if(root1==null && root2==null) return true;
		if(root1==null || root2==null) return false;
		if(root1.val!=root2.val) return false;
		
		return isSymmetical(root1.left,root2.right) && isSymmetical(root1.right,root2.left);
	}
}
