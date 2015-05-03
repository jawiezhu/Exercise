// Given an integer n, generate a square matrix filled with elements from 1 to n^2 in spiral order.

// For example,
// Given n = 3,

// You should return the following matrix:
// [
//  [ 1, 2, 3 ],
//  [ 8, 9, 4 ],
//  [ 7, 6, 5 ]
// ]


class Solution {
public:
    vector<vector<int> >generateMatrix(int n) {
        int m=0;
        vector<vector<int> >a;
        a.resize(n,vector<int>(n));
        if(n==0)
            return a;
        int x=0;
        int y=0;
        m=a[0][0]=1;

        while(m<n*n)
        {
            while(y<n-1&&!a[x][y+1])
            {
                m++;
                y++;
                a[x][y]=m;
            }
            while(x<n-1&&!a[x+1][y])
            {
                m++;
                x++;
                a[x][y]=m;
            }
           
            while(y-1>=0&&!a[x][y-1])
            {
                m++;
                y--;
                a[x][y]=m;
            }

            while(x-1>=0&&!a[x-1][y])
            {
                m++;
                x--;
                a[x][y]=m;
            }
        }   

        return a;
    }
};

// LeetCode, Spiral Matrix II
// 时间复杂度O(n^2)，空间复杂度O(n^2)
class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int> > matrix(n, vector<int>(n));
        int begin = 0, end = n - 1;
        int num = 1;

        while (begin < end) {
            for (int j = begin; j < end; ++j) matrix[begin][j] = num++;
            for (int i = begin; i < end; ++i) matrix[i][end] = num++;
            for (int j = end; j > begin; --j) matrix[end][j] = num++;
            for (int i = end; i > begin; --i) matrix[i][begin] = num++;
            ++begin;
            --end;
        }

        if (begin == end) matrix[begin][begin] = num;

        return matrix;
    }
};


// LeetCode, Spiral Matrix II
// @author 龚陆安 (http://weibo.com/luangong)
// 时间复杂度O(n^2)，空间复杂度O(n^2)
class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        vector< vector<int> > matrix(n, vector<int>(n));
        if (n == 0) return matrix;
        int beginX = 0, endX = n - 1;
        int beginY = 0, endY = n - 1;
        int num = 1;
        while (true) {
            for (int j = beginX; j <= endX; ++j) matrix[beginY][j] = num++;
            if (++beginY > endY) break;

            for (int i = beginY; i <= endY; ++i) matrix[i][endX] = num++;
            if (beginX > --endX) break;

            for (int j = endX; j >= beginX; --j) matrix[endY][j] = num++;
            if (beginY > --endY) break;

            for (int i = endY; i >= beginY; --i) matrix[i][beginX] = num++;
            if (++beginX > endX) break;
        }
        return matrix;
    }
};

public class Solution {
    public int[][] generateMatrix(int n) {
        int startX = 0;
        int startY = 0;
        int endX = n - 1;
        int endY = n - 1;
        
        int[][] matrix = new int[n][n];
        int startValue = 1;
        
        while (startX <= endX) {
            startValue = fillNumber(startX, startY, endX, endY, matrix, startValue);
            startX++;
            startY++;
            endX--;
            endY--;
        }
        return matrix;
    }
    
    public int fillNumber(int startX, int startY, int endX, int endY, int[][] matrix, int startV) {
        if (startX == endX) {
            matrix[startX][startY] = startV;
            return -1;
        }
        
        for (int i = startY; i <= endY; i++) {
            matrix[startX][i] = startV;
            startV++;
        }
        for (int i = startX + 1; i <= endX; i++) {
            matrix[i][endY] = startV;
            startV++;
        }
        
        for (int i = endY - 1; i >= startY; i--) {
             matrix[endX][i] = startV;
            startV++;
        }
        
        for (int i = endX - 1; i >= startX + 1; i--) {
             matrix[i][startY] = startV;
             startV++;
        }
        
        return startV;
    }
};



