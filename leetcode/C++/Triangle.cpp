// Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

// For example, given the following triangle
// [
//      [2],
//     [3,4],
//    [6,5,7],
//   [4,1,8,3]
// ]
// The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).

// Note:
// Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.


// ERROR
// -1
// 2,3
// 1,-1,-3
// output:-2
// expected:-1
class Solution {
public:

    int minimumTotal(vector<vector<int> > &triangle) {
        int n=triangle.size();
        int sum=0;
        int tmp=0;
        sum=triangle[0][0];
        int j=0;
        int min=INT_MIN;


        for(int i=1;i<n;i++)
        {
            sort(triangle[i].begin(),triangle[i].end());
            tmp=triangle[i][0];

            sum=sum+tmp;
        }

        return sum;
    }
};


//================
class Solution{
public:
	int minimumTotal(vector<vector<int> > &triangle){
		int n=triangle.size();
		if(n==0) return 0;

		int *sum=new int[n+1];

		sum[0]=triangle[0][0];

		for(int i=1;i<n;i++)
		{
			sum[i]=sum[i-1]+triangle[i][i];
			for(int j=i-1;j>0;j--)
				sum[j]=min(sum[j],sum[j-1])+triangle[i][j];
			sum[0]=sum[0]+triangle[i][0];
		}

		int min=INT_MAX;
		for(int i=0;i<n;i++)
			if(sum[i]<min)
				min=sum[i];

		return min;
	}
};
//===========================
//设状态为$f(i, j)$，表示从从位置$(i,j)$出发，路径的最小和，则状态转移方程为
//f(i,j)=min{f(i,j+1),f(i+1,j+1)}+(i,j)

// LeetCode, Triangle
// 时间复杂度O(n^2)，空间复杂度O(1)
class Solution {
public:
    int minimumTotal (vector<vector<int>>& triangle) {
        for (int i = triangle.size() - 2; i >= 0; --i)
            for (int j = 0; j < i + 1; ++j)
                triangle[i][j] += min(triangle[i + 1][j],
                        triangle[i + 1][j + 1]);

        return triangle [0][0];
    }
};


//===================

// 使用动态规划法。当我们计算第i层的数到底层的最小和时，
// 如果我们知道第i+1层的数到底层最小的和就好算了。
// 即minsum[i][j]=triangle[i]+min( minsum[i+1][j] , minsum[i+1][j+1] )；
// 从底层向顶层逐层计算，就能得到最终结果。
// 使用大小为n的数组d记录每一层的结果，达到了O（n）的空间复杂度要求。
class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        int s = triangle.size();
        if(s != (triangle[s-1].size()))
        	return -1;
       	if(s==1)
       		return triangle[0][0];
        int *d = new int[s];
        int i,j;
        for(i=0;i<s;i++)
        	d[i]=triangle[s-1][i];
       	for(i=s-2;i>=0;i--)
       	{
       		for(j=0;j<=i;j++)
       		{
    		   	d[j]=triangle[i][j]+min(d[j],d[j+1]);
    	   	}	
       	}
       	return d[0]; 
    }
};

//
//用从后往前更新的方法，就只需要O(n)的额外空间。
class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (triangle.size() == 0)
            return 0;
            
        vector<int> f(triangle[triangle.size()-1].size());
        
        f[0] = triangle[0][0];
        for(int i = 1; i < triangle.size(); i++)
            for(int j = triangle[i].size() - 1; j >= 0; j--)
                if (j == 0)
                    f[j] = f[j] + triangle[i][j];
                else if (j == triangle[i].size() - 1)
                    f[j] = f[j-1] + triangle[i][j];
                else
                    f[j] = min(f[j-1], f[j]) + triangle[i][j];
                    
        int ret = INT_MAX;
        for(int i = 0; i < f.size(); i++)
            ret = min(ret, f[i]);
            
        return ret;       
    }
};


//O(n^2)
int minimumTotal(vector<vector<int> > &triangle) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int row = triangle.size();
        int col = triangle[row-1].size();
        
        int ** dp = new int*[row];
        for(int i = 0; i < row; i++)
            dp[i] = new int[col];
            
        dp[0][0] = triangle[0][0];
        for(int i = 1; i < row; ++i){
            int vlen = triangle[i].size();
            for(int j = 0; j < vlen; ++j){
                if(j==0) dp[i][j] = dp[i-1][0] + triangle[i][0];
                else if(j == vlen-1) dp[i][j] = dp[i-1][vlen-2] + triangle[i][vlen-1];
                else{
                    dp[i][j] = dp[i-1][j-1] < dp[i-1][j] ? dp[i-1][j-1] : dp[i-1][j];
                    dp[i][j] += triangle[i][j];
                }
            }
        }
        int min = dp[row-1][0];
        for(int j = 1; j < col; j++)
            if(min > dp[row-1][j]) min = dp[row-1][j];
            
        for(int i = 0; i < row; ++i)
            delete[] dp[i];
        delete[] dp;
        return min;
    }

//O(n)
int minimumTotal(vector<vector<int> > &triangle) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int row = triangle.size();
        int col = triangle[row-1].size();
        
        int* dp = new int[col];
        
        dp[0] = triangle[0][0];
        for(int i = 1; i < row; ++i){
            int tmp;
            int vlen = triangle[i].size();
            for(int j = 0; j < vlen; ++j){
                if(j==0) { tmp = dp[0]; dp[j] = dp[0] + triangle[i][0];}
                else if(j == vlen-1) dp[j] = tmp + triangle[i][vlen-1];
                else{
                    int res = tmp < dp[j] ? tmp : dp[j];
                    res += triangle[i][j];
                    tmp = dp[j];
                    dp[j] = res;                    
                }
            }
        }
        
        int min = dp[0];
        for(int j = 1; j < col; j++)
            if(min > dp[j]) min = dp[j];
        
        delete[] dp;
        return min;
    }