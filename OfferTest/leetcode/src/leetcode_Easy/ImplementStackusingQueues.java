package leetcode_Easy;

import java.util.LinkedList;
import java.util.Queue;


//����������q1��q2ʵ��һ��ջ��pushʱ����Ԫ����ӵ�q1�Ķ�β��
//popʱ��q1�г����һ��Ԫ���������ӵ�q2�У�
//Ȼ��pop��q1�е����һ��Ԫ�أ�Ȼ��ע��ǵ�q1��q2��
//�Ա�֤�������Ԫ��ʱʼ����q1����ӡ�top�ĵ������ơ�
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

//pushʱֱ����ӵ���β�ͺá�
//pop��topʱ���Ѷ��г����һ��Ԫ���⣬���ѭ����ӵ����е�β����
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

