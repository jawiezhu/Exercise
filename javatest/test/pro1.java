package test;

public class pro1 {
	
	/**
	 * @author JawieZhu
	 * @param
	 * @param a
	 * @param b
	 */
	public static void add(int a,int b){
		int sum=a+b;
		System.out.println(sum);
	}
	
	public static void multi(int a,int b){
		int res=a*b;
		System.out.println(res);
	}
	
	public static void main(String[] args){
		int sum=0;
//		for(int i=1;i<1000;i++)
//		{
//			if(i%3==0||i%5==0)
//			{
//				sum=sum+i;
//			}
//		}
		
		//System.out.println(sum);
		
		add(3,5);
		multi(2,10);
	}
}
