package leetcode_Easy;

import java.util.LinkedList;
import java.util.Queue;


//用两个队列q1，q2实现一个栈。push时把新元素添加到q1的队尾。
//pop时把q1中除最后一个元素外逐个添加到q2中，
//然后pop掉q1中的最后一个元素，然后注意记得q1和q2，
//以保证我们添加元素时始终向q1中添加。top的道理类似。
public class ImplementStackusingQueues {
	
	private Queue<Integer> q1=new LinkedList<Integer>();
	private Queue<Integer> q2=new LinkedList<Integer>();
	
	 // Push element x onto stack.
    public void push(int x) {
        q1.offer(x);
    }

    // Removes the element on top of the stack.
    public void pop() {
    	int s1=q1.size()-1;
        for(int i=0;i<s1;i++)
        	q2.offer(q1.poll());
        q1.poll();
        
        Queue<Integer> tmp=q1;
        q1=q2;
        q2=tmp;
    }

    // Get the top element.
    public int top() {
    	int s1=q1.size()-1;
    	for(int i=0;i<s1;i++)
        	q2.offer(q1.poll());
    	
    	int top=q1.peek();
    	q2.offer(q1.poll());
    	
    	Queue<Integer> tmp=q1;
    	q1=q2;
    	q2=tmp;
    	
    	return top;
    }

    // Return whether the stack is empty.
    public boolean empty() {
        return q1.isEmpty() && q2.isEmpty();
    }
}

//push时直接添加到队尾就好。
//pop和top时，把队列除最后一个元素外，逐个循环添加到队列的尾部。
class MyStack {  
    private Queue<Integer> q = new LinkedList<Integer>();  
      
    // Push element x onto stack.  
    public void push(int x) {  
        q.offer(x);  
    }  
  
    // Removes the element on top of the stack.  
    public void pop() {  
        int size = q.size();  
        for (int i = 1; i < size; i++) {  
            q.offer(q.poll());  
        }  
        q.poll();  
    }  
  
    // Get the top element.  
    public int top() {  
        int size = q.size();  
        for (int i = 1; i < size; i++) {  
            q.offer(q.poll());  
        }  
        int top = q.peek();  
        q.offer(q.poll());  
        return top;  
    }  
  
    // Return whether the stack is empty.  
    public boolean empty() {  
        return q.isEmpty();  
    }  
}  

