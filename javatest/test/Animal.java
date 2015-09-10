package test;

public abstract class Animal {
	public abstract void run();
	public void breath() {
		
	}
}

class Cat extends Animal{

	@Override
	public void run() {
		// TODO Auto-generated method stub
		System.out.println("miao miao run!~");
	}
	
}

class Dog extends Animal{

	@Override
	public void run() {
		// TODO Auto-generated method stub
		System.out.println("dog run!~");
	}
	
	
}
