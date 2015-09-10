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
				//���Ϊ0������1�Ĵ����ɸ�λ����
				count+=highNum*factor;
			}else if(currentNum==1){
				//���Ϊ1������1�Ĵ����ɸ�λ�͵�λ����
				count+=highNum*factor+lowerNum+1;
			}else{
				//�������1������1�Ĵ����ɸ�λ����
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
