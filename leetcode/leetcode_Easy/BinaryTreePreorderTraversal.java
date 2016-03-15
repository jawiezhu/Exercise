package leetcode_Easy;

import java.util.ArrayList;
import java.util.List;
import java.util.Stack;

public class BinaryTreePreorderTraversal {
	public List<Integer> preorderTraversal(TreeNode root){
		
		List<Integer> res=new ArrayList<Integer>();
		
		if(root==null) return res;
		
		Stack<TreeNode> stack=new Stack<TreeNode>();
		stack.push(root);
		
		while(!stack.empty()){
			TreeNode n=stack.pop();
			res.add(n.val);
			
			if(n.right!=null) stack.push(n.right);
			if(n.left!=null) stack.push(n.left);
		}
		return res;
	}
}


