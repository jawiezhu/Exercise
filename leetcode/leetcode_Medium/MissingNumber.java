package leetcode_Medium;

import java.util.Arrays;

public class MissingNumber {
	
	 public int missingNumber(int[] nums) {
		 int sum=0;
		 for(int i=0;i<nums.length;i++){
			 sum=sum+nums[i];
		 }
		 
		 int n=nums.length;
		 int sum2=(n+1)*n/2;
		 return sum2-sum;
	 }
	
	 public int missingNumber2(int[] nums) {

		    int xor = 0, i = 0;
		    for (i = 0; i < nums.length; i++) {
		        xor = xor ^ i ^ nums[i];
		    }

		    return xor ^ i;
		}
	 
	 public int missingNumber3(int[] nums) { //xor
		    int res = nums.length;
		    for(int i=0; i<nums.length; i++){
		        res ^= i;
		        res ^= nums[i];
		    }
		    return res;
		}
//	 If anyone needs explanation for XOR solution, a number XOR itself will become 0, 
//	 any number XOR with 0 will stay unchanged. So if every number from 1...n XOR with itself except 
//	 the missing number, the result will be the missing number.
//
//	 Example: 1..4 missing 3
//
//	  1^2  ^4 
//	 ^1^2^3^4 
//	 ----------- 
//	  0^0^3^0 => 3
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

}
