// Follow up for "Unique Paths":

// Now consider if some obstacles are added to the grids. How many unique paths would there be?

// An obstacle and empty space is marked as 1 and 0 respectively in the grid.

// For example,
// There is one obstacle in the middle of a 3x3 grid as illustrated below.

// [
//   [0,0,0],
//   [0,1,0],
//   [0,0,0]
// ]
// The total number of unique paths is 2.

// Note: m and n will be at most 100.

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int row=obstacleGrid.size();
        int col=obstacleGrid[0].size();

        int *dp=new int[col];

        if(obstacleGrid[0][0]!=0)
        	dp[0]=0;
        else
        	dp[0]=1;

        for(int i=1;i<col;i++)
        	if(obstacleGrid[0][i]!=0)
        		dp[i]=0;
        	else
        		dp[i]=dp[i-1];

        for(int i=1;i<row;i++)
        	for(int j=0;j<col;j++)
        		if(obstacleGrid[i][j]!=0)
        			dp[j]=0;
        		else if(j>0)
        			dp[j]=dp[j]+dp[j-1];

        return dp[col-1];


    }
};

//  1. 如果没有障碍

// val[i][0] = 1
// val[0][j] = 1
// val[i][j] = val[i-1][j] + val[i][j-1]

// 2. 有了障碍后
// 如果obstacle[i][j] = 1 
//      val[i][j] = 1
// 否则
//      tmp = obstacle[i-1][j] == 1 ? 0 : val[i-1][j]
//      tmp = obstacle[i][j-1] == 1 ? tmp : tmp + val[i-1][j-1]
// 　　　val[i][j] = tmp
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        int row = obstacleGrid.size();
        int col = obstacleGrid[0].size();
        int token = 1;
        int val[row][col];
        for (int j = 0; j < col; ++j)
        {
            if(obstacleGrid[0][j] == 1)
                token = 0;
            val[0][j] = token;
            
        }
        token = 1;
        for (int i = 0; i < row; ++i)
        {
            if(obstacleGrid[i][0] == 1)
                token = 0;
            val[i][0] = token;
        }
        for (int i = 1; i < row; ++i)
        {
            for(int j = 1; j < col; ++j)
            {
                if (obstacleGrid[i][j] == 1)
                    val[i][j] = 0;
                else
                {
                    int tmp = obstacleGrid[i-1][j] == 1 ? 0 :val[i-1][j];
                    tmp = obstacleGrid[i][j-1] == 1 ? tmp : tmp + val[i][j-1];
                    val[i][j] = tmp;
                }
            }
        }
        return val[row-1][col-1];
    }
};



class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > f(obstacleGrid.size(), vector<int>(obstacleGrid[0].size()));
               
        f[0][0] = obstacleGrid[0][0] == 1 ? 0 : 1;
        for(int i = 1; i < f.size(); i++)
            f[i][0] = obstacleGrid[i][0] == 1 ? 0 : f[i-1][0];
            
        for(int i = 1; i < f[0].size(); i++)
            f[0][i] = obstacleGrid[0][i] == 1 ? 0 : f[0][i-1];
            
        for(int i = 1; i < f.size(); i++)
            for(int j = 1; j < f[i].size(); j++)
                f[i][j] = obstacleGrid[i][j] == 1 ? 0 : f[i-1][j] + f[i][j-1];
                
        return f[f.size()-1][f[0].size()-1];
    }
};

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        int m = obstacleGrid.size();
        if (m < 1)
        {
            return 0;
        }
        int n = obstacleGrid[0].size();
        if (n < 1)
        {
            return 0;
        }

        int buf[m][n];
        bool obstacleFound = false;
        for (int i = 0; i < m; i++)
        {
            if (!obstacleFound && obstacleGrid[i][0] == 0)
            {
                buf[i][0] = 1;
            }
            else
            {
                buf[i][0] = 0;
                obstacleFound = true;
            }
        }

        obstacleFound = false;
        for (int i = 0; i < n; i++)
        {
            if (!obstacleFound && obstacleGrid[0][i] == 0)
            {
                buf[0][i] = 1;
            }
            else
            {
                buf[0][i] = 0;
                obstacleFound = true;
            }
        }

        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                if (obstacleGrid[i][j] == 1)
                {
                    buf[i][j] = 0;
                }
                else
                {
                    buf[i][j] = buf[i-1][j] + buf[i][j-1];
                }
            }
        }

        return buf[m-1][n-1];
    }
};


// dp[i][j]=0   					dp[i][j]==1
// 		=dp[i-1][j]+dp[i][j-1]  	dp[i][j]==0
public class Solution {
    public static int uniquePathsWithObstacles(int[][] obstacleGrid) {
        int i, j, n = obstacleGrid.length, m = obstacleGrid[0].length, dp[][] = new int[n][m];
        
        if (obstacleGrid == null || obstacleGrid[n - 1][m - 1] == 1 || obstacleGrid[0][0] == 1) {
            return 0;
        }
        
        // initial dynamic matrix
        for (i = 0; i < n; i ++) {
            if (obstacleGrid[i][0] == 0) {
                dp[i][0] = 1;
            } else {
                break;
            }
        }
        while (i < n) {
            dp[i][0] = 0;
            i ++;
        }
        
        for (j = 0; j < m; j ++) {
            if (obstacleGrid[0][j] == 0) {
                dp[0][j] = 1;
            } else {
                break;
            }
            
        }
        
        while (j < m) {
            dp[0][j] = 0;
            j ++;
        }
        
        
        // dynamic process
        for ( i = 1; i < n; i ++) {
            for ( j = 1; j < m; j ++) {
                if (obstacleGrid[i][j] == 1) {
                    dp[i][j] = 0;
                } else {
                    dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
                }
            }
        }
        
        return dp[n - 1][m - 1];
    }
};


