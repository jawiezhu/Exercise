package OfferSolution;

public class Power {

	public static double Power(double base,int exponent){
		
		double res=1.0;
		
		if(exponent==0)
			return 0.0;
		
		if(exponent>0){
			for(int i=0;i<exponent;i++){
				res=res*base;
			}
			return res;
		}
		
		if(exponent<0){
			for(int i=0;i<-exponent;i++){
				res=res*base;
			}

		}
		
		return 1/res;
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		System.out.println(Power(2,2));
	}

}
