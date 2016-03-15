package leetcode_Easy;

import java.util.Deque;
import java.util.LinkedList;
import java.util.Queue;

public class MaximumDepthofBinaryTree {
	public int maxDepth(TreeNode root){
		if(root==null) return 0;
		return Math.max(maxDepth(root.left), maxDepth(root.right))+1;
	}
	
	
	public int maxDepth2(TreeNode root){
		if(root==null) return 0;
		
		Queue<TreeNode> stack=new LinkedList<TreeNode>();
		
		stack.add(root);
		int count=0;
		
		while(!stack.isEmpty()){
			int size=stack.size();
			while(size-- >0){
				TreeNode cur=stack.poll();
				if(cur.left != null) stack.add(cur.left);
				if(cur.right != null) stack.add(cur.right);
			}
			count++;
		}
		
		return count;
	}
}
