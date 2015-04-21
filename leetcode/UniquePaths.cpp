// A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

// The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

// How many possible unique paths are there?


// Above is a 3 x 7 grid. How many possible unique paths are there?

// Note: m and n will be at most 100.

//会超时
class Solution {
public:
	

	int numofpath(int beginx,int beginy,int endx,int endy)
	{
		if(beginx==endx&&beginy==endy)
			return 1;
		if(beginx>endx||beginy>endy)
			return 0;

		return numofpath(beginx+1,beginy,endx,endy)+numofpath(beginx,beginy+1,endx,endy);

	}

    int uniquePaths(int m, int n) {
    	if(m==0||n==0) return 0;
        return numofpath(1,1,m,n);
    }
};

//解题：从左上角走到右下角，每次只能向下或者向右走一步，不管怎么走都需要m+n-2步才能走到，而这其中有m-1步是向下走，有n-1是向右走，只用从这m+n-2个位置中选择m-1个位置，
//则剩余的位置表示向右走。容易求得值是Cm-1m+n-2,利用杨辉三角即可。


//开一个f[m][n]的数组，f[i][j] = f[i-1][j] + f[i][j-1]，空间时间复杂度O(m*n)。用滚动数组空间复杂度可降为O(n)
class Solution {
public:

    int uniquePaths(int m, int n) {
    	vector<vector<int>>f(m,vector<int>(n));

    	for(int i=0;i<n;i++)
    		f[0][i]=1;
    	for(int i=0;i<m;i++)
    		f[i][0]=1;
    	for(int i=1;i<m;i++)
    		for(int j=1;j<n;j++)
    			f[i][j]=f[i-1][j]+f[i][j-1];

    	return f[m-1][n-1];
    }
};


//====================
// Dynamic Programming Solution using Bottom-up Approach:
// If you notice closely, the above DP solution is using a top-down approach. Now let’s try a bottom-up approach. Remember this important relationship that is necessary for this DP solution to work:

// The total unique paths at grid (r,c) is equal to the sum of total unique paths from grid to the right (r,c+1) and the grid below (r+1,c).
// How can this relationship help us solve the problem? 
// We observe that all grids of the bottom edge and right edge must all have only one unique path to the bottom-right corner. 
// Using this as the base case, we can build our way up to our solution at grid (1,1) using the relationship above.

const int M_MAX = 100;
const int N_MAX = 100;
 
int dp(int m, int n) {
  int mat[M_MAX+2][N_MAX+2] = {0};
  mat[m][n+1] = 1;
 
  for (int r = m; r >= 1; r--)
    for (int c = n; c >= 1; c--)
      mat[r][c] = mat[r+1][c] + mat[r][c+1];
 
  return mat[1][1];
}

//Pretty easy, use dynamic programming, from bottom line to top line, caculate every the path num of every cell.
class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m <= 0 || n <= 0)
            return 0;
        vector<int> nums;
        for(int i = 0; i < m; i ++) {
            if(i == 0) {
                for(int j = 0; j < n; j++)
                    nums.push_back(1);
            } else {
                for(int j = 1; j < n; j ++) {
                    nums[j] += nums[j - 1];
                }
            }
        }
        return nums[n - 1];
    }
};


//第一种，动态规划，比较好想。对于任意一点(x,y)，要么是从(x,y)的左相邻点(x,y-1)过来，要么是从(x,y)的上相邻点(x-1,y)过来。
//如果用f(x,y)来表示robot走到点(x,y)时的走法，那么f(x,y)=f(x-1,y)+f(x,y-1)。
// 其中，base条件是。当(x,y)位于最上面一行或者最左边一列时，由于robot要么向右走要么向下走，显然只能有1种走法，
// 即f(x,y)=1 if(x==1 or y==0)。这个做法的时间复杂度为O(m,n)，空间复杂度为O(m,n)。
// 如果稍微优化一下，空间复杂度是可以降低为O(min(m,n))的。见下面代码。
// 第二种，排列组合，挺巧妙的，正好在Cracking the Code Interview书中看到了这种解法。
// robot从第(1,1)点走到了第(m,n)点。它只能向右或者向下，不管它怎么走，它必然向右走了m-1步，向下走了n-1步。一共走了m-1+n-1步。
// 而不同的走法，本质是向右或者向下构成的m-1+n-1长度的序列不同。
// 走法的总数目，本质上是m-1+n-1个总步数中选出m-1个代表向右走的走法的个数，这个问题的另一种表述是，
// 走法的总数目，本质上是m-1+n-1个总步数中选出n-1个代表向下走的走法的个数。这其实正是组合的小性质。
// C(a+b, a)=C(a+b, b)
// 这样题目就转换为了一个数学计算了，求C(m-1+n-1, m-1)。

// 第三种，递归的做法。
// 比较耗时间，我用OJ尝试着提交了一下递归的做法，发现超时了。

// version 2 动态规划 bottom-up 空间复杂度由O(m*n)变化为O(min(m,n));
class Solution {
public:
    int uniquePaths(int m, int n) {
        int s=(m<n)?m:n;
        int l=(m>n)?m:n;
        int * arr= new int [s];
        for(int j=0;j<s;j++)
            arr[j]=1;
        for(int i=1;i<l;i++){
            for(int j=1;j<s;j++){
                arr[j]+=arr[j-1];
            }
        }
        return arr[s-1];
    }
};

//=======排列组合
class Solution {
private:
    long long cal_factorial(long a, long start = 1) {
        long long res= 1;
        while (a >= start) {
            res *= a;    
            a--;
        }
        return res;
    }
public:
    int uniquePaths(int m, int n) {
        int max_mn = m>n?m:n; //尽可能使得乘积较小，防止溢出
        long long a = cal_factorial(m + n - 2, max_mn);
        long long b = cal_factorial(m + n - 2 - max_mn + 1);
        long long result = a/b;
        return result;    
}
};