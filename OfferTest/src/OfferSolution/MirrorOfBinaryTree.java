package OfferSolution;

public class MirrorOfBinaryTree {
	public void Mirror(TreeNode Root){
		if(Root==null) return ;
		if(Root.left==null && Root.right==null) return ;
		
		TreeNode Tmp=Root.left;
		Root.left=Root.right;
		Root.right=Tmp;
		
		if(Root.left !=null) Mirror(Root.left);
		if(Root.right!=null) Mirror(Root.right);
	}
}
