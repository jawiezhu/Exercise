package leetcode_Medium;

public class SingleNumber {
	public int singleNumber(int[] nums){
		if(nums==null||nums.length==0)
			return 0;
		
		int temp=0;
		int len=nums.length;
		
		for(int i=0;i<len;i++){
			temp=temp^nums[i];
		}
		
		return temp;
	}
}
