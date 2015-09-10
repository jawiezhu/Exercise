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
		
		//Ҷ�ڵ� �� ·���Ͻڵ�ĺ͵��������ֵ
		if(currentSum==sum && (root.left==null)&&(root.right==null)){
			//��ӡvector�ڵ�
		}
		
		//�������Ҷ�ڵ㣬����
		if(root.left!=null)
			FindPaths(root.left,sum,path,currentSum);
		if(root.right!=null)
			FindPaths(root.right,sum,path,currentSum);
		
		//���ظ��ڵ�ǰ��·����ɾ����ǰ�ڵ�
		path.remove(root.value);
		
		
		
	}
}
