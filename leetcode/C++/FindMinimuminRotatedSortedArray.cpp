
// Suppose a sorted array is rotated at some pivot unknown to you beforehand.

// (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

// Find the minimum element.

// You may assume no duplicate exists in the array.



class Solution {
public:
    int findMin(vector<int> &num) {
        sort(num.begin(),num.end());
        return num[0];
    }
};

class Solution {
public:
    int findMin(vector<int>& nums) {
        int size=nums.size()-1;
        int l=0;
        int r=size;
        while(l<=r){
        	int mid=l+(r-l)/2;
        	if(nums[mid]>nums[size]){
        		l=mid+1;
        	}else{
        		r=mid-1;
        	}
        }
        return nums[l];
		
    }
};



private static int search2(int[] A, int target){
        int lo = 0;
        int hi = A.length - 1;
        while(lo <= hi){
            int mid = lo + (hi - lo)/2;
            if(target == A[mid]) return mid;
            if(A[mid] > lo){
                if(target >= lo && target < A[mid]){
                    hi = mid - 1;
                }else {
                    lo = mid + 1;
                }
            }else {
                if(target <= hi && target > A[mid]){
                    lo = mid + 1;
                }else {
                    hi = mid -1;
                }
            }
        }
        return -1;
    }