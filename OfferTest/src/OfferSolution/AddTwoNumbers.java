package OfferSolution;

public class AddTwoNumbers {
	
	public int Add(int num1,int num2){
		int sum,carry;
		do{
			sum=num1^num2;
			// x&y��ĳһλ��1˵������������ǰһλ�Ľ�λ�����������ƶ�һλ
			carry=(num1&num2)<<1;
			
			num1=sum;
			num2=carry;
		}while(num2!=0);
		return num1;
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

}
