package leetcode;

import java.util.LinkedList;
import java.util.Queue;

public class InvertBinaryTree {
	public TreeNode invertTree(TreeNode root){
		if(root==null) return null;
		//if(root.left==null&&root.right==null) return root;
		TreeNode temp=root.left;
		root.left=root.right;
		root.right=temp;
		invertTree(root.left);
		invertTree(root.right);
		return root;
	}
	
	public TreeNode invertTree2(TreeNode root){
		if(root==null) return null;
		Queue<TreeNode> q=new LinkedList<TreeNode>();
		q.add(root);
		while(!q.isEmpty()){
			TreeNode node=q.peek();
			q.poll();
			
			TreeNode temp=node.left;
			node.left=node.right;
			node.right=temp;
			
			if(node.left!=null) q.add(node.left);
			if(node.right!=null) q.add(node.right);
		}
		
		return root;
	}
}	


