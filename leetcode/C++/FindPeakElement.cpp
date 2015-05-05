// A peak element is an element that is greater than its neighbors.
// Given an input array where num[i] ≠ num[i+1], find a peak element and return its index.
// The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.
// You may imagine that num[-1] = num[n] = -∞.
// For example, in array [1, 2, 3, 1], 3 is a peak element and your function should return the index number 2.
// click to show spoilers.
// Note:
// Your solution should be in logarithmic complexity.
// Credits:
// Special thanks to @ts for adding this problem and creating all test cases.



class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.size()==0) return NULL;

        for(int i=1;i<nums.size();i++)
        {
        	if(nums[0]>nums[1])
        		return 0;
        	if(nums[nums.size()-1]>nums[nums.size()-2])
        		return nums.size()-1;
        	if(nums[i]>nums[i-1]&&nums[i]>nums[i+1])
        		return i;
        }

        return NULL;
    }
};


// 求序列最大值。顺序查找或二分查找均可。
// 满足复杂度要求的话需要用二分查找。

//顺序查找
class Solution {
public:
    int findPeakElement(const vector<int> &num) {
        for(int i = 1; i < num.size(); i ++)
        {
            if(num[i] < num[i-1])
            {// <
                return i-1;
            }
        }
        return num.size()-1;
    }
};

//二分查找 递归
class Solution {
public:
    int findPeakElement(const vector<int> &num) {
        return Helper(num, 0, num.size()-1);
    }
    int Helper(const vector<int> &num, int low, int high)
    {
        if(low == high)
            return low;
        else
        {
            int mid1 = (low+high)/2;
            int mid2 = mid1+1;
            if(num[mid1] > num[mid2])
                return Helper(num, low, mid1);
            else
                return Helper(num, mid2, high);
        }
    }
};

//二分查找（迭代）
class Solution {
public:
    int findPeakElement(const vector<int> &num) 
    {
        int low = 0;
        int high = num.size()-1;
        
        while(low < high)
        {
            int mid1 = (low+high)/2;
            int mid2 = mid1+1;
            if(num[mid1] < num[mid2])
                low = mid2;
            else
                high = mid1;
        }
        return low;
    }
};
