package OfferSolution;

public class NumberOf1 {

	public int NumberOfone(int n){
		if(n<=0){
			return 0;
		}
		
		int count=0;
		int factor=1;
		while(n/factor!=0){
			int lowerNum=n-n/factor*factor;
			int currentNum=(n/factor)%10;
			int highNum=n/(factor*10);
			
			if(currentNum==0){
				//如果为0，出现1的次数由高位决定
				count+=highNum*factor;
			}else if(currentNum==1){
				//如果为1，出现1的次数由高位和低位决定
				count+=highNum*factor+lowerNum+1;
			}else{
				//如果大于1，出现1的次数由高位决定
				count+=(highNum+1)*factor;
			}
			factor*=10;
		}
		return count;
		
	}
	
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

}
