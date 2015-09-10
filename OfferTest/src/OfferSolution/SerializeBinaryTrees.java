package OfferSolution;

import java.util.LinkedList;
import java.util.List;

public class SerializeBinaryTrees {
	public static void serialize(TreeNode root,List<Integer> result){
		List<TreeNode> list=new LinkedList<TreeNode>();
		list.add(root);
		TreeNode node;
		while(list.size()>0){
			node=list.remove(0);
			if(node==null){
				result.add(null);
			}else{
				result.add(node.value);
				list.add(node.left);
				list.add(node.right);
			}
		}
	}
	
	public static TreeNode deserialize(List<Integer> result,int idx){
		if(result.size()<1 || idx<0 ||result.size()<=idx || result.get(idx)==null){
			return null;
		}
		
		TreeNode root=new TreeNode(result.get(idx));
		root.left=deserialize(result,idx*2+1);
		root.right=deserialize(result,idx*2+2);
		return root;
	}
	
	public static void main(String[] args) {
        test01();
    }

    private static void test01() {
        TreeNode n1 = new TreeNode(1);
        TreeNode n2 = new TreeNode(2);
        TreeNode n3 = new TreeNode(3);
        TreeNode n4 = new TreeNode(4);
        TreeNode n5 = new TreeNode(5);
        TreeNode n6 = new TreeNode(6);
        TreeNode n7 = new TreeNode(7);
        TreeNode n8 = new TreeNode(8);
        TreeNode n9 = new TreeNode(9);

        n1.left = n2;
        n1.right = n3;
        n2.left = n4;
        n2.right = n5;
        n3.left = n6;
        n3.right = n7;
        n4.left = n8;
        n4.right = n9;

        List<Integer> result = new LinkedList<Integer>();
        serialize(n1, result);
        System.out.println(result);
        System.out.println();

        TreeNode root = deserialize(result, 0) ;
        print(root);

    }

    private static void print(TreeNode root) {
        if (root != null) {
            print(root.left);
            System.out.printf("%-3d", root.value);
            print(root.right);
        }
    }
}
