package leetcode;

public class HouseRobberII {
	public int rob(int[] nums) {
        if(nums==null||nums.length==0) return 0;
        if(nums.length==1) return nums[0];
      //第一个房子没有被偷，则可以从第二个房子偷到最后一个房子，在这之间用线性的动态规划求解
        //dp[i]表示到第i个房子，小偷没用惊动警察时获取的最大钱数
        int[] dp1=new int[nums.length];
        dp1[0]=0;
        dp1[1]=nums[1];
        for(int i=2;i<nums.length;i++){
        	dp1[i]=Math.max(dp1[i-2]+nums[i], dp1[i-1]);
        }
      //第一个房子被偷，则第二个和最后一个房子不能被偷，则从第三个房子到倒数最后一个房子之间用线性动态规划求解
        int[] dp2=new int[nums.length];
        dp2[0]=nums[0];
        dp2[1]=nums[0];
        for(int i=2;i<nums.length-1;i++){
        	dp2[i]=Math.max(dp2[i-2]+nums[i],dp2[i-1]);
        }
        
        return Math.max(dp1[nums.length-1], dp2[nums.length-2]);
    }
	
	
	public int rob2(int[] nums){
		int n=nums.length;
		if(n==0) return 0;
		if(n==1) return nums[0];
		return Math.max(robRange(nums,0,n-2), robRange(nums,1,n-1));
	}
	
	 public int robRange(int[] nums, int start, int end){
		 int prepre=0;
		 int pre=nums[start];
		 for(int i=start+1;i<=end;i++){
			 int cur=Math.max(prepre+nums[i], pre);
			 prepre=pre;
			 pre=cur;
		 }
		 
		 return pre;
	 }
}
