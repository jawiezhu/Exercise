package leetcode;

public class AddDigits {

	public static int addDigits(int num) {
        int sum=10;
        while(sum>9){
        	sum=0;
        	while(num>0){
        		sum=sum+num%10;
        		num=num/10;
        	}
        	num=sum;
        }
        return sum;
    }
	
	
	public static int addDigits2(int num){
		while(num>=10){
			num=(num/10)+num%10;
		}
		return num;
	}
	
	public static int addDigits3(int num){
		if(num==0) return 0;
		if(num%9==0) return 9;
		
		return num%9;
	}
	
	public static int addDigits4(int num){
		return 1+(num-1)%9;
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		System.out.println(addDigits(0));

	}

}
