// Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

// The same repeated number may be chosen from C unlimited number of times.

// Note:
// All numbers (including target) will be positive integers.
// Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
// The solution set must not contain duplicate combinations.
// For example, given candidate set 2,3,6,7 and target 7, 
// A solution set is: 
// [7] 
// [2, 2, 3] 

class Solution {
public:
	// start 从candidates开始的位置, sum当前的和,target目标和,path存放满足条件的值,res 存放所有结果
	void com(vector<int> &candidates,int start,int sum,int target,vector<int> &path,vector<vector<int> > &res)
	{
		if(sum>target)//超出目标值 退出
			return ;
		if(sum==target)// 找到一种解
		{
			res.push_back(path);
			return ;
		}

		int len=candidates.size();
		for(int i=start;i<len;i++)
		{
			path.push_back(candidates[i]);//存放当前值
			com(candidates,i,sum+candidates[i],target,path,res);
			path.pop_back();//回溯
		}
	}

    vector<vector<int> > combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int> > res;
        vector<int> path;
        com(candidates,0,0,target,path,res);
        return res;
    }
};



// LeetCode, Combination Sum
// 时间复杂度O(n!)，空间复杂度O(n)
class Solution {
public:
    vector<vector<int> > combinationSum(vector<int> &nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int> > result; // 最终结果
        vector<int> intermediate; // 中间结果
        dfs(nums, target, 0, intermediate, result);
        return result;
    }

private:
    void dfs(vector<int>& nums, int gap, int start, vector<int>& intermediate,
            vector<vector<int> > &result) {
        if (gap == 0) {  // 找到一个合法解
            result.push_back(intermediate);
            return;
        }
        for (size_t i = start; i < nums.size(); i++) { // 扩展状态
            if (gap < nums[i]) return; // 剪枝

            intermediate.push_back(nums[i]); // 执行扩展动作
            dfs(nums, gap - nums[i], i, intermediate, result);
            intermediate.pop_back();  // 撤销动作
        }
    }
};


class Solution {
private:
	const int index_count;
	vector<vector<int> > results;
public:
	Solution() : index_count(10000) {};
	// index记录当前找到的候选数字，n表示当前正在找第几个，n是index的下标不是candidates的下标
	void backtrace(int target, int sum, vector<int> &candidates, int index[], int n)
	{
		if (sum > target)
		{
			return;	// 回溯
		}
		if (sum == target)
		{
			vector<int> result;
			for (int i = 1; i <= n; ++i)
			{
				result.push_back(candidates[index[i]]);	
			}
			results.push_back(result);
			return;	// 此处可以不加，如果不加return由于都是正整数，到下面的计算时会多进行一次无用的递归。
		}

		// 深度搜索，为了避免重复，每次从当前候选项索引到结尾，上面的i=index[n]可以看出
		for (int i = index[n]; i < candidates.size(); ++i)
		{
			index[n+1] = i;	// 记录当前考察的候选项索引
			backtrace(target, sum+candidates[i], candidates, index, n+1);
		}
	}
	vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		sort(candidates.begin(), candidates.end());

		int *index = new int[index_count];
		memset(index, 0, sizeof(int)*index_count);
		
		results.clear();	// 提交到leetcode的测试系统上必须添加，它应该是使用一个对象测试所有测试用例。
		backtrace(target, 0, candidates, index, 0);

		delete[] index;

		return results;
	}
};
