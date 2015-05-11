// Suppose a sorted array is rotated at some pivot unknown to you beforehand.

// (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

// You are given a target value to search. If found in the array return its index, otherwise return -1.

// You may assume no duplicate exists in the array.



class Solution {
public:
    int search(vector<int>& nums, int target) {
        //if(nums.size()==0) return ;

        for(int i=0;i<nums.size();i++)
        {
        	if(target==nums[i])
        		return i;
        }

        return -1;
    }
};


// LeetCode, Search in Rotated Sorted Array
// 时间复杂度O(log n)，空间复杂度O(1)
class Solution {
public:
    int search(int A[], int n, int target) {
        int first = 0, last = n;
        while (first != last) {
            const int mid = (first + last) / 2;
            if (A[mid] == target)
                return mid;
            if (A[first] <= A[mid]) {
                if (A[first] <= target && target < A[mid])
                    last = mid;
                else
                    first = mid + 1;
            } else {
                if (A[mid] < target && target <= A[last-1])
                    first = mid + 1;
                else
                    last = mid;
            }
        }
        return -1;
    }
};


//JAVA
public class Solution {
    public static int search(int[] A, int target) {
        return searchBinary(A, 0, A.length-1 , target);
    }

    public static int searchBinary(int A[],int s,int e,int target){
        int mid = (s+e)/2;
        if(A[mid] == target)
            return mid;
        if(s >= e) return -1;
        if( A[mid] < A[e] ){ //后半部分是顺序的
            if(target > A[mid] && target <= A[e]){
                return searchBinary(A, mid+1, e, target);
            }else
                return searchBinary(A, s, mid-1, target);
        }else{ //前半部分顺序的
            if(target >= A[s] && target < A[mid])
                return searchBinary(A, s, mid-1, target);
            else
                return searchBinary(A, mid+1, e, target);
        }

    }
};


// 二分搜索来找到转折点，也就是最小数的位置。对二分搜索要稍作修改，当a[left] <= a[mid]时，可以肯定a[left..mid]是升序的，那么a[left]是最小的，也肯能最小的在a[mid+1..right]中，

// 所以要比较a[left]和min(a[mid+1..right])，同样对于a[left]>a[mid]，做同样的处理。

class Solution {
public:
    int findPos(int a[], int left, int right)
    {
        if (left > right)
            return -1;
            
        int mid = left + (right - left) / 2;
        
        if (a[left] <= a[mid])
        {
            int pos = findPos(a, mid + 1, right);
            
            if (pos == -1)
                return left;
            else
                return a[left] < a[pos] ? left : pos; 
        }
        else
        {
            int pos = findPos(a, left, mid - 1);
            
            if (pos == -1)
                return mid;
            else
                return a[pos] < a[mid] ? pos : mid;
        }
    }
    
    int bsearch(int a[], int left, int right, int key)
    {
        if (left > right)
            return -1;
            
        int mid = left + (right - left) / 2;
        
        if (a[mid] == key)
            return mid;
        else if (a[mid] < key)
            return bsearch(a, mid + 1, right, key);
        else
            return bsearch(a, left, mid - 1, key);
    }
    
    int search(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int pos = findPos(A, 0, n - 1);
        
        int index = bsearch(A, 0, pos - 1, target);
        if (index != -1)
            return index;
            
        return bsearch(A, pos, n - 1, target);
    }
};




// 两层的二分查找，最外层的二分用来找到有序的部分，因为初始有序的数组被翻转后，其中的任何位置的元素都仍然属于一个有序的子序列，这个有序的子序列不是在左边有序，就是右边有序，当然也可能都有序。

// 里层的二分查找就简单了，就是我们所谓的二分查找，在一个有序的序列中查找给定值。
class Solution {
public:
	int search(int A[], int n, int target) {
		if(n == 0) return -1;
		int left = 0, right = n - 1;
		while (left <= right)
		{
			int midle = (left + right) >> 1;
			//右半部分有序
			if (A[midle] <= A[right])
			{
			    //右半部分包含目标值？
				if(A[midle] <= target && target <= A[right])
				{
				  int rlow = midle, rhigh = right;
				  while (rlow <= rhigh)
				  {
					  int mid = (rlow + rhigh) >> 1;
					  if(A[mid] == target) return mid;
					  else if(A[mid] < target) rlow = mid + 1;
					  else rhigh = mid - 1;
				  }
				}
				right = midle - 1;
			}
			//左半部分有序
			if(A[left] <= A[midle])
			{
			    //左半部分包含目标值？
				if (A[left] <= target && target <= A[midle])
				{
					int llow = left, lhigh = midle;
					while (llow <= lhigh)
					{
						int lmid = (llow + lhigh) >> 1;
						if(A[lmid] == target) return lmid;
						else if(A[lmid] < target) llow = lmid + 1;
						else lhigh = lmid - 1;
					}
				}
				left = midle + 1;
			}
		}
		return -1;
	}
};


//拆分两段后，容易发现第一段的最后一个数大于第二段的最后一个数，并且第二段的第一个数小于第二段的最后一个数
// 任何题意给定的序列都满足这个关系

// 所以先二分找到两段的交点

// 然后分别二分找到答案

class Solution
{
public:
    int search_2(int A[], int L, int R, int target)
    {
        while(L<=R)
        {
            int mid=(L+R)>>1;
            if(A[mid]>target)
            {
                R=mid-1;
            }
            else if(A[mid]<target)
            {
                L=mid+1;
            }
            else    return mid;
        }
        return -1;
    }
    int search(int A[], int n, int target)
    {
        if(n == 0)  return -1;
        if(n == 1)
        {
            if(A[0] == target)  return 0;
            else    return -1;
        }
        if(n == 2)
        {
            if(A[0] == target)  return 0;
            else if(A[1] == target) return 1;
            else    return -1;
        }
        int L=0,R=n-2;
        while(L<R)//[0,n-2]找一个比A[n-1]大的数
        {
            int mid=(L+R>>1)+1;
            if(A[mid]>A[n-1])   L=mid;
            else  R=mid-1;
        }
        int split=L;
        if(A[L]<A[n-1]) split=n-1;
        //[0,split],[split+1,n-1]
        int ans;
        ans=search_2(A,0,split,target);
        if(ans!=-1) return ans;
        if(split+1<=n-1)
        {
            return search_2(A,split+1,n-1,target);
        }
        return -1;
    }
};

class Solution {
public:
  int search(int A[], int n, int target) {
    if (A == NULL || n == 0)
      return -1;
    int left = 0, right = n - 1, mid = 0;
    while (left <= right){
      mid = left + (right - left) / 2;
      if (A[mid] == target)
        return mid;
      else if (A[mid] > A[right]){	 //转折点在右边部分，这样左边部分是升序排列的
        if (A[left] <= target && target < A[mid])   //满足这个条件就进入了没有转折点、全部都是升序的序列
          right = mid - 1;
        else
          left = mid + 1;
      }
      else{	//这里表示转折点在左边或者已经没有转折点了，既已经进入了完全升序的序列
        if(A[mid] < target && target <= A[right])
          left = mid + 1;
        else
          right = mid - 1;
      }
    }
    return -1;
  }

};
