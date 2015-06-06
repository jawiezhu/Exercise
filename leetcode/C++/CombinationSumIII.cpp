// Find all possible combinations of k numbers that add up to a number n, given that only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.

// Ensure that numbers within the set are sorted in ascending order.


// Example 1:

// Input: k = 3, n = 7

// Output:

// [[1,2,4]]

// Example 2:

// Input: k = 3, n = 9

// Output:

// [[1,2,6], [1,3,5], [2,3,4]]
class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int> >res;
        vector<int>item;
        dfs(k,n,1,item,res);
        return res;
    }

    void dfs(int k,int n,int level,vector<int> &item,vector<vector<int> >&res)
    {
    	if(n<0) return ;
    	if(n==0&&item.size()==k) res.push_back(item);
    	for(int i=level;i<=9;i++)
    	{
    		item.push_back(i);
    		dfs(k,n-i,i+1,item,res);
    		item.pop_back();
    	}
    }
};



//=======================
class Solution {
public:

    void help(int idx, int k, int n, vector<vector<int>> &ret, vector<int> &cur){
        if(k <= 0){
            if(k == 0 && n == 0)
                ret.push_back(cur);
            return;
        }
        for(int i = idx; i < 10; i++){
            if(n - i >= 0){
                cur.push_back(i);
                help(i + 1,k - 1,n - i,ret,cur);
                cur.pop_back();
            }
            else
                break;
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ret;
        vector<int> cur;
        help(1,k,n,ret,cur);
        return ret;
    }
};
//==============


//===============================
class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        
        vector<int> item;
        helper(result, item, 0, k, n);
        
        return result;
    }
    
    //max是item中最大的那个数，left是还剩下的值，k是需要找的数目
    void helper(vector<vector<int>>& result, vector<int>& item, int max, int k, int left){
        if(item.size()==k&&left==0){
            result.push_back(item);
            return;
        }
        for(int i=max+1; i<=9&&i<=left; i++){
            item.push_back(i);
            helper(result, item, i, k, left-i);
            item.pop_back();
        }
    }
};

//
// 这道题题是组合之和系列的第三道题，跟之前两道Combination Sum 组合之和，
// Combination Sum II 组合之和之二都不太一样，那两道的联系比较紧密，变化不大，
// 而这道跟它们最显著的不同就是这道题的个数是固定的，为k。个人认为这道题跟那道Combinations 组合项更相似一些，
// 但是那道题只是排序，对k个数字之和又没有要求。所以实际上这道题是它们的综合体，两者杂糅到一起就是这道题的解法了，
// n是k个数字之和，如果n小于0，则直接返回，如果n正好等于0，
// 而且此时out中数字的个数正好为k，说明此时是一个正确解，将其存入结果res中，具体实现参见代码入下：

class Solution {
public:
    vector<vector<int> > combinationSum3(int k, int n) {
        vector<vector<int> > res;
        vector<int> out;
        combinationSum3DFS(k, n, 1, out, res);
        return res;
    }
    void combinationSum3DFS(int k, int n, int level, vector<int> &out, vector<vector<int> > &res) {
        if (n < 0) return;
        if (n == 0 && out.size() == k) res.push_back(out);
        for (int i = level; i <= 9; ++i) {
            out.push_back(i);
            combinationSum3DFS(k, n - i, i + 1, out, res);
            out.pop_back();
        }
    }
};


//===
class Solution {
public:
    void visit(int pos, int k, int n, int &sum,  vector<int> &buf, vector<vector<int> > &result)
    {
        if (k == 0)
        {
            if (sum == n)
            {
                result.push_back(buf);
            }
            return;
        }

        for (int i = pos; i <= 9; i++)
        {   
            if (sum + i > n)
            {
                break;
            }
            buf.push_back(i);
            sum += i;
            visit(i+1, k-1, n, sum, buf, result);
            buf.pop_back();
            sum -= i;
        }
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int> > result;
        vector<int> buf;
        int sum = 0;
        visit(1, k, n, sum, buf, result);

        return result;
    }
};



//==
class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int> > result;
        vector<int> num;
        dfs(k, n, result, num, 1);
        return result;
    }
private:
    void dfs(int k, int n, vector<vector<int> > &result, vector<int> &num, int cur){
        if(n == 0 && k == 0){
            result.push_back(num);
            return;
        }
        if(k == 0 || cur > 9 || n < cur)
            return;
        num.push_back(cur);
        dfs(k - 1, n - cur, result, num, cur + 1);
        num.pop_back();
        dfs(k, n, result, num, cur + 1);
    }
};

//==========
class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> cur;
        find_put(0, n, cur, res, k);
        return res;
    }
    // 开始位置， 尚需， 已添加， 结果， 总数
    void find_put(int reach, int need, vector<int>& cur, vector<vector<int> >& res, int num) {
        if(cur.size()==num && need==0) {res.push_back(cur); return;}
		reach++;
        while(reach<10 && reach<=need && cur.size()<num) {
            cur.push_back(reach);
            find_put(reach, need-reach, cur, res, num);
			// 还原状态
            cur.pop_back();
            reach++;
        }
    }
};

