package Generic3;

public abstract class Father<T> {
	T name;
	public abstract void test(T t);
}

//子类声明时使用指定具体类型
//属性的类型为具体类型
//方法同理
class Child1 extends Father<String>{
	String t2;
	@Override
	public void test(String t) {
		// TODO Auto-generated method stub

	}
}


class Child2<T> extends Father<T>{
	String t2;
	@Override
	public void test(T t) {
		// TODO Auto-generated method stub

	}
}
