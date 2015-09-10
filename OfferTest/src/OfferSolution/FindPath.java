package OfferSolution;

import java.util.Vector;

public class FindPath {
	public void Find(TreeNode Root,int sum){
		if(Root==null) return;
		Vector<Integer> path = null;
		int currentSum=0;
		FindPaths(Root,sum,path,currentSum);
	}

	private void FindPaths(TreeNode root, int sum, Vector<Integer> path,
			int currentSum) {
		// TODO Auto-generated method stub
		currentSum+=root.value;
		path.add(root.value);
		
		//叶节点 且 路径上节点的和等于输入的值
		if(currentSum==sum && (root.left==null)&&(root.right==null)){
			//打印vector节点
		}
		
		//如果不是叶节点，遍历
		if(root.left!=null)
			FindPaths(root.left,sum,path,currentSum);
		if(root.right!=null)
			FindPaths(root.right,sum,path,currentSum);
		
		//返回父节点前，路径是删除当前节点
		path.remove(root.value);
		
		
		
	}
}
