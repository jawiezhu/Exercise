package MyException;
/*
 * 
 */
public class MyException extends Exception{
	public MyException(){
		super();
	}
	
	public MyException(String message){
		super(message);
	}
}

class TestMyException{
	
	void test()throws MyException{
		
	}
	public static void main(String[] args){
		try{
			new TestMyException().test();
		}catch(MyException e){
			e.printStackTrace();
		}
	}
}