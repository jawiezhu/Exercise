package leetcode_Easy;

import java.util.ArrayList;
import java.util.List;
import java.util.Stack;

public class BinaryTreeInorderTraversal {
	public List<Integer> inorderTraversal(TreeNode root){
		List<Integer> lst=new ArrayList<Integer>();
		
		if(root==null) return lst;
		
		Stack<TreeNode> stack=new Stack<TreeNode>();
		
		TreeNode p=root;
		
		while(!stack.empty() || p!=null){
			
			//if it is not null, push to stack
			//and go down the tree to left
			if(p!=null){
				stack.push(p);
				p=p.left;
				
			//if no left child	
			//pop stack,process the node
			//then let p point to the right
			}else{
				TreeNode t=stack.pop();
				lst.add(t.val);
				p=t.right;
			}
		}
		
		return lst;
	}
	
	
}

class Solution{
	
	
	List<Integer> res=new ArrayList<Integer>();
	public List<Integer> inorderTraversal(TreeNode root){
		if(root==null) return res;
		
		inorderTraversal(root.left);
		res.add(root.val);
		inorderTraversal(root.right);
		
		return res;
	}
	
}
