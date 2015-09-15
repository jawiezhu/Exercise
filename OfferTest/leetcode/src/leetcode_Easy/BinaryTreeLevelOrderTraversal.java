package leetcode_Easy;

import java.util.ArrayList;
import java.util.Deque;
import java.util.LinkedList;
import java.util.List;

public class BinaryTreeLevelOrderTraversal {
	public List<List<Integer>> levelOrder(TreeNode root) {
        List<List<Integer>> list=new LinkedList<List<Integer>>();
        if(root==null) return list;
        
        Deque<TreeNode> cur=new LinkedList<TreeNode>();
        Deque<TreeNode> nxt=new LinkedList<TreeNode>();
        Deque<TreeNode> exc=new LinkedList<TreeNode>();
        
        TreeNode tmp;
        
        cur.add(root);
        
        while(!cur.isEmpty()){
        	List<Integer> layout=new ArrayList<Integer>();
        	
        	while(!cur.isEmpty()){
        		tmp=cur.remove();
        		
        		if(tmp.left!=null){
        			nxt.add(tmp.left);
        		}
        		
        		if(tmp.right!=null){
        			nxt.add(tmp.right);
        		}
        		
        		layout.add(tmp.val);
        	}
        	
        	exc=cur;
        	cur=nxt;
        	nxt=exc;
        	
        	
        	list.add(layout);
        	System.out.println(list);
        	
        }
        
        return list;
    }
}
