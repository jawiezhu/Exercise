// Given a m x n matrix, if an element is 0, 
// set its entire row and column to 0. Do it in place.

// click to show follow up.

// Follow up:
// Did you use extra space?
// A straight forward solution using O(mn) space is probably a bad idea.
// A simple improvement uses O(m + n) space, but still not the best solution.
// Could you devise a constant space solution?

//时间复杂度过高,ERROR
class Solution {
public:
	void clear(vector<vector<int> >& matrix){
		int col=matrix[0].size();
        int row=matrix.size();

        for(int i=0;i<row;i++)
        {
        	for(int j=0;j<col;j++)

        		matrix[i][j]=0;

        }
	}
    void setZeroes(vector<vector<int>>& matrix) {
        int col=matrix[0].size();
        int row=matrix.size();

        for(int i=0;i<row;i++)
        {
        	for(int j=0;j<col;j++)

        		if(0==matrix[i][j])
        			clear(matrix);
        }

    }
};

//========
// 空间的方法很简单，设置两个bool数组，记录每行和每列是否存在0。

// 想要常数空间，可以复用第一行和第一列。
// 时间复杂度O(mn),空间复杂度O(1)
class Solution{
public:
    void setZeroes(vector<vector<int> > &matrix){
        const size_t m=matrix.size();//row
        const size_t n=matrix[0].size();//col
        bool row_has_zero=false;
        bool col_has_zero=false;

        for(size_t i=0;i<n;i++)
        {
            if(matrix[0][i]==0)
            {
                row_has_zero=true;
                break;
            }
        }

        for(size_t i=0;i<m;i++)
        {
            if(matrix[i][0]==0)
            {
                col_has_zero=true;
                break;
            }
        }

        for(size_t i=1;i<m;i++)
        {
            for(size_t j=1;j<n;j++)
            {
                if(matrix[i][j]==0)
                {
                    matrix[0][j]=0;
                    matrix[i][0]=0;
                }
            }

        }

        for(size_t i=1;i<m;i++)
        {
            for(size_t j=1;j<n;j++)
            {
                if(matrix[i][0]==0||matrix[0][j]==0)
                    matrix[i][j]=0;
            }
        }

        if(row_has_zero)
            for(size_t i=0;i<n;i++)
                matrix[0][i]=0;

        if(col_has_zero)
            for(size_t i=0;i<m;i++)
                matrix[i][0]=0;
    }
};




// LeetCode, Set Matrix Zeroes
// 时间复杂度O(m*n)，空间复杂度O(m+n)
class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        const size_t m = matrix.size();
        const size_t n = matrix[0].size();
        vector<bool> row(m, false); // 标记该行是否存在0
        vector<bool> col(n, false); // 标记该列是否存在0

        for (size_t i = 0; i < m; ++i) {
            for (size_t j = 0; j < n; ++j) {
                if (matrix[i][j] == 0) {
                    row[i] = col[j] = true;
                }
            }
        }

        for (size_t i = 0; i < m; ++i) {
            if (row[i])
                fill(&matrix[i][0], &matrix[i][0] + n, 0);
        }
        for (size_t j = 0; j < n; ++j) {
            if (col[j]) {
                for (size_t i = 0; i < m; ++i) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};


//======================
void setZeroes(vector<vector<int> > &matrix) 
{
    bool bColZero = false, bRowZero = false;
    
    if (matrix.size() == 0 || matrix[0].size() == 0)
    {
        return;
    }
 
    // Mark bColZero true when col[0] contains zero.   
    for (size_t row = 0; row < matrix.size(); ++row)
    {
        if (!matrix[row][0]) bColZero = true;
    }
    
    // Mark bRowZero true when row[0] contains zero.
    for (size_t col = 0; col < matrix[0].size(); ++col)
    {
        if (!matrix[0][col]) bRowZero = true;
    }
    
    // Map zero points to row[0] and col[0].
    for (size_t row = 1; row < matrix.size(); ++row)
    {
        for (size_t col = 1; col < matrix[row].size(); ++col)
        {
            if (!matrix[row][col])
            {
                matrix[0][col] = 0;
                matrix[row][0] = 0;
            }
        }
    }
    
    // Set zero according to row[0] and col[0].
    for (size_t row = 1; row < matrix.size(); ++row)
    {
        for (size_t col = 1; col < matrix[row].size(); ++col)
        {
           if (!matrix[row][0] || !matrix[0][col])
           {
               matrix[row][col] = 0;
           }
        }
    }
    
    // Process col[0].
    if (bColZero)
    {
        for (size_t row = 0; row < matrix.size(); ++row)
        {
            matrix[row][0] = 0;
        }
    }
    
    // Process row[0].
    if (bRowZero)
    {
        for (size_t col = 0; col < matrix[0].size(); ++col)
        {
            matrix[0][col] = 0;
        }
    }
}


//
// 遍历数组找到某一值为0然后遍历他的上下左右直到边界，
// 要用while而不能用搜索，因为搜索过去新节点的操作以旧结点一样的操作
//          要用一个新数组，不然原数组修改后会影响到下次的查找
class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        int i,j;
        int num[330][330];
        for(i=0;i<matrix.size();i++)
        {
            for(j=0;j<matrix[0].size();j++)
            {
                num[i][j]=matrix[i][j];
            }
        }
        for(i=0;i<matrix.size();i++)
        {
            for(j=0;j<matrix[0].size();j++)
            {
                if(num[i][j]==0)
                {
                    int x,y;
                    x=i,y=j;
                    while(x>=0) matrix[x--][y]=0;
                    x=i,y=j;
                    while(x<matrix.size()) matrix[x++][y]=0;
                    x=i,y=j;
                    while(y>=0) matrix[x][y--]=0;
                    x=i,y=j;
                    while(y<matrix[0].size()) matrix[x][y++]=0;
                }
            }
        }
    }
};



// 1：首先编辑出0行是否要清零，0列是否要清零
// 2：遍历数组，若某个matrix[i,j]是:0，则将matrix[0,j]和matrix[i,0]为0
// 3：遍历数组，判断matrix[0,j]==0 || matrix[i,0]==0 若是则matrix[i,j]=0
// 4:  根据步骤1决定0行0列是否清零
class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        int i,j;
        int row=0,col=0;
        //预判出来就是为了防止后面那个修改的错误，要把0行0列排出去
        for(i=0;i<matrix.size();i++)
        {
            if(matrix[i][0]==0)
            {
                col=1;
                break;
            }
        }
        for(i=0;i<matrix[0].size();i++)
        {
            if(matrix[0][i]==0)
            {
                row=1;
                break;
            }
        }
        for(i=0;i<matrix.size();i++)
        {
            for(j=0;j<matrix[0].size();j++)
            {
                if(matrix[i][j]==0)
                {
                    matrix[0][j]=matrix[i][0]=0;
                }
            }
        }
        //这里必须是1，若为0的话，如果matrix[0,0]为0的话,则0行0列全为0了，则真个matrix数组都为0了
        for(i=1;i<matrix.size();i++)
        {
            for(j=1;j<matrix[0].size();j++)
            {
                if(matrix[i][0]==0 || matrix[0][j]==0) matrix[i][j]=0;
            }
        }
        if(row)
        {
            for(i=0;i<matrix[0].size();i++)
                matrix[0][i]=0;
        }
        if(col)
        {
            for(i=0;i<matrix.size();i++)
                matrix[i][0]=0;
        }
    }
};
