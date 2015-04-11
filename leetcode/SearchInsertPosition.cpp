// Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

// You may assume no duplicates in the array.

// Here are few examples.
// [1,3,5,6], 5 → 2
// [1,3,5,6], 2 → 1
// [1,3,5,6], 7 → 4
// [1,3,5,6], 0 → 0

// 常规解法:O(n)
class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        if(n==0) return NULL;
        int i=0;
        for(i=0;i<n;i++)
        {
            if(target<=A[i])
                return i;
        }
        return i;
    }
};

//二分法:O(logn) 必须为有序数组
class Solution {
public:
    int searchInsert(int A[], int n, int target) {
       int start=0;
       int end=n-1;
       int index=(start+end)/2;
       while(start<end)
       {
       		if(A[index]>target)
       		{
       			end=index-1;
       			index=(start+end)/2;
       		}else if(A[index]<target){
       			start=index+1;
       			index=(start+end)/2;
       		}else{
       			return index;
       		}
       }
       if(A[start]<target){
       		return start+1;
       }else{
       		return start;
       }
    }
};

