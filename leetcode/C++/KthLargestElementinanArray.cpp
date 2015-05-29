// Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.

// For example,
// Given [3,2,1,5,6,4] and k = 2, return 5.

// Note: 
// You may assume k is always valid, 1 ≤ k ≤ array's length.

// Credits:
// Special thanks to @mithmatt for adding this problem and creating all test cases.

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int len=nums.size();

        return nums[len-k];
    }
};


//利用快排的思想，平均时间复杂度O(n)，4ms AC。
//最坏情况下会退化成O(n^2)，比如说数组是从小到大排好序的而要找的是最大值。非递归，空间复杂度O(1)。
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int L = 0, R = nums.size() - 1;
        while (L < R) {
            int left = L, right = R;
            int key = nums[left];
            while (left < right) {
                while (left < right && nums[right] < key) --right;
                nums[left] = nums[right];
                while (left < right && nums[left] >= key) ++left;
                nums[right] = nums[left];
            }
            nums[left] = key;
            if (left == k - 1) return nums[k - 1];
            else if (left > k - 1) R = left - 1;
            else L = left + 1;
        }
        return nums[k - 1];
    }
};

//
class Solution {
public:
    int visit(vector<int> &nums, int k, int left, int right)
    {
	    int pivot = nums[right];
	    int p = left-1;
	    int q = left;
	    while (q < right)
	    {
		    if (nums[q] < pivot)
		    {
			    p++;
			    swap(nums[p], nums[q]);
		    }
		    q++;
	    }

	    swap(nums[p+1], nums[right]);

	    if (p+1 == k)
	    {
		    return p+1;
	    }
	    else if (p+1 > k)
	    {
		    return visit(nums, k, left, p); 
	    }
	    else
	    {
		    return visit(nums, k, p+2, right);
	    }
    }
    
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
	    k = n - k;
	    int index = visit(nums, k, 0, n-1);

	    return nums[index];
    }
};

//O(n)解法：快速选择算法
// import random
// class Solution:
//   # @param {integer[]} nums
//   # @param {integer} k
//   # @return {integer}
//   def findKthLargest(self, nums, k):
//     pivot = random.choice(nums)
//     nums1, nums2 = [], []
//     for num in nums:
//       if num > pivot:
//         nums1.append(num)
//       elif num < pivot:
//         nums2.append(num)
//     if k <= len(nums1):
//       return self.findKthLargest(nums1, k)
//     if k > len(nums) - len(nums2):
//       return self.findKthLargest(nums2, k - (len(nums) - len(nums2)))
//     return pivot
//

 class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int length = nums.size();
        if (length == 1) {
            return nums[0];
        }
        vector<int> left;
        vector<int> right;
        
        for (int index=1; index<length; index++) {
            if (nums[index] > nums[0]) {
                right.push_back(nums[index]);
            }else{
                left.push_back(nums[index]);
            }
        }
        length = right.size();
        if (length >=k) {
            return findKthLargest(right, k);
        }else if(length == k-1){
            return nums[0];
        }else{
            return findKthLargest(left, k-length-1);
        }
    }
};



//类似于快排，但是我们每次只需要排一半的元素，算法总体的运算次数为n(1+1/2+...+1/n)=2n(1-(1/2)^logn)，O(n)。
//LeetCode的运行时间仅为4ms
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        quickSortVariant(nums, nums.size() - k, 0, nums.size() - 1);
        return nums[nums.size() - k];
    }
    
    int getRand(int start, int end){
        if(end < start) {
            return 0;
        }
        srand((unsigned)time(0));
        return rand()%(end-start+1) + start;
    }
    
    int swap(vector<int>& nums, int i, int j){
        int temp = nums[i];
        nums[i]=nums[j];
        nums[j]=temp;
    }
    
    void quickSortVariant(vector<int>& nums, int k, int start, int end){
        int flag = getRand(start, end); //找到一个标记元素
        swap(nums, start, flag);
        int flagNum = nums[start];
        int i=start, j=end;
        while(i<j){
            while(j>i&&nums[j]>=flagNum){
                j--;
            }
            nums[i]=nums[j];
            while(j>i&&nums[i]<=flagNum){
                i++;
            }
            nums[j]=nums[i];
        }
        nums[i]=flagNum;
        if(i>k){
            quickSortVariant(nums, k, start, i - 1);
        }else if(i<k){
            quickSortVariant(nums, k, i+1, end);
        }
    }
};


