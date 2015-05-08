// Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.

// Note:
// You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold additional elements from nums2. 
// The number of elements initialized in nums1 and nums2 are m and n respectively.

class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        int aindex=m-1;
        int bindex=n-1;
        int index=m+n-1;
        
        while(aindex>=0&&bindex>=0)
        {
            if(B[bindex]>A[aindex])
            {
                A[index--]=B[bindex--];
                //index--;
                //bindex--;
            }else{
                A[index--]=A[aindex--];
                //index--;
                //aindex--;
            }
        }
        
        while(aindex>=0)
        {
            A[index--]=A[aindex--];
            //index--;
            //aindex--;
        }
        
        while(bindex>=0)
        {
            A[index--]=B[bindex--];
            //index--;
            //bindex--;
        }
        
    }
};



//LeetCode, Merge Sorted Array
// 时间复杂度O(m+n)，空间复杂度O(1)
class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        int ia = m - 1, ib = n - 1, icur = m + n - 1;
        while(ia >= 0 && ib >= 0) {
            A[icur--] = A[ia] >= B[ib] ? A[ia--] : B[ib--];
        }
        while(ib >= 0) {
            A[icur--] = B[ib--];
        }
    }
};
