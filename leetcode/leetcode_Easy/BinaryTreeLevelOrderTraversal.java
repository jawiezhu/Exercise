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
	
	
	
	public List<List<Integer>> levelOrder2(TreeNode root) {
        List<List<Integer>> nodes = new ArrayList<List<Integer>>();
    if(root==null){
        return nodes;
    }

    LinkedList<TreeNode> queue = new LinkedList<TreeNode>();

    queue.add(root);

    while(queue.size()!=0){

        int size = queue.size();
        List<Integer> layer_vals = new ArrayList<Integer>();

        while(size!=0){
            TreeNode temp = queue.poll();
            layer_vals.add(temp.val);

            if(temp.left!=null)queue.add(temp.left);
            if(temp.right!=null)queue.add(temp.right);

            size--;
        }
        nodes.add(layer_vals);
    }

    return nodes;
    }
}
