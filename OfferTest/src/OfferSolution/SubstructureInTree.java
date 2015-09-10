package OfferSolution;

public class SubstructureInTree {
	public boolean HasSubtree(TreeNode Root1,TreeNode Root2){
		boolean res=false;
		
		if(Root1!=null&&Root2!=null){
			if(Root1.value==Root2.value){
				res=isSame(Root1,Root2);
			}
			if(!res){
				res=HasSubtree(Root1.left,Root2);
			}
			if(!res){
				res=HasSubtree(Root1.right,Root2);
			}
		}
		
		return res;
	}

	private boolean isSame(TreeNode root1, TreeNode root2) {
		// TODO Auto-generated method stub
		if(root2==null) return true;
		if(root1==null) return false;
		if(root1.value!=root2.value) return false;
		return isSame(root1.left,root2.left)&&isSame(root1.right,root2.right);
	}
}
