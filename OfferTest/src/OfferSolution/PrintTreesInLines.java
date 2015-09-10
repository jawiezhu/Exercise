package OfferSolution;

import java.util.LinkedList;
import java.util.List;

public class PrintTreesInLines {
	public void print(TreeNode root){
		if(root==null) return ;
		
		List<TreeNode> list=new LinkedList<TreeNode>();
		TreeNode node;
		//��ǰ��Ľڵ����
		int current=1;
		//��¼��һ��Ľڵ����
		int next=0;
		list.add(root);
		
		while(list.size()>0){
			node=list.remove(0);
			current--;
			//System.out.printf("%-3d", node.value);
			
			if(node.left!=null){
				list.add(node.left);
				next++;
			}
			
			if(node.right!=null){
				list.add(node.right);
				next++;
			}
			
			if(current==0){
				System.out.println();
				current=next;
				next=0;
			}
		}
	}
}
