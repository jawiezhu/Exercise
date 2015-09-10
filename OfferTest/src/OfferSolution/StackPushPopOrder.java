package OfferSolution;

import java.util.Stack;

public class StackPushPopOrder {
	public boolean check(int[] pPush,int[] pPop){
		boolean isPossiable=false;
		
		if(pPush!=null && pPop!=null){
			Stack<Integer> stack=new Stack<Integer>();
			int i=0;
			int j=0;
			
			//检查每个出栈
			while(j<pPop.length){
				while(i<pPush.length && pPop[j]!=pPush[i]){
					//如果不等、则一直进站
					stack.push(pPush[i]);
					i++;
				}
				//相等的元素没有进站
				i++;
				j++;
				int top=0;
				//出栈比较
				while((!stack.isEmpty())&&(top=stack.pop())==pPop[j]){
					j++;
				}
				
				if(j<pPop.length){
					stack.push(top);
				}
				//当已经找不到进站元素时退出
				
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
