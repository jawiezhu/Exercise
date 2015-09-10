package OfferSolution;

public class KthNodeInBST {
	public static TreeNode KthNode(TreeNode root,int k){
		if(root==null || k<1) return null;
		
		int[] tmp={k};
		return kthNodeCore(root,tmp);
	}

	private static TreeNode kthNodeCore(TreeNode root, int[] k) {
		TreeNode result=null;
		
		// 先成左子树中找
		if(root.left!=null){
			result=kthNodeCore(root.left,k);
		}
		
		// 如果在左子树中没有找到
		if(result==null){
			// 说明当前的根结点是所要找的结点
			if(k[0]==1){
				result=root;
			}else{
				// 当前的根结点不是要找的结点，但是已经找过了，所以计数器减一
				k[0]--;
			}
		}
		
		// 根结点以及根结点的右子结点都没有找到，则找其右子树
		if(result==null && root.right!=null){
			result=kthNodeCore(root.right,k);
		}
		
		return result;
	}
	
	
	 public static void main(String[] args) {
	        TreeNode n1 = new TreeNode(1);
	        TreeNode n2 = new TreeNode(2);
	        TreeNode n3 = new TreeNode(3);
	        TreeNode n4 = new TreeNode(4);
	        TreeNode n5 = new TreeNode(5);
	        TreeNode n6 = new TreeNode(6);
	        TreeNode n7 = new TreeNode(7);
	        TreeNode n8 = new TreeNode(8);
	        TreeNode n9 = new TreeNode(9);

//	        n1.left = n2;
//	        n1.right = n3;
//	        n2.left = n4;
//	        n2.right = n5;
//	        n3.left = n6;
//	        n3.right = n7;
//	        n4.left = n8;
//	        n4.right = n9;
	        
	        n5.left=n3;
	        n5.right=n7;
	        n3.left=n2;
	        n3.right=n4;
	        n7.left=n6;
	        n7.right=n8;

	        print(n1);
	        System.out.println();

	        for (int i = 0; i <= 10; i++) {
	            System.out.printf(KthNode(n5, i) + ", ");
	        }

	    }
	 
	 
	 private static void print(TreeNode root) {
	        if (root != null) {
	            print(root.left);
	            System.out.printf("%-3d", root.value);
	            print(root.right);
	        }
	    }
}
