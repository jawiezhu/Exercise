// You are given an n x n 2D matrix representing an image.

// Rotate the image by 90 degrees (clockwise).

// Follow up:
// Could you do this in-place?

class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        int n=matrix.size();
        vector<vector<int> > tmp(n,vector<int> (n));

        for(int i=0;i<n;i++)
        {
        	for(int j=0;j<n;j++)
        		tmp[j][n-1-i]=matrix[i][j];
        }

        for(int i=0;i<n;i++)
        {
        	for(int j=0;j<n;j++)
        		cout<<tmp[i][j]<<" ";
        	cout<<endl;
        }
    }
};


// 纯模拟，从外到内一圈一圈的转，但这个方法太慢。

// 首先沿着副对角线翻转一次，然后沿着水平中线翻转一次。
// 或者，首先沿着水平中线翻转一次，然后沿着主对角线翻转一次。

// LeetCode, Rotate Image
// 思路 1，时间复杂度O(n^2)，空间复杂度O(1)
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        const int n = matrix.size();

        for (int i = 0; i < n; ++i)  // 沿着副对角线反转
            for (int j = 0; j < n - i; ++j)
                swap(matrix[i][j], matrix[n - 1 - j][n - 1 - i]);

        for (int i = 0; i < n / 2; ++i) // 沿着水平中线反转
            for (int j = 0; j < n; ++j)
                swap(matrix[i][j], matrix[n - 1 - i][j]);
    }
};


// LeetCode, Rotate Image
// 思路 2，时间复杂度O(n^2)，空间复杂度O(1)
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        const int n = matrix.size();

        for (int i = 0; i < n / 2; ++i) // 沿着水平中线反转
            for (int j = 0; j < n; ++j)
                swap(matrix[i][j], matrix[n - 1 - i][j]);

        for (int i = 0; i < n; ++i)  // 沿着主对角线反转
            for (int j = i + 1; j < n; ++j)
                swap(matrix[i][j], matrix[j][i]);
    }
};
