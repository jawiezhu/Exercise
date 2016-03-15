package leetcode_Easy;

import java.util.ArrayList;
import java.util.Deque;
import java.util.LinkedList;
import java.util.List;

public class BinaryTreeLevelOrderTraversalII {
	public static List<List<Integer>> levelOrderBottom(TreeNode root) {
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
        	
        	
        	list.add(0,layout);
        	System.out.println(list);
        	
        }
        
        return list;
        
    }
	
	public static void main(String[] args){
		TreeNode n3=new TreeNode(3);
		TreeNode n9=new TreeNode(9);
		TreeNode n20=new TreeNode(20);
		TreeNode n15=new TreeNode(15);
		TreeNode n7=new TreeNode(7);
		
		n3.left=n9;
		n3.right=n20;
		n20.left=n15;
		n20.right=n7;
		
		levelOrderBottom(n3);
	}
}
