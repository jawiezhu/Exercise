// Follow up for "Search in Rotated Sorted Array":
// What if duplicates are allowed?

// Would this affect the run-time complexity? How and why?

// Write a function to determine if a given target is in the array.

class Solution {
public:
    bool search(vector<int>& nums, int target) {
    	if(nums.size()==0) return false;

        for(int i=0;i<nums.size();i++)
        {
        	if(target==nums[i])
        		return true;
        }
        return false;
    }
};


//允许重复元素，则上一题中如果{A[m]>=A[l]},
// 那么{[l,m]}为递增序列的假设就不能成立了，比如{[1,3,1,1,1]}。

// 如果{A[m]>=A[l]}不能确定递增，那就把它拆分成两个条件：

// 若{A[m]>A[l]}，则区间{[l,m]}一定递增
// 若{A[m]==A[l]} 确定不了，那就{l++}，往下看一步即可。
// LeetCode, Search in Rotated Sorted Array II
// 时间复杂度O(n)，空间复杂度O(1)
class Solution {
public:
    bool search(int A[], int n, int target) {
        int first = 0, last = n;
        while (first != last) {
            const int mid = (first + last) / 2;
            if (A[mid] == target)
                return true;
            if (A[first] < A[mid]) {
                if (A[first] <= target && target < A[mid])
                    last = mid;
                else
                    first = mid + 1;
            } else if (A[first] > A[mid]) {
                if (A[mid] < target && target <= A[last-1])
                    first = mid + 1;
                else
                    last = mid;
            } else
                //skip duplicate one
                first++;
        }
        return false;
    }
};


// Almost the same to Search in Rotated Sorted Array without duplicates, 
// but careful about the corner case like [1311], 
// we should search both left half and right half. 
// So, in this case, the run-time complexity will between O(logN) to O(N).
class Solution {
public:
    bool search(int A[], int n, int target) {
        if(n == 0)
            return false;
        if(n == 1) {
            if(A[0] == target )
                return true;
            else 
                return false;
        }
        
        int median = n/2;
        if(A[median] == target)
            return true;
        if(A[0] == target)
            return true;
            
        if(A[0] < A[median] && target > A[0] && target < A[median] || 
            (A[0] > A[median] && (target > A[0] || target < A[median]))){
              return search(A + 1, median - 0, target);  
            }else if(A[0] == A[median]){
                bool ret1 = search(A + 1, median - 0, target);      
                bool ret2 = false;
                if(n - median - 1 <= 0)
                    ret2 = false;
                
                ret2 = search(A + median + 1, n - median -1, target);
                return ret1 || ret2;
            }else{
                if(n - median - 1 <= 0)
                    return false;
                
                return search(A + median + 1, n - median -1, target);
            }
    }
};



class Solution {
//classified discussion
//1. Based on the property of rotated array, there may or may not have one sorted sequence 
//when one sequence is divided into two parts  
//2. make decision under all these cases
public:
	bool search(int A[], int n, int target) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		return BinarySearch(A, n, target);
	}


	bool BinarySearch( int* A, int n, int target ) 
	{
		//throw std::exception("The method or operation is not implemented.");
		int l = 0;
		int r = n-1;
		while (l <= r)
		{
			int m = l+(r-l)/2;
			if(A[m] == target) return true;
			if (A[l] < A[m])//left subsequence sorted
			{
				if(A[l] <= target && target < A[m])
					r = m-1;
				else l = m+1;
			}
			else if (A[m] < A[r])
			{
				if(A[m] < target && target <= A[r])
					l = m+1;
				else r = m-1;
			}
			else if (A[l] == A[m])//A[m] is not the target, so remove en element equal to A[m] is safe
				l++;
			else if(A[m] == A[r])//ditto
				r--;
		}
		return false;
	}
};


