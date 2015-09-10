package leetcode;

public class HouseRobberII {
	public int rob(int[] nums) {
        if(nums==null||nums.length==0) return 0;
        if(nums.length==1) return nums[0];
      //��һ������û�б�͵������Դӵڶ�������͵�����һ�����ӣ�����֮�������ԵĶ�̬�滮���
        //dp[i]��ʾ����i�����ӣ�С͵û�þ�������ʱ��ȡ�����Ǯ��
        int[] dp1=new int[nums.length];
        dp1[0]=0;
        dp1[1]=nums[1];
        for(int i=2;i<nums.length;i++){
        	dp1[i]=Math.max(dp1[i-2]+nums[i], dp1[i-1]);
        }
      //��һ�����ӱ�͵����ڶ��������һ�����Ӳ��ܱ�͵����ӵ��������ӵ��������һ������֮�������Զ�̬�滮���
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
