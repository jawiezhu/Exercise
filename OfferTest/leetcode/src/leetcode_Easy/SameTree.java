package leetcode_Easy;

public class SameTree {
	 public boolean isSameTree(TreeNode p, TreeNode q) {
		 
		 /*
		  * if(p==null && q==null) return true;
		  * else if(!(q!=null && p!=null && q.val==p.val) return false;
		  * return isSameTree(p.left,q.left) && isSameTree(p.right,q.right);
		  */
		 if(p==null && q==null) return true;
		 if(p==null && q!=null) return false;
		 if(p!=null && q==null) return false;
		 if(p.val!=q.val) return false;
		 return isSameTree(p.left, q.left) && isSameTree(p.right,q.right);
	 }
}
