package leetcode_Easy;

public class PlusOne {
	public int[] plusOne(int[] digits) {
        
		int carry=1;
		int tmp;
		for(int i=digits.length-1;i>=0;i--){
			tmp=digits[i];
			digits[i]=(tmp+carry)%10;
			carry=(tmp+carry)/10;
			
			if(carry==0)
				break;
		}
		
		if(carry==1){
			int[] res=new int[digits.length+1];
			System.arraycopy(digits, 0, res, 1, digits.length);
			res[0]=carry;
			return res;
		}else{
			return digits;
		}
    }
}
