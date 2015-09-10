package OfferSolution;

import java.util.Stack;

public class QueueWithTwoStacks extends CQueue {

	
	
	@Override
	public void appendTail(int x) {
		stack1.push(x);
	}

	@Override
	public int deleteHead() {
		// TODO Auto-generated method stub
		while(!stack1.isEmpty()){
			int tmp=stack1.peek();
			stack2.push(tmp);
			stack1.pop();
		}
		
		int ele=stack2.peek();
		stack2.pop();
		return ele;
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

}


abstract class CQueue{
	public void appendTail(int x){
		
	}
	
	public int deleteHead(){
		return 0;
		
	}
	
	Stack<Integer> stack1=new Stack();
	Stack<Integer> stack2=new Stack();
}