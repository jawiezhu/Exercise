// Given an array of non-negative integers, you are initially positioned at the first index of the array.

// Each element in the array represents your maximum jump length at that position.

// Your goal is to reach the last index in the minimum number of jumps.

// For example:
// Given array A = [2,3,1,1,4]

// The minimum number of jumps to reach the last index is 2. (Jump 1 step from index 0 to 1, then 3 steps to the last index.)
class Solution {
public:
    int jump(vector<int>& nums) {
        int result=0;

        int last=0;

        int cur=0;

        for(int i=0;i<nums.size();i++)
        {
        	if(i>last)
        	{
        		last=cur;
        		result++;
        	}
        	cur=max(cur,i+nums[i]);
        }

        return result;
    }
};


//
/* 
 * We use "last" to keep track of the maximum distance that has been reached 
 * by using the minimum steps "ret", whereas "curr" is the maximum distance 
 * that can be reached by using "ret+1" steps. Thus, 
 * curr = max(i+A[i]) where 0 <= i <= last. 
 */  
class Solution {  
public:  
    int jump(int A[], int n) {  
        int ret = 0;//当前跳数  
        int last = 0;//上一跳可达最远距离  
        int curr = 0;//当前一跳可达最远距  
        for (int i = 0; i < n; ++i) {  
            //无法向前继跳直接返回  
            if(i>curr){  
                return -1;  
            }  
            //需要进行下次跳跃，则更新last和当执行的跳数ret  
            if (i > last) {  
                last = curr;  
                ++ret;  
            }  
            //记录当前可达的最远点  
            curr = max(curr, i+A[i]);  
        }  
  
        return ret;  
    }  
};  


// LeetCode, Jump Game II
// 时间复杂度O(n)，空间复杂度O(1)
class Solution {
public:
    int jump(int A[], int n) {
        int step = 0; // 最小步数
        int left = 0;
        int right = 0;  // [left, right]是当前能覆盖的区间
        if (n == 1) return 0;

        while (left <= right) { // 尝试从每一层跳最远
            ++step;
            const int old_right = right;
            for (int i = left; i <= old_right; ++i) {
                int new_right = i + A[i];
                if (new_right >= n - 1) return step;

                if (new_right > right) right = new_right;
            }
            left = old_right + 1;
        }
        return 0;
    }
};



