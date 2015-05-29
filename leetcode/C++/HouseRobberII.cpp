// Note: This is an extension of House Robber.
// After robbing those houses on that street, the thief has found himself a new place for 
// his thievery so that he will not get too much attention. This time, all houses at this place are arranged in a circle.
//  That means the first house is the neighbor of the last one. Meanwhile, 
// the security system for these houses remain the same as for those in the previous street.
// Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.


class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        return max(robbing(nums,0,nums.size()-1),robbing(nums,1,nums.size()));
    }

    int robbing(vector<int> &nums,int left,int right)
    {
    	int take=0;
    	int maxProfit=0;
    	int nonTake=0;
    	for(int i=left;i<right;i++)
    	{
    		take=nonTake+nums[i];
    		nonTake=maxProfit;
    		maxProfit=max(take,nonTake);
    	}

    	return maxProfit;
    }
};





//讨论是否抢劫第一件房屋。如果是，则不可以抢最后一件房屋。否则，可以抢最后一间房屋。
// 以此为依据，将环形DP问题转化为两趟线性DP问题，可以复用 House Robber 的代码。
// 另外需要特判一下只有一件房屋的情形。
//
class Solution:
  # @param {integer[]} nums
  # @return {integer}
  def rob(self, nums):
    if len(nums) == 1:
      return nums[0]
    return max(self.robLinear(nums[1:]), self.robLinear(nums[:-1]))
  # @param num, a list of integer
  # @return an integer
  def robLinear(self, num):
    size = len(num)
    odd, even = 0, 0
    for i in range(size):
      if i % 2:
        odd = max(odd + num[i], even)
      else:
        even = max(even + num[i], odd)
    return max(odd, even)

//


// 现在房子排成了一个圆圈，则如果抢了第一家，就不能抢最后一家，因为首尾相连了，
// 所以第一家和最后一家只能抢其中的一家，或者都不抢，那我们这里变通一下，如果我们把第一家和最后一家分别去掉，
// 各算一遍能抢的最大值，然后比较两个值取其中较大的一个即为所求。那我们只需参考之前的House Robber 打家劫舍中的解题方法，
// 然后调用两边取较大值，代码如下：
    // DP
class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() <= 1) return nums.empty() ? 0 : nums[0];
        return max(rob(nums, 0, nums.size() - 1), rob(nums, 1, nums.size()));
    }
    int rob(vector<int> &nums, int left, int right) {
        if (right - left <= 1) return nums[left];
        vector<int> dp(right, 0);
        dp[left] = nums[left];
        dp[left + 1] = max(nums[left], nums[left + 1]);
        for (int i = left + 2; i < right; ++i) {
            dp[i] = max(nums[i] + dp[i - 2], dp[i - 1]);
        }
        return dp.back();
    }
};

class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() <= 1) return nums.empty() ? 0 : nums[0];
        return max(rob(nums, 0, nums.size() - 1), rob(nums, 1, nums.size()));
    }
    int rob(vector<int> &nums, int left, int right) {
        int a = 0, b = 0;
        for (int i = left; i < right; ++i) {
            int m = a, n = b;
            a = n + nums[i];
            b = max(m, n);
        }
        return max(a, b);
    }
};

//House Robber I的升级版. 因为第一个element 和最后一个element不能同时出现. 
//则分两次call House Robber I. case 1: 不包括最后一个element. case 2: 不包括第一个element.
//两者的最大值即为全局最大值
public class Solution {
    //1 2 3
    public int rob(int[] nums) {
        if(nums==null || nums.length==0) return 0;
        if(nums.length==1) return nums[0];
        if(nums.length==2) return Math.max(nums[0], nums[1]);
        return Math.max(robsub(nums, 0, nums.length-2), robsub(nums, 1, nums.length-1));
    }
    
    private int robsub(int[] nums, int s, int e) {
        int n = e - s + 1;
        int[] d =new int[n];
        d[0] = nums[s];
        d[1] = Math.max(nums[s], nums[s+1]);
        
        for(int i=2; i<n; i++) {
            d[i] = Math.max(d[i-2]+nums[s+i], d[i-1]);
        }
        return d[n-1];
    }
}//

// Basic ideas:
// 　　1. Run original DP twice, 1st with num[0] selected, 2nd with num[0] not selected
// 　　2. Since it is circular arrangement, if 1st is assumed to be selected, we should not consider the last element
class Solution {
public:
    int _rob(vector<int> &num) {
        size_t len = num.size();

        int inc = num[0];
        int exc = 0;
        for (int i = 1; i < len - 1; i++) // Note: we skipped the last element
        {
            int old_inc = inc;
            inc = num[i] + exc;
            exc = std::max(exc, old_inc);
        }

        return std::max(inc, exc);
    }

    int rob(vector<int> &num) {
        size_t len = num.size();
        if (len == 0) return 0;

        // num[0] is selected
        int rob1 = _rob(num);

        // num[0] is not selected
        vector<int> in2;
        in2.insert(in2.end(), num.begin() + 1, num.end());
        in2.push_back(num[0]);
        int rob2 = _rob(in2);
        
        return std::max(rob1, rob2);
    }
};




//
class Solution {
public:
    int rob(vector<int> &num) {
        if (num.size() == 0) return 0;
        if (num.size() == 1) return num[0];
        vector<int> dp(num.size());
        //抢第一家到倒数第二家的最大值
        dp[0] = num[0];
        for (int i = 1; i < num.size() - 1; ++i)
            dp[i] = max(dp[i-1], (i == 1 ? 0 : dp[i-2]) + num[i]);
        int res = dp[num.size()-2];
        //抢第二家到最后一家的最大值
        dp[1] = num[1];
        for (int i = 2; i < num.size() ; ++i)
            dp[i] = max(dp[i-1], (i == 2 ? 0 : dp[i-2]) + num[i]);
        //返回两者较大的一个    
        return max(res, dp[num.size()-1]);
    }
};


