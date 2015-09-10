package Generic2;

import java.io.Closeable;

public class TestMethod {
	
	public static <T> void test(T a){
		System.out.println(a);
	}
	
	public static <T extends Closeable> void test(T... a){
		
	}
}
