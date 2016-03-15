package leetcode_Easy;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Stack;

public class BinaryTreePostOrderTree {
	public List<Integer> postorderTraversal(TreeNode root) {
		 
        List<Integer> lst = new ArrayList<Integer>();
 
        if(root == null)
            return lst; 
 
        Stack<TreeNode> stack = new Stack<TreeNode>();
        stack.push(root);
 
        TreeNode prev = null;
        while(!stack.empty()){
            TreeNode curr = stack.peek();
 
            if(prev == null || prev.left == curr || prev.right == curr){
               
                if(curr.left != null){
                    stack.push(curr.left);
                }else if(curr.right != null){
                    stack.push(curr.right);
                }else{
                    stack.pop();
                    lst.add(curr.val);
                }
 
          
            }else if(curr.left == prev){
                if(curr.right != null){
                    stack.push(curr.right);
                }else{
                    stack.pop();
                    lst.add(curr.val);
                }
 
            
            }else if(curr.right == prev){
                stack.pop();
                lst.add(curr.val);
            }
 
            prev = curr;
        }
 
        return lst;
    }
	
	
	 public List<Integer> postorderTraversal2(TreeNode root) {
         LinkedList<Integer> result = new LinkedList<Integer>();
    if(root == null) return result;

    Stack<TreeNode> stack = new Stack<TreeNode>();
    stack.push(root);

    while(!stack.isEmpty()){
        root = stack.pop();
        result.addFirst(root.val);
        if(root.left != null){
            stack.push(root.left);
        }
        if(root.right != null){
            stack.push(root.right);
        }
    }

    return result;
    }
}
