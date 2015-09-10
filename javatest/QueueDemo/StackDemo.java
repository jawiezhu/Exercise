package QueueDemo;

import java.util.ArrayDeque;
import java.util.Deque;

/**
 * 使用队列实现自定义堆栈
 * 弹
 * 压
 * 获取头
 * @author JawieZhu
 *
 * @param <E>
 */

public class StackDemo<E> {
	private Deque<E> container=new ArrayDeque<E>();
	
	private int cap;

	public StackDemo(int cap) {
		super();
		this.cap = cap;
	}
	
	//
	public boolean push(E e){
		if(container.size()+1>cap){
			return false;
		}
		
		return container.offerLast(e);
	}
	
	
	public E pop(){
		return container.pollLast();
	}
	
	public E peek(){
		return container.peekLast();
	}
	
	public int size(){
		return this.container.size();
	}
}
