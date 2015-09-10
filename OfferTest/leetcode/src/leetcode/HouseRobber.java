package leetcode;

public class HouseRobber {
	 /*
	  * dp[0] = num[0] （当i=0时）
		dp[1] = max(num[0], num[1]) （当i=1时）
		dp[i] = max(num[i] + dp[i - 2], dp[i - 1]) （当i !=0 and i != 1时）
	  */
	public int rob(int[] nums) {
	      if(nums.length==0||nums==null) return 0;
	      int[]dp=new int[nums.length];
	      // dp[i]=max(num[i]+dp[i-2],dp[i-1])
          // dp[i]表示[0,i]取1个或多个不相邻数值的最大收益
	      if(nums.length==1) return nums[0];
	      if(nums.length==2) return Math.max(nums[0], nums[1]);
	      dp[0]=nums[0];
	      dp[1]=Math.max(nums[0], nums[1]);
	      
	      for(int i=2;i<nums.length;i++){
	    	  dp[i]=Math.max(nums[i]+dp[i-2], dp[i-1]);
	      }
	      
	      return dp[nums.length-1];
	 }
}
