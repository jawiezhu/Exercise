// Given a set of distinct integers, nums, return all possible subsets.

// Note:
// Elements in a subset must be in non-descending order.
// The solution set must not contain duplicate subsets.
// For example,
// If nums = [1,2,3], a solution is:

// [
//   [3],
//   [1],
//   [2],
//   [1,2,3],
//   [1,3],
//   [2,3],
//   [1,2],
//   []
// ]

class Solution {
private:
	vector<vector<int> >ret;

public:
	void dfs(int dep,int maxDep,vector<int> &num,vector<int> a,int start)
	{
		ret.push_back(a);

		if(dep==maxDep)
			return ;

		for(int i=start;i<num.size();i++)
		{
			vector<int> b(a);
			b.push_back(num[i]);
			dfs(dep+1,maxDep,num,b,i+1);
		}
	}

    vector<vector<int> > subsets(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        ret.clear();
        vector<int> a;
        dfs(0,nums.size(),nums,a,0);

        return ret;
    }
};



// 思路1：递归，放与不放的问题。
// 思路2：循环生成子集，然后找子集中依次添加新元素。子集的元素个数可能有0，1，2...n个。
// 所以可以循环在更小的子集中添加元素形成更大的子集。为了防止重复，可以先将输入字符串排序。
class Solution {
public:
    vector<vector<int> >*  v;
    vector<vector<int> > subsets(vector<int> &S) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        v = new vector<vector<int> >();
        
        sort(S.begin(),S.end());
        
        vector<int> res;
        generate(res, S, 0);
        
        return *v;
    }
    
    void generate(vector<int> res, vector<int> &S, int i)
    {
        if(i == S.size())
        {
            v->push_back(res);
            return;
        }
        else
        {
            generate(res, S, i+1);
            res.push_back(S[i]);
            generate(res, S, i+1);
        }
    }
};

class Solution {
public:
    vector<vector<int>> subsets(vector<int> &S) {
        sort(S.begin(),S.end());
        vector<vector<int>> r;
        vector<vector<int>> pre;
        vector<vector<int>> cur;
        int len=0;
        vector<int> tmp;
        cur.push_back(tmp);
        do
        {
            pre = cur;
            cur.clear();
            for(int i=0;i<pre.size();i++)
            {
                r.push_back(pre[i]);
                if(pre[i].size()>0)
                {
                    for(int j=0;j<S.size();j++)
                    {
                        if(S[j]<pre[i][0])
                        {
                            vector<int> tmp = pre[i];
                            tmp.insert(tmp.begin(),S[j]);
                            cur.push_back(tmp);
                        }
                        else
                        {
                            break;
                        }
                    }
                }
                else
                {
                    for(int j=0;j<S.size();j++)
                    {
                        vector<int> tmp = pre[i];
                        tmp.insert(tmp.begin(),S[j]);
                        cur.push_back(tmp);
                    }
                }
            }
            len++;
        }while(len<=S.size());
        return r;
    }
};


// 可以用递推的思想，观察S=[], S =[1], S = [1, 2] 时解的变化。

// 可以发现S=[1, 2] 的解就是 把S = [1]的所有解末尾添上2，然后再并上S = [1]里面的原有解。
// 因此可以定义vector<vector<int> > 作为返回结果res, 开始时res里什么都没有，
// 第一步放入一个空的vecotr<int>，然后这样迭代n次，每次更新res 内容，最后返回res。
class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        vector<vector<int> > res;
        vector<int> emp;
        res.push_back(emp);
        sort(S.begin(), S.end());
        if(S.size() == 0) return res;
        for(vector<int>::iterator ind = S.begin(); ind < S.end(); ++ind){
            int size = res.size();
            for(int i = 0; i < size; ++i){
                vector<int> v;
                for(vector<int>::iterator j = res[i].begin(); j < res[i].end(); ++j){
                   v.push_back(*j);
                }
                v.push_back(*ind);
                res.push_back(v);
            }
        }
        return res;
    }
};

// 所谓子集，就是包含原集合中的一些元素，不包含另一些元素。
// 如果单独看某一个元素，它都有两种选择："被包含在子集中"和"不被包含在子集中"，
// 对于元素个数为n、且不含重复元素的S，子集总数是2n。因此我们可以遍历S的所有元素，
// 然后用递归考虑每一个元素包含和不包含的两种情况。
class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        vector<int> v;
        sort(S.begin(), S.end());
        subsetsCore(S, 0, v);
        return res;
    }
private:
    vector<vector<int> > res;
    void subsetsCore(vector<int> &S, int start, vector<int> &v){
        if(start == S.size()) { res.push_back(v); return;}
        vector<int> v2;
        for(vector<int>::iterator i = v.begin(); i < v.end(); v2.push_back(*(i++)));
        v.push_back(S[start]);
        subsetsCore(S, start+1, v); //包含S[start]
        subsetsCore(S, start+1, v2); //不包含S[start]
    }
};


