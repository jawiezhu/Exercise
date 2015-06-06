// The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.



// Given an integer n, return all distinct solutions to the n-queens puzzle.

// Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.

// For example,
// There exist two distinct solutions to the 4-queens puzzle:

// [
//  [".Q..",  // Solution 1
//   "...Q",
//   "Q...",
//   "..Q."],

//  ["..Q.",  // Solution 2
//   "Q...",
//   "...Q",
//   ".Q.."]
// ]

// The classic recursive problem.
// 1. Use a int vector to store the current state, A[i]=j refers that the ith row and jth column is placed a queen.
// 2. Valid state: not in the same column, which is A[i]!=A[current], not in the same diagonal direction: abs(A[i]-A[current]) != r-i

// 3. Recursion: 
// Start: placeQueen(0,n)
// if current ==n then print result
// else
// for each place less than n,
// place queen
// if current state is valid, then place next queen place Queen(cur+1,n)
// end for
// end if

class Solution {
public:
	void printQueen(vector<int> &A,int n,vector<vector<string> >&res)
	{
		vector<string> r;
		for(int i=0;i<n;i++)
		{
			string str(n,'.');
			str[A[i]]='Q';
			r.push_back(str);
		}
		res.push_back(r);
	}
	bool isValidQueens(vector<int>A,int r)
	{
		for(int i=0;i<r;i++)
		{
			if((A[i]==A[r])||(abs(A[i]-A[r]))==(r-i))
				return false;
		}
		return true;
	}
	void nqueens(vector<int> A,int cur,int n,vector<vector<string> >&res)
	{
		if(cur==n)
		{
			printQueen(A,n,res);
		}else{
			for(int i=0;i<n;i++)
			{
				A[cur]=i;
				if(isValidQueens(A,cur))
					nqueens(A,cur+1,n,res);
			}
		}
	}

    vector<vector<string> > solveNQueens(int n) {
        vector<vector<string> >res;
        res.clear();
        vector<int> A(n,-1);
        nqueens(A,0,n,res);
        return res;
    }
};

//
//vector<int> nums(n);num[i]表示第i行的queen放在num[i]列，这样就转化成求0-n-1的全排列，然后看每一个排列是否符合条件。
vector<vector<string>> res;
	void permutationHelper(vector<int> &nums, int index, int n)
	{
		if(index == n)
		{
			bool flag = true;
			for(int i = 0; i<n && flag; i++)
				for(int j=i+1; j<n; j++)
					if((j-i) == abs(nums[j]-nums[i]))
					{
						flag = false;
						break;
					}

			if(flag)
			{
				vector<string> tmp;
				for(int i =0; i<n;i++)
				{
					string row(n,'.');
					row[nums[i]]='Q';
					tmp.push_back(row);
				}
				res.push_back(tmp);
			}
		}
		for(int i = index; i < n; i++)
		{
			swap(nums[index], nums[i]);
			permutationHelper(nums, index+1, n);
			swap(nums[index], nums[i]);
		}
	}
	void permutation(int n)
	{
		vector<int> nums(n);
		for(int i = 0; i < n; i++)
			nums[i] = i;
		permutationHelper(nums,0,n);
	}
	vector<vector<string> > solveNQueens(int n) {
        // Note: The Solution object is instantiated only once.
        res.clear();
		permutation(n);
		return res;
    }

//===========================================

class Solution {
private:
    vector<vector<string> > ret;
    int a[100];
    bool canUse[100];
public:
    bool check(int y, int n)
    {
        for(int i = 0; i < n; i++)
            if (abs(i - n) == abs(y - a[i]))
                return false;
        return true;
    }
    
    void solve(int dep, int maxDep)
    {
        if (dep == maxDep)
        {
            vector<string> ans;
            for(int i = 0; i < maxDep; i++)
            {
                string s;
                for(int j = 0; j < a[i]; j++)
                    s += '.';
                s += 'Q';
                for(int j = 0; j < maxDep - (a[i] + 1); j++)
                    s += '.';
                ans.push_back(s);
            }
            ret.push_back(ans);
            
            return;
        }
        
        for(int i = 0; i < maxDep; i++)
            if (canUse[i] && check(i, dep))
            {
                canUse[i] = false;
                a[dep] = i;
                solve(dep + 1, maxDep);
                canUse[i] = true;             
            }
    }
    
    vector<vector<string> > solveNQueens(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ret.clear();
        memset(canUse, true, sizeof(canUse));
        solve(0, n);
        return ret;
    }
};


//=======================================

class Solution {
public:
    vector<vector<string>> solution;
    
    void generate_solution(const vector<int>& queen)
    {
        vector<string> s;
        for(int i = 0; i < queen.size(); ++i)
        {
            string l(queen.size(), '.');
            l[queen[i]] = 'Q';
            s.emplace_back(move(l));     // avoid copy!
        }
        solution.emplace_back(move(s));
    }
    
    void traverse_solution_space(vector<int>& queen, int placed, int total)
    {
        if (placed == total)
        {
            generate_solution(queen);    
            return;
        }
        
        // try place the queens
        for(int i = 0; i < queen.size(); ++i)
        {
            bool valid = true;
            // verify the position
            for(int j = 0; j < placed; ++j)
            {
                if (i == queen[j] ||  // same column
                    abs(queen[j] - i) == placed - j) // diagonal attack
                {
                    valid = false;
                    break;
                }
            }
            
            if (valid)
            {
                queen[placed] = i;
                traverse_solution_space(queen, placed + 1, total);
            }
        }
    }

    vector<vector<string> > solveNQueens(int n) {
        solution.clear();
        vector<int> queen(n);
        
        traverse_solution_space(queen, 0, n);
        
        return solution;
    }
};


//===============================
// LeetCode, N-Queens
// 深搜+剪枝
// 时间复杂度O(n!)，空间复杂度O(n)
class Solution {
public:
    vector<vector<string> > solveNQueens(int n) {
        this->columns = vector<int>(n, 0);
        this->main_diag = vector<int>(2 * n, 0);
        this->anti_diag = vector<int>(2 * n, 0);

        vector<vector<string> > result;
        vector<int> C(n, 0);  // C[i]表示第i行皇后所在的列编号
        dfs(C, result, 0);
        return result;
    }
private:
    // 这三个变量用于剪枝
    vector<int> columns;  // 表示已经放置的皇后占据了哪些列
    vector<int> main_diag;  // 占据了哪些主对角线
    vector<int> anti_diag;  // 占据了哪些副对角线

    void dfs(vector<int> &C, vector<vector<string> > &result, int row) {
        const int N = C.size();
        if (row == N) { // 终止条件，也是收敛条件，意味着找到了一个可行解
            vector<string> solution;
            for (int i = 0; i < N; ++i) {
                string s(N, '.');
                for (int j = 0; j < N; ++j) {
                    if (j == C[i]) s[j] = 'Q';
                }
                solution.push_back(s);
            }
            result.push_back(solution);
            return;
        }

        for (int j = 0; j < N; ++j) {  // 扩展状态，一列一列的试
            const bool ok = columns[j] == 0 && main_diag[row + j] == 0 &&
                    anti_diag[row - j + N] == 0;
            if (！ok) continue;  // 剪枝：如果合法，继续递归
            // 执行扩展动作
            C[row] = j;
            columns[j] = main_diag[row + j] = anti_diag[row - j + N] = 1;
            dfs(C, result, row + 1);
            // 撤销动作
            // C[row] = 0;
            columns[j] = main_diag[row + j] = anti_diag[row - j + N] = 0;
        }
    }
};







