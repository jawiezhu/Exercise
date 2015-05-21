// Given an array of non-negative integers, you are initially positioned at the first index of the array.

// Each element in the array represents your maximum jump length at that position.

// Determine if you are able to reach the last index.

// For example:
// A = [2,3,1,1,4], return true.

// A = [3,2,1,0,4], return false.


class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size()==0||nums.size()==1) return true;

        int maxstep=nums[0];

        for(int i=1;i<nums.size();i++)
        {
        	if(maxstep==0) return false;

        	maxstep--;
        	if(maxstep<nums[i])
        		maxstep=nums[i];

        	if(maxstep+i>=nums.size()-1) return true;
        }
    }
};


// 贪心,只需要时刻计算前位置和当前位置所能跳的最远长度,并始终和n作比较就可以:

// 1,若在任意pos位置出现maxstep为0的情况,则说明无法继续向前移动,返回false

// 2.若在任意pos位置出现maxstep+pos>=n说明可以完成最后一跳,返回true


//用贪心策略，刚开始step = A[0]，到下一步step--, 并且取step = max(step, A[1])，这样step一直是保持最大的能移动步数，局部最优也是全局最优。
class Solution {
public:
    bool canJump(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (n == 0)
            return false;
            
        int step = A[0];
        
        for(int i = 1; i < n; i++)
            if (step > 0)
            {
                step--;
                step = max(step, A[i]);
            }
            else
                return false;
                
        return true;
    }
};


//
// 由于每层最多可以跳{A[i]}步，也可以跳0或1步，因此如果能到达最高层，则说明每一层都可以到达。有了这个条件，说明可以用贪心法。

// 思路一：正向，从0出发，一层一层网上跳，看最后能不能超过最高层，能超过，说明能到达，否则不能到达。

// 思路二：逆向，从最高层下楼梯，一层一层下降，看最后能不能下降到第0层。

// 思路三：如果不敢用贪心，可以用动规，设状态为{f[i]}，表示从第0层出发，走到{A[i]}时剩余的最大步数，则状态转移方程为：
// f[i]=max(f[i−1],A[i−1])−1,i>0

// LeetCode, Jump Game
// 思路1，时间复杂度O(n)，空间复杂度O(1)
class Solution {
public:
    bool canJump(int A[], int n) {
        int reach = 1; // 最右能跳到哪里
        for (int i = 0; i < reach && reach < n; ++i)
            reach = max(reach,  i + 1 + A[i]);
        return reach >= n;
    }
};


// LeetCode, Jump Game
// 思路2，时间复杂度O(n)，空间复杂度O(1)
class Solution {
public:
    bool canJump (int A[], int n) {
        if (n == 0) return true;
        // 逆向下楼梯，最左能下降到第几层
        int left_most = n - 1;

        for (int i = n - 2; i >= 0; --i)
            if (i + A[i] >= left_most)
                left_most = i;

        return left_most == 0;
    }
};


// LeetCode, Jump Game
// 思路三，动规，时间复杂度O(n)，空间复杂度O(n)
class Solution {
public:
    bool canJump(int A[], int n) {
        vector<int> f(n, 0);
        f[0] = 0;
        for (int i = 1; i < n; i++) {
            f[i] = max(f[i - 1], A[i - 1]) - 1;
            if (f[i] < 0) return false;;
        }
        return f[n - 1] >= 0;
    }
};


