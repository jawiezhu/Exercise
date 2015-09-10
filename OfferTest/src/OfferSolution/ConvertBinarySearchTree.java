package OfferSolution;

public class ConvertBinarySearchTree {
	public TreeNode Convert(TreeNode root){
		TreeNode pLastNodeInList=null;
		ConvertNode(root,pLastNodeInList);
		
		//将pLastNodeInList指向头结点
		TreeNode pHeadOfList=pLastNodeInList;
		while(pHeadOfList!=null&&pHeadOfList.left!=null){
			pHeadOfList=pHeadOfList.left;
		}
		
		return pHeadOfList;
		
	}

	private void ConvertNode(TreeNode root, TreeNode pLastNodeInList) {
		// TODO Auto-generated method stub
		if(root==null) return;
		
		TreeNode pCurrent=root;
		
		if(pCurrent.left!=null)
			ConvertNode(pCurrent.left,pLastNodeInList);
		
		pCurrent.left=pLastNodeInList;
		if(pLastNodeInList!=null)
			pLastNodeInList.left=pCurrent;
		pLastNodeInList=pCurrent;
		
		if(pCurrent.right!=null)
			ConvertNode(pCurrent.right,pLastNodeInList);
	}
}
