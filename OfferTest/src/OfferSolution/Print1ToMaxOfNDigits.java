package OfferSolution;

import java.math.BigDecimal;

public class Print1ToMaxOfNDigits {

	public static void solution(int n){
		if(n<=0) return;
		BigDecimal res=new BigDecimal("1");
		
		for(int i=0;i<n;i++){
			res=res.multiply(new BigDecimal(Integer.toString(10)));
		}
		
		BigDecimal cnt=new BigDecimal("999999999999998");
		
		for(;cnt.intValue()<res.intValue();){
			System.out.println(cnt.toString());
			cnt=cnt.add(new BigDecimal("1"));	
		}	
	}
	
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		solution(15);
	}

}
