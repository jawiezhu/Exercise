package OfferSolution;

public class Fibonacci {

	public int Fibo(int n){
		
		int[] res={1,2};
		if(n<2)
		{
			return res[n];
		}
		
		int fibN=0;
		int fibNMinusOne=1;
		int fibNMinusTwo=0;
		for(int i=2;i<n;i++){
			fibN=fibNMinusOne+fibNMinusTwo;
			fibNMinusTwo=fibNMinusOne;
			fibNMinusOne=fibN;
		}
		return fibN;
		
	}
	
	
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

}
