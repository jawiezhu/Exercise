package OfferSolution;

import java.util.LinkedList;
import java.util.Queue;

public class PrintFromTopToBottom {
	public void Qprint(TreeNode Root){
		if(Root==null) return;
		
		Queue<TreeNode> Q=new LinkedList<TreeNode>();
		Q.offer(Root);
		
		while(Q.size()!=0){
			TreeNode p=Q.peek();
			Q.remove();
			
			System.out.println(p.value);
			
			if(p.left!=null)
				Q.offer(p.left);
			if(p.right!=null)
				Q.offer(p.right);
			
		}
	}
}