// LeetCode, Subsets
// 增量构造法，深搜，时间复杂度O(2^n)，空间复杂度O(n)
class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        sort(S.begin(), S.end());  // 输出要求有序
        vector<vector<int> > result;
        vector<int> path;
        subsets(S, path, 0, result);
        return result;
    }

private:
    static void subsets(const vector<int> &S, vector<int> &path, int step,
            vector<vector<int> > &result) {
        if (step == S.size()) {
            result.push_back(path);
            return;
        }
        // 不选S[step]
        subsets(S, path, step + 1, result);
        // 选S[step]
        path.push_back(S[step]);
        subsets(S, path, step + 1, result);
        path.pop_back();
    }
};

// LeetCode, Subsets
// 位向量法，深搜，时间复杂度O(2^n)，空间复杂度O(n)
class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        sort(S.begin(), S.end());  // 输出要求有序

        vector<vector<int> > result;
        vector<bool> selected(S.size(), false);
        subsets(S, selected, 0, result);
        return result;
    }

private:
    static void subsets(const vector<int> &S, vector<bool> &selected, int step,
            vector<vector<int> > &result) {
        if (step == S.size()) {
            vector<int> subset;
            for (int i = 0; i < S.size(); i++) {
                if (selected[i]) subset.push_back(S[i]);
            }
            result.push_back(subset);
            return;
        }
        // 不选S[step]
        selected[step] = false;
        subsets(S, selected, step + 1, result);
        // 选S[step]
        selected[step] = true;
        subsets(S, selected, step + 1, result);
    }
};

// LeetCode, Subsets
// 迭代版，时间复杂度O(2^n)，空间复杂度O(1)
class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        sort(S.begin(), S.end()); // 输出要求有序
        vector<vector<int> > result(1);
        for (auto elem : S) {
            result.reserve(result.size() * 2);
            auto half = result.begin() + result.size();
            copy(result.begin(), half, back_inserter(result));
            for_each(half, result.end(), [&elem](decltype(result[0]) &e){
                e.push_back(elem);
            });
        }
        return result;
    }
};

// 本方法的前提是：集合的元素不超过int 位数。用一个int 整数表示位向量，第i 位为1，则表示
// 选择S[i]，为0 则不选择。例如S={A,B,C,D}，则0110=6 表示子集{B,C}。这种方法最巧妙。因为它不仅能生成子集，还能方便的表示集合的并、交、差等集合运算。设两个集合的位向量分别为B1 和B2，则$B_1\cup B_2, B_1 \cap B_2, B_1 \triangle B_2$分别对应集合的并、交、对称差。
// 二进制法，也可以看做是位向量法，只不过更加优化。
// LeetCode, Subsets
// 二进制法，时间复杂度O(2^n)，空间复杂度O(1)
class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        sort(S.begin(), S.end()); // 输出要求有序
        vector<vector<int> > result;
        const size_t n = S.size();
        vector<int> v;

        for (size_t i = 0; i < 1 << n; i++) {
            for (size_t j = 0; j < n; j++) {
                if (i & 1 << j) v.push_back(S[j]);
            }
            result.push_back(v);
            v.clear();
        }
        return result;
    }
};



// 思路1：递归，放与不放的问题。
// 思路2：循环生成子集，然后找子集中依次添加新元素。
// 子集的元素个数可能有0，1，2...n个。
// 所以可以循环在更小的子集中添加元素形成更大的子集。为了防止重复，可以先将输入字符串排序。
class Solution {
public:
    vector<vector<int> >*  v;
    vector<vector<int> > subsets(vector<int> &S) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        v = new vector<vector<int> >();
        
        sort(S.begin(),S.end());
        
        vector<int> res;
        generate(res, S, 0);
        
        return *v;
    }
    
    void generate(vector<int> res, vector<int> &S, int i)
    {
        if(i == S.size())
        {
            v->push_back(res);
            return;
        }
        else
        {
            generate(res, S, i+1);
            res.push_back(S[i]);
            generate(res, S, i+1);
        }
    }
};

class Solution {
public:
    vector<vector<int>> subsets(vector<int> &S) {
        sort(S.begin(),S.end());
        vector<vector<int>> r;
        vector<vector<int>> pre;
        vector<vector<int>> cur;
        int len=0;
        vector<int> tmp;
        cur.push_back(tmp);
        do
        {
            pre = cur;
            cur.clear();
            for(int i=0;i<pre.size();i++)
            {
                r.push_back(pre[i]);
                if(pre[i].size()>0)
                {
                    for(int j=0;j<S.size();j++)
                    {
                        if(S[j]<pre[i][0])
                        {
                            vector<int> tmp = pre[i];
                            tmp.insert(tmp.begin(),S[j]);
                            cur.push_back(tmp);
                        }
                        else
                        {
                            break;
                        }
                    }
                }
                else
                {
                    for(int j=0;j<S.size();j++)
                    {
                        vector<int> tmp = pre[i];
                        tmp.insert(tmp.begin(),S[j]);
                        cur.push_back(tmp);
                    }
                }
            }
            len++;
        }while(len<=S.size());
        return r;
    }
};