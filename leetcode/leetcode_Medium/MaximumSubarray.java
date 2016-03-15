package leetcode_Medium;

public class MaximumSubarray {
	/**
	 * global[i]（全局最优）和local[i]（局部最优）
	 * 那么第i+1步的表达式是：
local[i+1]=Math.max(A[i], local[i]+A[i])，
就是局部最优是一定要包含当前元素，所以不然就是上一步的局部最优local[i]+当前元素A[i]
（因为local[i]一定包含第i个元素，所以不违反条件），
但是如果local[i]是负的，那么加上他就不如不需要的，
所以不然就是直接用A[i]；

global[i+1]=Math(local[i+1],global[i])，
有了当前一步的局部最优，那么全局最优就是当前的局部最优或者还是原来的全局最优
（所有情况都会被涵盖进来，因为最优的解如果不包含当前元素，
那么前面会被维护在全局最优里面，如果包含当前元素，那么就是这个局部最优）。
	 * @param nums
	 * @return
	 */
	public int maxSubArray(int[] nums) {
        if(nums==null || nums.length==0) return 0;
        int local=nums[0];
        int global=nums[0];
        for(int i=0;i<nums.length;i++){
        	local=Math.max(nums[i], local+nums[i]);
        	global=Math.max(local, global);
        }
        
        return global;
    }
	
	
	
	/*
	 * 动态规划问题，已知了前k个元素的最大子序列和为maxSub
	 *已经被记录下来了，以及一个临时和sum，如果添加了第k+1这个元素，由于是连续子序列这个限制，
	 * 所以如果k+1这个元素之前的和是小于0的，那么对于增大k+1这个元素从而去组成最大子序列是没有贡献的，
	 * 所以可以把sum 置0。 
	 */
	public int maxSubArray2(int[] nums) {
		if (nums == null || nums.length < 1) {
            throw new IllegalArgumentException();
        }
		
		int max=Integer.MIN_VALUE;
		int curSum=0;
		
		for(int i:nums){
			// 当前和小于0，就将当前值赋给curSum
			if(curSum<=0){
				curSum=i;
			}else{// 否则进行累加
				curSum+=i;
			}
			// 保存较大的值
			if(max<curSum){
				max=curSum;
			}
		}
		return max;
    }
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

}
