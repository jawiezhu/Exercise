// You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

// Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.



// 其实就是在某个数组里面找一个序列， 序列里面的每一个元素都不能相邻，然后求其最大和

// 这个问题可以用dp的思想来考虑， 对于第n个房间我们所能有的选择是偷和不偷， 那么如果是做决定是偷 
// 则上一步必须是不偷 那么 这一步的就是 dp[N] = num[i -1 ] + dpNonTake[N -1] , 
// 假设dp[N] 表示的是有N个元素时候的最大值状态。 如果是不偷， 那么上一步就无所谓是不是已经偷过，
// 所以就copy为 dp[N] = dp[N -1 ]即可,所以总而言之为 dp[N] = Math.max(dpNontake[N-1 ] + num[i],dp[N-1]); 
// 因为每一轮迭代只需要触碰到dp 的相邻两个选项 所以可以空间压缩为 两个元素即可。
// 一个 为take 一个为 nontake 和 到当前的最大值。 那么迭代为：

// take = nonTake + num【i】;  偷
// nonTake = maxProfit;    不偷 0
// maxProfit = Math.max(take,nonTake); 求最大利润

// 时间复杂度为O(n) 空间为O(1) 
class Solution {
public:
    int rob(vector<int>& nums) {
        int take=0;
        int maxProfit=0;
        int nonTake=0;

        for(int i=0;i<nums.size();++i)
        {
        	take=nonTake+nums[i];
        	nonTake=maxProfit;
        	maxProfit=max(take,nonTake);
        }

        return maxProfit;
    }
};

class Solution {
public:
    int rob(vector<int>& nums)
    {
        if(nums.empty())return 0;

        int length = nums.size();
        vector<int> dp(length,0);

        dp[0] = nums[0];
        dp[1] = max(nums[0],nums[1]);

        for(int i =2; i< length; ++i)
        {
            dp[i] = max(dp[i-2]+nums[i],dp[i-1]);
        }

        return dp[length-1];

    }
};


//
// 动态规划，设置maxV[i]表示到第i个房子位置，最大收益。

// 递推关系为maxV[i] = max(maxV[i-2]+num[i], maxV[i-1])
class Solution {
public:
    int rob(vector<int> &num) {
        int n = num.size();
        if(n == 0)
            return 0;
        else if(n == 1)
            return num[0];
        else
        {
            vector<int> maxV(n, 0);
            maxV[0] = num[0];
            maxV[1] = max(num[0], num[1]);
            for(int i = 2; i < n; i ++)
                maxV[i] = max(maxV[i-2]+num[i], maxV[i-1]);
            return maxV[n-1];
        }
    }
};

//两个数组, 一个是包含最后一个字符的最大值, 一个是不包含最后一个字符的最大值. 更新两个数组, 最后求 max(d[n-1], b[n-1])即可.
// public class Solution {
//     public int rob(int[] num) {
//         //   31 23 9 13 49 1 0
//         //   0  0 0 0
//         if(num==null || num.length==0) return 0;

//         int n = num.length;

//         int [] b = new int[n]; //include last element;
//         int [] d = new int[n]; //exclude last element;

//         b[0] = num[0];
//         d[0] = 0;

//         for(int i=1; i<n; i++) {
//             b[i] = d[i-1] + num[i];
//             d[i] = Math.max(b[i-1], d[i-1]);
//         }

//         return Math.max(d[n-1], b[n-1]);
//     }
// }

// 这道题的本质相当于在一列数组中取出一个或多个不相邻数，使其和最大。
// 那么我们对于这类求极值的问题首先考虑动态规划Dynamic Programming来解，我们维护一个一位数组dp，
// 其中dp[i]表示到i位置时不相邻数能形成的最大和，
// 经过分析，我们可以得到递推公式dp[i] = max(num[i] + dp[i - 2], dp[i - 1]), 
// 由此看出我们需要初始化dp[0]和dp[1]，其中dp[0]即为num[0]，dp[1]此时应该为max(num[0], num[1])，代码如下：
// DP
class Solution {
public:
    int rob(vector<int> &num) {
        if (num.size() <= 1) return num.empty() ? 0 : num[0];
        vector<int> dp = {num[0], max(num[0], num[1])};
        for (int i = 2; i < num.size(); ++i) {
            dp.push_back(max(num[i] + dp[i - 2], dp[i - 1]));
        }
        return dp.back();
    }
};

//核心思想还是用DP，分别维护两个变量a和b，然后按奇偶分别来更新a和b，这样就可以保证组成最大和的数字不相邻，代码如下
class Solution {
public:
    int rob(vector<int> &num) {
        int a = 0, b = 0;
        for (int i = 0; i < num.size(); ++i) {
            if (i % 2 == 0) {
                a += num[i];
                a = max(a, b);
            } else {
                b += num[i];
                b = max(a, b);
            }
        }
        return max(a, b);
    }
};

