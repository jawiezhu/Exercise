package OfferSolution;

import java.util.LinkedList;
import java.util.List;

public class PrintTreesInZigzag {
	public static void printzigzag(TreeNode root){
		if(root==null) return;
		List<TreeNode> current=new LinkedList<TreeNode>();
		List<TreeNode> reverse=new LinkedList<TreeNode>();
		
		int flag=0;
		TreeNode node;
		current.add(root);
		
		while(current.size()>0){
			 // �����һ����ʼȡ
			node=current.remove(current.size()-1);
			
			 //System.out.printf("%-3d", node.val);
			
			 // ��ǰ�Ǵ������Ҵ�ӡ�ģ��ǾͰ�����������ջ
			if(flag==0){
				if(node.left!=null){
					reverse.add(node.left);
				}
				
				if(node.right!=null){
					reverse.add(node.right);
				}
			}else{
				// ��ǰ�Ǵ��������ӡ�ģ��ǾͰ�����������ջ
				if(node.right!=null){
					reverse.add(node.right);
				}
				
				if(node.left!=null){
					reverse.add(node.left);
				}
			}
			
			//��һ�����н�㶼��ӡ���ˣ�����������ջ��������ӡ��һ��
			if(current.size()==0){
				flag=1-flag;
				List<TreeNode> tmp=current;
				current=reverse;
				reverse=tmp;
				System.out.println();
			}
			
		}
		
		
	}
}
