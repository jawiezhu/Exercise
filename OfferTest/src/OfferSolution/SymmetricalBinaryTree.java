package OfferSolution;

public class SymmetricalBinaryTree {
	public boolean isSymmetrical(TreeNode root){
		return isSymmetrical(root,root);
	}

	private boolean isSymmetrical(TreeNode root, TreeNode root2) {
		// TODO Auto-generated method stub
		if(root==null && root2==null) return true;
		
		if(root==null || root2==null) return false;
		
		if(root.value!= root2.value) return false;
		
		return isSymmetrical(root.left,root2.right)&&
				isSymmetrical(root.right,root2.left);
	}
	
	
}
