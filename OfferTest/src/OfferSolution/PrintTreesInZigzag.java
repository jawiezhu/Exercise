package OfferSolution;

import java.util.LinkedList;
import java.util.List;

public class PrintTreesInZigzag {
	public static void printzigzag(TreeNode root){
		if(root==null) return;
		List<TreeNode> current=new LinkedList<TreeNode>();
		List<TreeNode> reverse=new LinkedList<TreeNode>();
		
		int flag=0;
		TreeNode node;
		current.add(root);
		
		while(current.size()>0){
			 // 从最后一个开始取
			node=current.remove(current.size()-1);
			
			 //System.out.printf("%-3d", node.val);
			
			 // 当前是从左往右打印的，那就按从左往右入栈
			if(flag==0){
				if(node.left!=null){
					reverse.add(node.left);
				}
				
				if(node.right!=null){
					reverse.add(node.right);
				}
			}else{
				// 当前是从右往左打印的，那就按从右往左入栈
				if(node.right!=null){
					reverse.add(node.right);
				}
				
				if(node.left!=null){
					reverse.add(node.left);
				}
			}
			
			//当一层所有结点都打印完了，交换这两个栈并继续打印下一层
			if(current.size()==0){
				flag=1-flag;
				List<TreeNode> tmp=current;
				current=reverse;
				reverse=tmp;
				System.out.println();
			}
			
		}
		
		
	}
}
