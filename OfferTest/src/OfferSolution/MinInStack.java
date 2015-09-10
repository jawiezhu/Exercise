package OfferSolution;

import java.util.Stack;

public class MinInStack {
	Stack<Integer> stack_main=new Stack<Integer>();
	Stack<Integer> stack_min=new Stack<Integer>();
	
	public void push(int x){
		stack_main.push(x);
		if(stack_min.size()==0 || x<stack_min.peek()){
			stack_min.push(x);
		}else{
			stack_min.push(stack_min.peek());
		}
	}
	
	public void pop(){
		stack_main.pop();
		stack_min.pop();
	}
	
	public int min(){
		return stack_min.pop();
	}
}