//由于部分格子有obstacle，不能访问到，需要对左上角和右下角格子进行判断，即确认左上角和右下角是能访问。
class Solution {
private:
    int grid[100][100];
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        if( obstacleGrid.size() <= 0 ) return 0;
		
		int m = obstacleGrid.size();
		int n = obstacleGrid[0].size();
		
		if( obstacleGrid[m-1][n-1] ) return 0;
		
        if( m <= 0 || n <= 0 )
			return 0;
		memset( grid, 0, sizeof( grid ));
		if( !obstacleGrid[0][0] ) 
		    grid[0][0] = 1;
		
		for( int i = 0; i < m; ++i )
			for( int j = 0; j < n; ++j )
			{
				if( (i-1) >= 0 && !obstacleGrid[i-1][j] )
					grid[i][j] = grid[i-1][j];
				if( (j-1) >= 0 && !obstacleGrid[i][j-1] )
					grid[i][j] += grid[i][j-1];
			}
		return grid[m-1][n-1];
    }
};



//将obstacle标记为-1，其余基本跟上一题一样。
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        int i, j;
        for (i = 0; i < m; ++i) {
            for (j = 0; j < n; ++j) {
                obstacleGrid[i][j] = -obstacleGrid[i][j];
            }
        }
        for (i = 0; i < m; ++i) {
            if (obstacleGrid[i][0] == -1) break;
            obstacleGrid[i][0] = 1;
        }
        for (j = 0; j < n; ++j) {
            if (obstacleGrid[0][j] == -1) break;
            obstacleGrid[0][j] = 1;
        }
        for (i = 1; i < m; ++i) {
            for (j = 1; j < n; ++j) {
                if (obstacleGrid[i][j] == -1) continue;
                obstacleGrid[i][j] += (obstacleGrid[i-1][j] == -1) ? 0 : obstacleGrid[i-1][j];
                obstacleGrid[i][j] += (obstacleGrid[i][j-1] == -1) ? 0 : obstacleGrid[i][j-1];
            }
        }
        return (obstacleGrid[m-1][n-1] == -1) ? 0 : obstacleGrid[m-1][n-1];
    }
};

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        if(obstacleGrid.size() <= 0 || obstacleGrid[0].size() <= 0)
            return 0;

        int row = obstacleGrid.size();
        int column = obstacleGrid[0].size();
        vector<int> path_nums(column, 0);
        for(int i = 0; i < row; i ++) {
            int row_idx = row - 1 - i;
            for(int j = 0; j < column; j ++ ) {
                int column_idx = column - 1 - j;
                if(i == 0 && j == 0 && obstacleGrid[row_idx][column_idx] == 1)
                    return 0;
                if(i == 0 && j == 0 && obstacleGrid[row_idx][column_idx] == 0) {
                    path_nums[j] = 1;
                }else {
                    if(obstacleGrid[row_idx][column_idx] == 1) {
                        path_nums[j] = 0;
                    }else {
                        if(j != 0)
                            path_nums[j] += path_nums[j - 1];
                    }
                }
            } 
        }
        return path_nums[column - 1];
    }
};

// LeetCode, Unique Paths II
// 深搜 + 缓存，即备忘录法
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        const int m = obstacleGrid.size();
        const int n = obstacleGrid[0].size();
        // 0行和0列未使用
        this->f = vector<vector<int> >(m + 1, vector<int>(n + 1, 0));
        return dfs(obstacleGrid, m, n);
    }
private:
    vector<vector<int> > f;  // 缓存

    int dfs(const vector<vector<int> > &obstacleGrid,
            int x, int y) {
        if (x < 1 || y < 1) return 0; // 数据非法，终止条件

        // (x,y)是障碍
        if (obstacleGrid[x-1][y-1]) return 0;

        if (x == 1 and y == 1) return 1; // 回到起点，收敛条件

        return getOrUpdate(obstacleGrid, x - 1, y) +
                getOrUpdate(obstacleGrid, x, y - 1);
    }

    int getOrUpdate(const vector<vector<int> > &obstacleGrid,
            int x, int y) {
        if (f[x][y] > 0) return f[x][y];
        else return f[x][y] = dfs(obstacleGrid, x, y);
    }
};

// 与上一题类似，但要特别注意第一列的障碍。在上一题中，第一列全部是1，
// 但是在这一题中不同，第一列如果某一行有障碍物，那么后面的行应该为0。
// LeetCode, Unique Paths II
// 动规，滚动数组
// 时间复杂度O(n^2)，空间复杂度O(n)
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        const int m = obstacleGrid.size();
        const int n = obstacleGrid[0].size();
        if (obstacleGrid[0][0] || obstacleGrid[m-1][n-1]) return 0;

        vector<int> f(n, 0);
        f[0] = obstacleGrid[0][0] ? 0 : 1;

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                f[j] = obstacleGrid[i][j] ? 0 : (j == 0 ? 0 : f[j - 1]) + f[j];

        return f[n - 1];
    }
};




