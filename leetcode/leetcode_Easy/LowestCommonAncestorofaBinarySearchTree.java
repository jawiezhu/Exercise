package leetcode_Easy;

public class LowestCommonAncestorofaBinarySearchTree {
	public TreeNode lowestCommonAncestor(TreeNode root,TreeNode p,TreeNode q){
		if(root==null) return null;
		if(root.val>p.val&&root.val>q.val) return lowestCommonAncestor(root.left,p,q);
		if(root.val<p.val&&root.val<q.val) return lowestCommonAncestor(root.right,p,q);
		return root;
	}
	
	
	//A non-recursive version.
	    public TreeNode lowestCommonAncestor2(TreeNode root, TreeNode p, TreeNode q) {
	        while (true) {
	            if (root.val > p.val && root.val > q.val)
	                root = root.left;
	            else if (root.val < p.val && root.val < q.val)
	                root = root.right;
	            else
	                return root;
	        }
	    }
	
	
	
}


