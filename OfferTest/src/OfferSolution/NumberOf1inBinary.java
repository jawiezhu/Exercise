package OfferSolution;

public class NumberOf1inBinary {

	public static int NumberOne(int n){
		int cnt=0;
		while(n>0){
			
			if((n & 1)==1 )
				cnt++;
			
			n=n>>1;
		}
		return cnt;
	}
	
	public static int NumberOne2(int n){
		int cnt=0;
		int flag=1;
		
		while(flag<(2^32)){
			
			if((n & flag)>0 )
				cnt++;
			
			flag=flag<<1;
		}
		return cnt;
	}
	
	
	public static int NumberOne3(int n){
		int cnt=0;
		
		
		while(n>0){
			cnt++;
			n=(n-1)&n;
		}
		return cnt;
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		System.out.println(NumberOne3(9));
	}

}
