// Follow up for "Find Minimum in Rotated Sorted Array":
// What if duplicates are allowed?

// Would this affect the run-time complexity? How and why?
// Suppose a sorted array is rotated at some pivot unknown to you beforehand.

// (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

// Find the minimum element.

// The array may contain duplicates.


// 暴力解法，直接使用algorithm库中的求最小元素函数
// 需要遍历整个vector
class Solution {
public:
    int findMin(vector<int> &num) {
        if(num.empty())
            return 0;
        vector<int>::iterator iter = min_element(num.begin(), num.end());
        return *iter;
    }
};


// 利用sorted这个信息。如果平移过，则会出现一个gap，也就是从最大元素到最小元素的跳转。
// 如果没有跳转，则说明没有平移。
// 比上个解法可以省掉不少时间，平均情况下不用遍历vector了。
class Solution {
public:
    int findMin(vector<int> &num) {
        if(num.empty())
            return 0;
        else if(num.size() == 1)
            return num[0];
        else
        {
            for(vector<int>::size_type st = 1; st < num.size(); st ++)
            {
                if(num[st-1] > num[st])
                    return num[st];
            }
            return num[0];
        }
    }
};


// 二分查找
// 对于重复元素，只要low++即可。
// 注意：如果已经排好序，那么low元素即为最小值
class Solution {
public:
    int findMin(vector<int> &num) {
        int low = 0;
        int high = num.size()-1;
        while(low < high)
        {
            if(num[low] < num[high])
            //sorted
                return num[low];

            int mid = low + (high-low)/2;   //instead of (low+high)/2 to prevent overflow
            if(num[low] == num[mid])
            {
                if(low+1 == high)
                {//low+1==high
                    if(num[low]>num[high])
                        low = high;
                    break;
                }
                else
                    low ++;
            }
            else if(num[low] < num[mid])
                low = mid;
            else
                high = mid; //mid may be the minimum, thus not mid-1
        }
        return num[low];
    }
};

//
// 当数组中存在大量的重复数字时，
// 就会破坏二分查找法的机制，我们无法取得O(lgn)的时间复杂度，
// 又将会回到简单粗暴的O(n)，比如如下两种情况：

// {2, 2, 2, 2, 2, 2, 2, 2, 0, 1, 1, 2} 
// 和 {2, 2, 2, 0, 2, 2, 2, 2, 2, 2, 2, 2}，
//  我们发现，当第一个数字和最后一个数字，还有中间那个数字全部相等的时候，
//  二分查找法就崩溃了，因为它无法判断到底该去左半边还是右半边。
//  这种情况下，我们只能回到最原始的那种简单粗暴的方法，把整个数组从头到尾撸一遍，
//  找出最小的那个。代码如下：
class Solution {
public:
    int findMin(vector<int> &num) {
        if (num.size() <= 0) return 0;
        if (num.size() == 1) return num[0];

        int left = 0, right = num.size() - 1;
        if (num[left] > num[right]) {
            while (left != (right - 1)) {
                int mid = (left + right) / 2;
                if (num[left] <= num[mid]) left = mid;
                else right = mid;
            }
            return min(num[left], num[right]);
        } else if (num[left] == num[right]) {
            int res = num[0];
            for (int i = 1; i < num.size(); ++i) {
                res = min(res, num[i]);
            }
            return res;
        }
        return num[0];
    }
};

