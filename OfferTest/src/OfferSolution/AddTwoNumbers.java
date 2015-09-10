package OfferSolution;

public class AddTwoNumbers {
	
	public int Add(int num1,int num2){
		int sum,carry;
		do{
			sum=num1^num2;
			// x&y的某一位是1说明，它是它的前一位的进位，所以向左移动一位
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
