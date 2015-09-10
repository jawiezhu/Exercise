package OfferSolution;

import java.util.Stack;

public class StackPushPopOrder {
	public boolean check(int[] pPush,int[] pPop){
		boolean isPossiable=false;
		
		if(pPush!=null && pPop!=null){
			Stack<Integer> stack=new Stack<Integer>();
			int i=0;
			int j=0;
			
			//���ÿ����ջ
			while(j<pPop.length){
				while(i<pPush.length && pPop[j]!=pPush[i]){
					//������ȡ���һֱ��վ
					stack.push(pPush[i]);
					i++;
				}
				//��ȵ�Ԫ��û�н�վ
				i++;
				j++;
				int top=0;
				//��ջ�Ƚ�
				while((!stack.isEmpty())&&(top=stack.pop())==pPop[j]){
					j++;
				}
				
				if(j<pPop.length){
					stack.push(top);
				}
				//���Ѿ��Ҳ�����վԪ��ʱ�˳�
				
				if(i>=pPush.length&&!stack.isEmpty()){
					break;
				}
			}
			
			if(stack.isEmpty()){
				isPossiable=true;
			}
		}
		
		return isPossiable;
	}
}
