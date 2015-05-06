// Follow up for "Remove Duplicates":
// What if duplicates are allowed at most twice?

// For example,
// Given sorted array nums = [1,1,1,2,2,3],

// Your function should return length = 5, with the first five elements of nums being 1, 1, 2, 2 and 3. 
// It doesn't matter what you leave beyond the new length.

//
// 加一个变量记录一下元素出现的次数即可。
// 这题因为是已经排序的数组，所以一个变量即可解决。
// 如果是没有排序的数组，则需要引入一个hashmap来记录出现次数。
// 双指针
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()==0||nums.size()==1) return nums.size();
        int dup=1;
        int index=1;
        for(int i=1;i<nums.size();i++)
        {
        	if(nums[i]==nums[i-1])
        		dup++;
        	else
        		dup=1;

        	nums[index]=nums[i];
        	if(dup<=2)
        		index++;
        }
        return index;
    }
};

//
public class Solution {
    public int removeDuplicates(int[] A) {
        if (A == null || A.length == 0) return 0;
        int startPosition = 0;
        boolean isRepeated = false;
        for (int i = 1; i < A.length; i++) {
            if (A[i] != A[startPosition]) {
                isRepeated = false;
                startPosition++;
                A[startPosition] = A[i];
            } else {
                if (isRepeated == false) {
                    startPosition++;
                    A[startPosition] = A[i];
                    isRepeated = true;
                }
            }
        }
        return startPosition + 1;
    }
};

//
class Solution {
public:
    int removeDuplicates(int A[], int n) {
        int start = 0;
        for(int i = 0;i < n;i++) {
            if(i == 0 || i == 1) {
                A[start++] = A[i];
            }
            else {
                //using start
                if(A[i] == A[start-2]) {
                     
                }
                else {
                    A[start++] = A[i];
                }
            }
        }
        return start;
    }
};

//
// LeetCode, Remove Duplicates from Sorted Array II
// @author 虞航仲 (http://weibo.com/u/1666779725)
// 时间复杂度O(n)，空间复杂度O(1)
class Solution {
public:
    int removeDuplicates(int A[], int n) {
        int index = 0;
        for (int i = 0; i < n; ++i) {
            if (i > 0 && i < n - 1 && A[i] == A[i - 1] && A[i] == A[i + 1])
                continue;

            A[index++] = A[i];
        }
        return index;
    }
};

