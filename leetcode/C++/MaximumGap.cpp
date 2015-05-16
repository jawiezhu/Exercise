// Given an unsorted array, find the maximum difference between the successive elements in its sorted form.

// Try to solve it in linear time/space.

// Return 0 if the array contains less than 2 elements.

// You may assume all elements in the array are non-negative integers and fit in the 32-bit signed integer range.

// Credits:
// Special thanks to @porker2008 for adding this problem and creating all test cases.

class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if(nums.size()<2) return 0;
        sort(nums.begin(),nums.end());	
        int max=0;
        for(int i=1;i<nums.size();i++)
        {
        	if(nums[i]-nums[i-1]>max)
        		max=nums[i]-nums[i-1];
        }
        return max;

    }
};


// 先排序O(nlogn)，再一次遍历，得到maxGap

// 虽然不满足O(n)的时间要求，但是最直观的想法。
class Solution {
public:
    int maximumGap(vector<int> &num) {
        if(num.empty() || num.size() < 2)
            return 0;
        sort(num.begin(), num.end());
        int maxGap = num[1]-num[0];
        for(int i = 2; i < num.size(); i ++)
        {
            int curGap = num[i]-num[i-1];
            maxGap = (maxGap>=curGap)?maxGap:curGap;
        }
        return maxGap;
    }
};

//为了满足O(n)复杂度 捅排序
class Solution {
public:
    int maximumGap(vector<int> &num) {
        if(num.empty() || num.size() < 2)
            return 0;
        int maxNum = *max_element(num.begin(), num.end());
        int minNum = *min_element(num.begin(), num.end());
        //average gap from minNum to maxNum.
        int gap = (maxNum - minNum - 1) / (num.size() - 1) + 1;
        //number of buckets
        int bucketNum = (maxNum-minNum)/gap;
        vector<int> bucketsMin(bucketNum, INT_MAX);
        vector<int> bucketsMax(bucketNum, INT_MIN);
        //put into buckets
        for(int i = 0; i < num.size(); i ++)
        {
            if(num[i] != maxNum && num[i] != minNum)
            {
                int buckInd = (num[i]-minNum)/gap;
                bucketsMin[buckInd] = min(bucketsMin[buckInd], num[i]);
                bucketsMax[buckInd] = max(bucketsMax[buckInd], num[i]);
            }
        }
        int maxGap = INT_MIN;
        int previous = minNum;
        for(int i = 0; i < bucketNum; i ++)
        {
            if(bucketsMin[i] == INT_MAX && bucketsMax[i] == INT_MIN)
                continue;   //empty
            //i_th gap is minvalue in i+1_th bucket minus maxvalue in i_th bucket 
            maxGap = max(maxGap, bucketsMin[i]-previous);
            previous = bucketsMax[i];
        }
        maxGap = max(maxGap, maxNum-previous);
        return maxGap;
    }
};


// 解题思路：桶排序http://bookshadow.com/weblog/2014/12/14/leetcode-maximum-gap/
// 假设有N个元素A到B。

// 那么最大差值不会小于ceiling[(B - A) / (N - 1)]， 根据鸽巢原理。

// 令bucket（桶）的大小len = ceiling[(B - A) / (N - 1)]，则最多会有(B - A) / len + 1个桶

// 对于数组中的任意整数K，很容易通过算式loc = (K - A) / len找出其桶的位置，然后维护每一个桶的最大值和最小值

// 由于同一个桶内的元素之间的差值至多为len - 1，因此最终答案不会从同一个桶中选择。

// 对于每一个非空的桶p，找出下一个非空的桶q，则q.min - p.max可能就是备选答案。返回所有这些可能值中的最大值。
class Solution {
public:
       int maximumGap(vector<int> &num) {
        if(num.size() < 2)
          return 0;
        int min_value = num[0];
        int max_value = num[0];
        for(vector<int>::iterator iter = num.begin(); iter != num.end(); iter++) {
            min_value = min(*iter, min_value);
            max_value = max(*iter, max_value);
        }
        int range = ceil(double(max_value - min_value) / (num.size() - 1));
        vector<vector<int> >buckets(num.size());
        for(vector<int>::iterator iter = num.begin(); iter != num.end(); iter++) {
            int index = (*iter - min_value) / range;
            if(buckets[index].empty()) {
                buckets[index].push_back(*iter);
                buckets[index].push_back(*iter);

            } else {
                if(*iter < buckets[index][0]) {
                    buckets[index][0] = *iter;
                }
                if(*iter > buckets[index][1]) {
                    buckets[index][1] = *iter;
                }
            }
        }
        int gap = 0;
         int pre = 0;
        for(int i = 1; i < buckets.size(); i++) {
            if(buckets[i].empty())
              continue;
            gap = max(gap, buckets[i][0] - buckets[pre][1]);
            pre = i;
        }
        return gap;
    }
};



class Solution {
public:
    // 用桶排序
    // 算出相邻两个桶之间的最大差值
    // 如果是平均分布，则桶的数目和元素的数目相同时，其排序的时间复杂度是0(n)
    // 我们假设桶的个数和元素的数目相同，若是平均分布，则每个桶里有一个数，而若某个桶里有两个以上的桶时，这时必有至少一个是空桶，那么最大间隔可能就落在空桶的相邻两个桶存储的数之间，最大间隔不会落在同一个桶的数里，因此我们不需要对每个桶再排一次序，只需要记录同一个桶的最大值和最小值，算出前一个有最大值的桶和后一个有最小值的桶之差，则可能是最大间隔
    //步骤：1.算好用的桶的个数，用最大元素和最小元素算出平均间隔，记录在平均间隔上的最大值和最小值，
    // 2. 再算出前一个间隔里的最大值和后一个间隔里的最小值之差，取最大的一个，
    // 3. 再算出最小值和第二小的差（平均间隔最小值第一个），最大值和第二大（平均间隔最大值最后一个）的差，三个值相比，取最大的，就是最大间隔
    int maximumGap(vector<int> &num) {
        if (num.size() < 2) return 0;
        // 1. 算出用的桶数：取平均间隔，再用最大值和最小值之差除以间隔，得到桶数
        // 因为假设所有值都是平均分布的时候，如此取桶数可得时间复杂度是0(n)
        auto maxVal = *max_element(num.begin(), num.end());
        auto minVal = *min_element(num.begin(), num.end());
        int agGap = ceil((double)(maxVal - minVal) / (num.size()-1)); // 平均间隔
        int bucketCount = ceil((double)(maxVal - minVal) / agGap);
        // 2. 记录每个桶的最大值和最小值
        vector<pair<int, int> > buckets(bucketCount, make_pair(INT_MIN, INT_MAX)); // 初始化桶
        for (auto val : num){
            if (val == maxVal || val == minVal) continue;
            int bucketNum = (val - minVal) / agGap;
            if (val > buckets[bucketNum].first) 
                buckets[bucketNum].first = val; // 存储最大值
            if (val < buckets[bucketNum].second) buckets[bucketNum].second = val; // 存储最小值
        }
        // 3. 算出最大间隔
        int maxGap(0), lastMax(minVal);
        for (auto bucket : buckets){
            if (bucket.first == INT_MIN) continue; // 空桶
            int curMax(bucket.first), curMin(bucket.second);
            maxGap = max(maxGap, curMin - lastMax);
            lastMax = curMax;
        }
        maxGap = max(maxGap, maxVal - lastMax);
        return maxGap;
    }
};


