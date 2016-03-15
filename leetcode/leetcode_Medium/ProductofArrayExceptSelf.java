package leetcode_Medium;

public class ProductofArrayExceptSelf {
	
	 public int[] productExceptSelf(int[] nums) {
		 	int right=1;
		 	
		 	int res[]=new int[nums.length];
		 	res[0]=1;
		 	for(int i=1;i<nums.length;i++){
		 		res[i]=res[i-1]*nums[i-1];
		 	}
		 	
		 	for(int i=nums.length-1;i>=0;i--){
		 		res[i]=res[i]*right;
		 		right*=nums[i];
		 	}
		 	
		 	return res;
	 }
	
	 public int[] productExceptSelf2(int[] nums) {
		    int[] result = new int[nums.length];
		    for (int i = 0, tmp = 1; i < nums.length; i++) {
		        result[i] = tmp;
		        tmp *= nums[i];
		    }
		    for (int i = nums.length - 1, tmp = 1; i >= 0; i--) {
		        result[i] *= tmp;
		        tmp *= nums[i];
		    }
		    return result;
		}
	 
	 
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

}