class Solution {
public:
    bool search(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int left = 0;
        int right = n-1;
        while(left <= right)
        {
            int mid = left+(right-left)/2;
            if(A[left] < target && target < A[mid]) right = mid-1;
            else if(A[mid] < target && target < A[right]) left = mid+1;
            else
            {
                if(A[left] != target) left++;
                else return true;
                if(A[right] != target) right--;
                else return true;
            }
        }
    }
};



//出现相等元素之后会出现一种特殊退化的情况，
// 即中间元素等于start，end的元素，这样无法判断左边或者右边是否出现突增，增减，
// 所以这种情况下必须递归两边，算法退化成线性比较
class Solution
{
public:
    bool search(int A[], int n, int target)
    {
        if(A[0] < A[n-1])
            return binary_search(A,0,n-1,target);
        else
            return ordinary_search(A,0,n-1,target);
    }
    bool binary_search(int A[],int start,int end,int target)
    {
        if(start > end)
            return false;
        int mid = (start + end)/2;
        if(A[mid] == target)
            return true;
        if(A[mid] > target)
        {
            return binary_search(A,start,mid-1,target);
        }
        else
        {
            return binary_search(A,mid+1,end,target);
        }
    }
    bool ordinary_search(int A[],int start,int end,int target)
    {
        if(start > end)
            return false;
        int mid = (start + end)/2;
        if(A[mid] == target)
            return true;
        /**this is new**//**test case 1,3,1,1,1 or 1,1,1,3,1  无法断定3的具体位置**/
        if(A[start] == A[mid] && A[mid] == A[end])
        {
            return ordinary_search(A,start,mid-1,target)||ordinary_search(A,mid+1,end,target);
        }
        else if(A[start] <= A[mid])
        {
            if(target <= A[mid] && target >= A[start])
            {
                return binary_search(A,start,mid-1,target);
            }
            else
            {
                return ordinary_search(A,mid+1,end,target);
            }
        }
        else
        {
            if(target >= A[mid] && target <= A[end])
            {
                return binary_search(A,mid+1,end,target);
            }
            else
            {
                return ordinary_search(A,start,mid-1,target);
            }
        }
    }
};

//===============
class Solution {
public:
    bool search(int A[], int n, int target) {
        //if exists equal so don't know whether left or right is available???
        return search(A,0,n-1,target);
    }
    bool search(int A[], int start, int end, int target) {
        if(start > end)
            return false;
        int mid = start + (end - start)/2;
        if( A[mid] == target )
            return true;
        else if( A[mid] > target ) {
            //two side???
            if( A[start] == A[end] ) {
                return search(A,start,mid-1,target) || search(A,mid+1,end,target);
            }
            else {
                //no rotate,sorted array!!!
                if( A[start] < A[end] ) {
                    return bsearch(A,start,end,target);
                }
                // A[start] > A[end]!!!
                else {
                    if( A[mid] < A[start] ) {
                        return search(A,start,mid-1,target);
                    }
                    //A[mid] >= A[start]
                    else {
                        if(target >= A[start]) {
                            return bsearch(A,start,mid-1,target);
                        }
                        else {
                            return search(A,mid+1,end,target);
                        }
                    }
                }
            }
        }
        else {
            if( A[start] == A[end] ) {
                return search(A,start,mid-1,target) || search(A,mid+1,end,target);
            }
            else {
                //no rotate,sorted array!!!
                if( A[start] < A[end] ) {
                    return bsearch(A,start,end,target);
                }
                // A[start] > A[end]!!!
                else {
                    if( A[mid] < A[start] ) {
                        if(target <= A[end]) {
                            return bsearch(A,mid+1,end,target);
                        }
                        else {
                            return search(A,start,mid-1,target);
                        }
                    }
                    //A[mid] >= A[start]
                    else {
                        return search(A,mid+1,end,target);
                    }
                }
            }
        }
    }
    //binary search!!!
    bool bsearch(int A[], int start, int end, int target) {
        while(start <= end) {
            int mid = start + (end-start)/2;
            if(A[mid] == target)
                return true;
            else if(A[mid] > target) {
                end = mid-1;
            }
            else {
                start = mid+1;
            }
        }
        return false;
    }
};
