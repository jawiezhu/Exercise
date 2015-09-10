package test;

public class MyClass implements MyInterface {

	@Override
	public void test01() {
		// TODO Auto-generated method stub
		//MyInterface.MAX_GREAD;
		System.out.println(MyInterface.MAX_GREAD);
	}

	@Override
	public int test02(int a, int b) {
		// TODO Auto-generated method stub
		System.out.println("test02");
		return 0;
	}
	
}
