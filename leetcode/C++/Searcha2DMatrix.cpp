// Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

// Integers in each row are sorted from left to right.
// The first integer of each row is greater than the last integer of the previous row.
// For example,

// Consider the following matrix:

// [
//   [1,   3,  5,  7],
//   [10, 11, 16, 20],
//   [23, 30, 34, 50]
// ]
// Given target = 3, return true.

class Solution {
public:
    bool searchMatrix(vector<vector<int> >& matrix, int target) {
        int col=matrix[0].size();
        int row=matrix.size();
        
        int targetrow=0;
        int flag=0;


        if(0==col-1&&0==row-1)
        {
        	if(target==matrix[0][0])
        		return true;
        	else
        		return false;
        }


        for(int i=0;i<row;i++)
        {
        	if(target<matrix[0][0])
        	{
        		return false;
        	}
        	if(target==matrix[i][0])
        	{
        		return true;
        	}
            if(target<matrix[i][0]&&i>=1)
            {
                flag=1;
                targetrow=i-1;
                break;
            }
            if(target<matrix[row-1][col-1])
            {
            	flag=1;
            	targetrow=row-1;
            }
            if(target==matrix[row-1][col-1])
            {
            	return true;
            }
            flag=0;
        }


        for(int i=0;i<col;i++)
        {
            if(target==matrix[targetrow][i])
            {
                flag=1;
                break;
            }
            flag=0;
        }

        if(0==flag)
            return false;
        else
            return true;
    }
};




//=======
// LeetCode, Search a 2D Matrix
// 时间复杂度O(logn)，空间复杂度O(1)
class Solution {
public:
    bool searchMatrix(const vector<vector<int>>& matrix, int target) {
        if (matrix.empty()) return false;
        const size_t  m = matrix.size();
        const size_t n = matrix.front().size();

        int first = 0;
        int last = m * n;

        while (first < last) {
            int mid = first + (last - first) / 2;
            int value = matrix[mid / n][mid % n];

            if (value == target)
                return true;
            else if (value < target)
                first = mid + 1;
            else
                last = mid;
        }

        return false;
    }
};


// public class Solution {
//     public boolean searchMatrix(int[][] matrix, int target) {
//         int row=0;
//         int m = matrix.length;
//         int n = matrix[0].length;
//         int col=n-1;
//         while(row < m && col >= 0){
//             if(matrix[row][col] == target)
//                 return true;
//                 else if(matrix[row][col] < target)
//                 row++;
//                 else col--;
//         }
//         return false;
//     }
// }

// 思路1：二分法确定target可能在第几行出现。
// 再用二分法在该行确定target可能出现的位置。时间复杂度O(logn+logm)
// 思路2：从右上角元素开始遍历，每次遍历中若与target相等则返回true；
// 若小于则行向下移动；若大于则列向左移动。时间复杂度m+n
class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        int left = 0;
        int right = matrix.size()-1;
        if(left != right)
        {
            while(left<=right)
            {
                int middle = left + (right-left)/2;
                if(matrix[middle][0] < target)
                {
                    left = middle+1;
                }
                else if(matrix[middle][0] > target)
                {
                    right = middle-1;
                }
                else
                {
                    return true;
                }
            }
        }
        if(right == -1)
        {
            return false;
        }
        else
        {
            int row = right;
            int left = 0;
            int right = matrix[row].size()-1;
            while(left<=right)
            {
                int middle = left + (right-left)/2;
                if(matrix[row][middle] < target)
                {
                    left = middle+1;
                }
                else if(matrix[row][middle] > target)
                {
                    right = middle-1;
                }
                else
                {
                    return true;
                }
            }
            return false;
        }
        
    }
};


class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        int i =matrix.size()-1; int j=0;
        int n = matrix.size(); int m = matrix[0].size();
        while(i>=0&&j<m)
        {
            if(matrix[i][j]==target)
            {
                return true;
            }
            else if(matrix[i][j]<target)
            {
                j++;
            }
            else
            {
                i--;
            }
        }
        return false;
    }
};
