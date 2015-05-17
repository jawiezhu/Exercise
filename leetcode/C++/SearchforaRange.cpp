// Given a sorted array of integers, find the starting and ending position of a given target value.

// Your algorithm's runtime complexity must be in the order of O(log n).

// If the target is not found in the array, return [-1, -1].

// For example,
// Given [5, 7, 7, 8, 8, 10] and target value 8,
// return [3, 4].

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int len=nums.size();
        vector<int> res;
        int flag=0;
        for(int i=0;i<len;i++)
        {
        	if(target==nums[i])
        	{
        		res.push_back(i);
        		flag=1;
        		break;
        	}
        }

        if(flag==0)
        {
        	res.push_back(-1);
        }
        flag=0;
        for(int i=len-1;i>=0;i--)
        {
        	if(target==nums[i])
        	{
        		res.push_back(i);
        		flag=1;
        		break;
        	}
        }
        if(flag==0)
        {
        	res.push_back(-1);
        }


        return res;
    }
};




//二分找最左端，再二分找最右端。
class Solution {
public:
    int findPos(int a[], int beg, int end, int key, bool findLeft)
    {
        if (beg > end)
            return -1;
            
        int mid = (beg + end) / 2;
        
        if (a[mid] == key)
        {
            int pos = findLeft ? findPos(a, beg, mid - 1, key, findLeft) : findPos(a, mid + 1, end, key, findLeft);
            return pos == -1 ? mid : pos;
        }
        else if (a[mid] < key)
            return findPos(a, mid + 1, end, key, findLeft);
        else
            return findPos(a, beg, mid - 1, key, findLeft);       
    }
    
    vector<int> searchRange(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int leftPos = findPos(A, 0, n - 1, target, true);
        int rightPos = findPos(A, 0, n - 1, target, false);
        
        vector<int> ret;
        
        ret.push_back(leftPos);
        ret.push_back(rightPos);
        return ret;
    }
};




vector<int> searchRange(int A[], int n, int target) {
        vector<int> range(2,-1);
        int start = 0;
        int end = n - 1;
        while(start <= end) {
            int median = start + (end - start + 1) / 2;
            if(A[median] > target) {
                end = median - 1;
            }else if (A[median] < target) {
                start = median + 1;
            }else { //equals
                //go right
                int i = median + 1;
                for(; i <= end; i ++) {
                    if(A[i] != target){
                        range[1] = i - 1;
                        break;
                    }
                }
                if(range[1] == -1)
                    range[1] = i - 1;
                //go left
                i = median - 1;
                for(; i >= start; i --) {
                    if(A[i] != target){
                        range[0] = i + 1;
                        break;
                    }
                }
                if(range[0] == -1)
                    range[0] = i + 1;
                
                break;
            }
        }
        return range;
    }


// 1. 又是二分法
// 2. 二分法的框架, 需要考虑的位置有 3 个, 在代码中我标了出来, 分别为 q1, q2, q3
// 3. q1 是取 <= 还是取 <. 我的经验是, 若是题目要求找到 target, 那么就用 <=, 否则用 <. 我记得在二分搜索题时, 都是用 < 的
// 4. q2 比较容易, 考虑当 low == high 时, 我们希望游标往哪里走
// 5. q3, 返回 low/high. q3 的选取与 q2 有关. 还是需要考虑当 low == high 时, 游标会往哪走
class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        vector<int> res;
        if(n <= 0)
            return res;
 
        int leftIndex = lSearch(A, n, target);
        int rightIndex = rSearch(A, n, target);
         
        res.push_back(leftIndex);
        res.push_back(rightIndex);
        return res;
    }
 
    int lSearch(int A[], int n, int target) {
        int low = 0, high = n-1;
        while(low <= high) { // q1
            int mid = (low+high)>>1;
            if(A[mid] < target) { // q2
                low = mid+1;
            }else{
                high = mid-1;
            }
        }
        if(A[low] != target)
            return -1;
        return low; // q3
    }
    int rSearch(int A[], int n, int target) {
        int low = 0, high = n-1;
        while(low <= high) { // q1
            int mid = (low+high)>>1;
            if(A[mid] > target) { // q2
                high = mid-1;
            }else{
                low = mid +1;
            }
        }
        if(A[high] != target)
            return -1;
        return high; // q3
    }
};


// LeetCode, Search for a Range
// 偷懒的做法，使用STL
// 时间复杂度O(logn)，空间复杂度O(1)
class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        const int l = distance(A, lower_bound(A, A + n, target));
        const int u = distance(A, prev(upper_bound(A, A + n, target)));
        if (A[l] != target) // not found
            return vector<int> { -1, -1 };
        else
            return vector<int> { l, u };
    }
};


// LeetCode, Search for a Range
// 重新实现 lower_bound 和 upper_bound
// 时间复杂度O(logn)，空间复杂度O(1)
class Solution {
public:
    vector<int> searchRange (int A[], int n, int target) {
        auto lower = lower_bound(A, A + n, target);
        auto uppper = upper_bound(lower, A + n, target);

        if (lower == A + n || *lower != target)
            return vector<int> { -1, -1 };
        else
            return vector<int> {distance(A, lower), distance(A, prev(uppper))};
    }

    template<typename ForwardIterator, typename T>
    ForwardIterator lower_bound (ForwardIterator first,
            ForwardIterator last, T value) {
        while (first != last) {
            auto mid = next(first, distance(first, last) / 2);

            if (value > *mid)   first = ++mid;
            else                last = mid;
        }

        return first;
    }

    template<typename ForwardIterator, typename T>
    ForwardIterator upper_bound (ForwardIterator first,
            ForwardIterator last, T value) {
        while (first != last) {
            auto mid = next(first, distance (first, last) / 2);

            if (value >= *mid)   first = ++mid;  // 与 lower_bound 仅此不同
            else                 last = mid;
        }

        return first;
    }
};



