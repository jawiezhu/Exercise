// Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

// For example,
// If n = 4 and k = 2, a solution is:

// [
//   [2,4],
//   [3,4],
//   [2,3],
//   [1,2],
//   [1,3],
//   [1,4],
// ]

//dfs 递归
class Solution {
public:
	static void dfs(int n,int k,int start,int cur,vector<int> &path,vector<vector<int> >&result)
	{
		if(cur==k)
			result.push_back(path);

		for(int i=start;i<=n;i++)
		{
			path.push_back(i);
			dfs(n,k,i+1,cur+1,path,result);
			path.pop_back();
		}
	}
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int> >result;
        vector<int> path;
        dfs(n,k,1,0,path,result);
        return result;
    }
};

//迭代
// LeetCode, Combinations
// use prev_permutation()
// 时间复杂度O((n-k)!)，空间复杂度O(n)
class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        vector<int> values(n);
        iota(values.begin(), values.end(), 1);

        vector<bool> select(n, false);
        fill_n(select.begin(), k, true);

        vector<vector<int> > result;
        do{
            vector<int> one(k);
            for (int i = 0, index = 0; i < n; ++i)
                if (select[i])
                    one[index++] = values[i];
            result.push_back(one);
        } while(prev_permutation(select.begin(), select.end()));
        return result;
    }
};


// LeetCode, Combinations
// 深搜，递归
// 时间复杂度O(n!)，空间复杂度O(n)
class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int> > result;
        vector<int> path;
        dfs(n, k, 1, 0, path, result);
        return result;
    }
private:
    // start，开始的数, cur，已经选择的数目
    static void dfs(int n, int k, int start, int cur,
            vector<int> &path, vector<vector<int> > &result) {
        if (cur == k) {
            result.push_back(path);
        }
        for (int i = start; i <= n; ++i) {
            path.push_back(i);
            dfs(n, k, i + 1, cur + 1, path, result);
            path.pop_back();
        }
    }
};


//================
class Solution {
private:
    vector<vector<int> > ret;
    vector<int> a;
public:
    void solve(int dep, int maxDep, int n, int start)
    {
        if (dep == maxDep)
        {
            ret.push_back(a);
            return;
        }
        
        for(int i = start; i <= n; i++)
        {
            a[dep] = i;
            solve(dep + 1, maxDep, n, i + 1);
        }      
    }
    
    vector<vector<int> > combine(int n, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        a.resize(k);
        ret.clear();
        solve(0, k, n, 1);
        return ret;
    }
};



//com表示从第p位开始选出第l个数。
class Solution {
public:
    void com(int n, int k, int l, int p, vector< vector<int> > &result, vector<int> &rcd)
    {
        if(l == k)
        {
            result.push_back(rcd);
            return;
        }
        for(int i = p; i < n; ++i)
        {
            rcd[l] = i + 1;
            com(n, k, l+1, i+1, result, rcd);
        }
    }
    vector<vector<int> > combine(int n, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector< vector<int> > result;
        vector<int> rcd(k);
        com(n, k, 0, 0, result, rcd);
        return result;
    }
};