// Given a m x n grid filled with non-negative numbers, 
// find a path from top left to bottom right which minimizes the sum of all numbers along its path.

// Note: You can only move either down or right at any point in time.




// 需要利用动态规划的思路。对于m*n的矩阵，
// 每次只能向右或者向下移动，因此一共需要移动m+n-1步，
// 每一步能够得到的单元格如下（0表示第一步）：
// 0 1 2
// 1 2 3
// 2 3 4
// 3 4 5
// 因此问题变成了第n步的最小path sum移动等于第n-1中的path sum与第n个能到达的单元格的和的最小值。
// 建立一个m*n的矩阵来存储到达(i,j)单元格的min path sum，每一次计算第k步到达最远的单元格。
// 备注：详细思路可以参考http://blog.csdn.net/v_july_v/article/details/10212493（格子取数）
class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        int ** dp=new int *[grid.size()];
        int m=grid.size();
        int n=grid[0].size();
        for(int k=0;k<m;k++)
        {
        	dp[k]=new int [n];
        }

        dp[0][0]=grid[0][0];
        int step=m+n-1;
        int cur=1;
        while(cur<step)
        {
        	for(int i=0;i<=cur&&i<m;i++)
        	{
        		int j=cur-i;
        		if(j>=n)
        		{
        			continue;
        		}

        		dp[i][j]=INT_MAX;
        		if(j>0&&dp[i][j-1]+grid[i][j]<dp[i][j])
        		{
        			dp[i][j]=dp[i][j-1]+grid[i][j];
        		}
        		if(i>0&&dp[i-1][j]+grid[i][j]<dp[i][j])
        		{
        			dp[i][j]=dp[i-1][j]+grid[i][j];
        		}
        	}
        	cur++;
        }
        return dp[m-1][n-1];
    }
};


// 依然是动态规划，不过实际上可以利用一个m*n的矩阵来存储到达每个位置的min path sum。
// 每个位置的min path sum应该等于自身的值加上左侧或者上面两者中的极小值。
class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        if(grid.size() == 0 || grid[0].size() == 0){
            return 0;
        }
        
        int m = grid.size();
        int n = grid[0].size();
        
        int** dp = new int*[m];
        for(int i = 0; i < m; i++){
            dp[i] = new int[n];
        }
        
        dp[0][0] = grid[0][0];
        
        for(int i = 1; i < m; i++){
            dp[i][0] = dp[i-1][0] + grid[i][0];
        }
        
        for(int i = 1; i < n; i++){
            dp[0][i] = dp[0][i-1] + grid[0][i];
        }
        
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                dp[i][j] = (dp[i-1][j] < dp[i][j-1] ? dp[i-1][j] : dp[i][j-1]) + grid[i][j];
            }
        }
        
        return dp[m-1][n-1];
    }
};


//DP，f[i][j] = min(f[i-1][j], f[i][j-1]) + a[i][j]
class Solution {
private:
    int f[1000][1000];
public:
    int minPathSum(vector<vector<int> > &grid) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (grid.size() == 0 || grid[0].size() == 0)
            return 0;
            
        f[0][0] = grid[0][0];
        
        for(int i = 1; i < grid.size(); i++)
            f[i][0] = f[i-1][0] + grid[i][0];
            
        for(int i = 1; i < grid[0].size(); i++)
            f[0][i] = f[0][i-1] + grid[0][i];
            
        for(int i = 1; i < grid.size(); i++)
            for(int j = 1; j < grid[0].size(); j++)
                f[i][j] = min(f[i-1][j], f[i][j-1]) + grid[i][j];
                
        return f[grid.size()-1][grid[0].size()-1];
    }
};


//
// 题意从左上到右下，所有可能的路径中，求经过的元素和最小值。
// 动态规划基础题了，dp每个状态由左边或者上边的值中，较小的值与当前状态的值相加得到。

int dp[1000][1000];  
class Solution {  
public:  
    int minPathSum(vector<vector<int> > &grid) {  
        int rows=grid.size();  
        if(rows==0)return 0;  
        int cols=grid[0].size();  
        if(cols==0)return 0;  
        memset(dp,0,sizeof(dp));  
        for(int i=0;i<rows;++i)  
        {  
            for(int j=0;j<cols;++j)  
            {                 
                if(i==0&&j==0)dp[0][0]=grid[0][0];  
                else if(j==0)dp[i][0]=dp[i-1][0]+grid[i][0];  
                else if(i==0)dp[0][j]=dp[0][j-1]+grid[0][j];  
                else dp[i][j]=min(dp[i-1][j],dp[i][j-1])+grid[i][j];  
            }  
        }  
        return dp[rows-1][cols-1];          
    }  
};

