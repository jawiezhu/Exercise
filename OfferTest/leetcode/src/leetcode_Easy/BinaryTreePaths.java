package leetcode_Easy;

import java.util.LinkedList;
import java.util.List;

public class BinaryTreePaths {
	private static List<String> s=new LinkedList<String>();
	
	public static List<String> binaryTreePaths(TreeNode root){
		if(root!=null) findPaths(root,String.valueOf(root.val));
		return s;
	}

	private static void findPaths(TreeNode root, String path) {
		// TODO Auto-generated method stub
		if(root.left==null&& root.right==null) s.add(path);
		if(root.left!=null) findPaths(root.left,path+"->"+root.left.val);
		if(root.right!=null) findPaths(root.right,path+"->"+root.right.val);
	}
	
	public static void main(String[] args){
		TreeNode n1=new TreeNode(1);
		TreeNode n2=new TreeNode(2);
		TreeNode n3=new TreeNode(3);
		
		n1.left=n2;
		n1.right=n3;
		
		System.out.println(binaryTreePaths(n1));
	}
}
