package OfferSolution;

public class Accumulate {
	static int sum=0;
	public static boolean and(int n){
		sum+=n;
		return (n>0) && and(n-1);
	}
	
	public static void main(String[] args){
		and(100);
		System.out.println(sum);
	}
}
