package OfferSolution;

public class TreeDepth {
	public int maxDepth(TreeNode root){
		if(root==null) return 0;
		return Math.max(maxDepth(root.left), maxDepth(root.right))+1;
	}
}	

class Solution{
	public int TreeDepth(TreeNode root){
		if(root==null) return 0;
		
		int left=TreeDepth(root.left);
		int right=TreeDepth(root.right);
		
		return (left>right)?(left+1):(right+1);
	}
}

class BalanceTree{
	public boolean IsBalanced(TreeNode root){
		if(root==null) return true;
		return Math.abs(maxDepth(root.left)-maxDepth(root.right))<=1
				&&	IsBalanced(root.left)
				&&  IsBalanced(root.right);
	}
	
	public int maxDepth(TreeNode root){
		if(root==null) return 0;
		return Math.max(maxDepth(root.left), maxDepth(root.right))+1;
	}
}

class SolutionOther{
	public int TreeDepth(TreeNode root){
		if(root==null) return 0;
		
		int left=TreeDepth(root.left);
		int right=TreeDepth(root.right);
		
		return (left>right)?(left+1):(right+1);
	}
	
	public boolean Balanced(TreeNode root){
		if(root==null) return false;
		
		int left=TreeDepth(root.left);
		int right=TreeDepth(root.right);
		
		int diff=left-right;
		if(diff>1||diff<-1) 
			return false;
	
		return	Balanced(root.left) && Balanced(root.right);
	}
}

class SolutionBetter{
	public boolean IsBalanced(TreeNode root){
		int depth=0;
		return IsBal(root,depth);
	}

	private boolean IsBal(TreeNode root, int depth) {
		// TODO Auto-generated method stub
		if(root==null) {
			depth=0;
			return true;
		}
		int left=0;
		int right=0;
		if(IsBal(root.left,left)&&IsBal(root.right,right)){
			int diff=left-right;
			if(diff<=1||diff>=-1){
				depth=1+(left>right ? left:right);
				return true;
			}
		}
		return false;
	}
}

class SolutionBetter2{
	public boolean isBalanced(TreeNode root){
		return maxDepth(root)!=-1;
	}
	
	private int maxDepth(TreeNode root){
		if(root==null) return 0;
		int L=maxDepth(root.left);
		
		if(L==-1) return -1;
		int R=maxDepth(root.right);
		if(R==-1) return -1;
		
		if(Math.abs(L-R)<=1){
			return Math.max(L, R)+1;
		}else
			return -1;
	}
}



