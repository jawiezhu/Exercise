// Given a string s, partition s such that every substring of the partition is a palindrome.

// Return all possible palindrome partitioning of s.

// For example, given s = "aab",
// Return

//   [
//     ["aa","b"],
//     ["a","a","b"]
//   ]

class Solution {
public:
	void dfs(string s,vector<string> &path,vector<vector<string> >&res)
	{

		if(s.size()<1) 
		{
			res.push_back(path);
			return ;
		}

		for(int i=0;i<s.size();i++)
		{
			int begin=0;
			int end=i;

			while(begin<end)
			{
				if(s[begin]==s[end])
				{
					begin++;
					end--;
				}else
				{
					break;
				}
			}

			if(begin>=end)
			{
				path.push_back(s.substr(0,i+1));
				dfs(s.substr(i+1),path,res);
				path.pop_back();
			}
		
		}
	}
    vector<vector<string>> partition(string s) {
        vector<vector<string> >res;
        vector<string> path;
        dfs(s,path,res);
        return res;
    }
};


//======================
// 用递归来做，任意一个划分的方法，都是一个vector<string>，如果它非空，那么肯定存在他的第一个元素。对任意一个字符串s：

//     for i=1:s.length

//             s1=s[0~i]

//             s2=[i~end]

//              s1是回文串吗？如果不是，那就continue

//              如果是：

//               对s2进行递归，得到s2的输出，s2可能有多种划分方式，那么，在每一种的前面加上s1即可！
//     end

//     递归结束的条件是，输入的字符串长度为0（那么直接返回空的vector），或者输入的字符串的长度为1（返回仅包含该字母的veector）。
class Solution {
public:
  bool is_huiwen(const string &s)
    {
        int l=s.length();
        int i;
        for(i=0; i<l/2; i++)
            if(s[i] != s[l-1-i])
                return false;
        return true;
    }
    
    vector<vector<string> > partition(string s) 
    {
        
        int l=s.length();
  //   cout<<"l="<<l<<endl;
        vector<vector<string> >vv;
        vector<string> v;
        if(l==0)
        {
            return vv;
        }

        int i;
        for(i=1; i<l; i++)
        {
            string ts=s.substr(0,i);
      //   cout<<"i= "<<i<<" ts= "<<ts;
            if(! is_huiwen(ts) )
                continue;
            string ts_end=s.substr(i,s.length() - i);
     //    cout<<"ts_end = "<<ts_end<<endl;
            vector<vector<string> > vvt;
            vvt=partition(ts_end);
            int j;
            for(j=0; j<vvt.size(); j++)
            {
                
                vvt[j].insert(vvt[j].begin(), ts);
             //  for(int m=0;m<vvt[j].size();m++)cout<<vvt[j][m]<<" ";cout<<endl;
                vv.push_back(vvt[j]);
            }
        }
        if(is_huiwen(s) )
        {
            v.push_back(s);
            vv.push_back(v);
        }
        return vv;
    }
};


//============================================================================================
// 深度优先搜索可以是一个递归，不同于普通的递归是：普通的递归一般为：

// void func() {

// 　　//terminated condition

// 　　//do sth..

// 　　func();

// }

// 而深度优先搜索的形式一般为:

// void func() {

// 　　//terminated condition　　中止条件肯定是有的

// 　　//do sth..

// 　　for ( ... ) {　　　　//当前层所有的可能往下一层走的分支，但是因为for是一次一次执行循环的，所以func会不停地往下调用，直到调用到terminated condition为止，然后再回退，回退到当前层的for的下一次循环

// 　　　　func();　　　　//注意这里，在当前层，func会递归执行很多次

// 　　}

// }


//LeetCode, Palindrome Partitioning
// 时间复杂度O(2^n)，空间复杂度O(n)
class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> path;  // 一个partition方案
        dfs(s, path, result, 0, 1);
        return result;
    }

    // s[0, prev-1]之间已经处理，保证是回文串
    // prev 表示s[prev-1]与s[prev]之间的空隙位置，start同理
    void dfs(string &s, vector<string>& path,
            vector<vector<string>> &result, size_t prev, size_t start) {
        if (start == s.size()) { // 最后一个隔板
            if (isPalindrome(s, prev, start - 1)) { // 必须使用
                path.push_back(s.substr(prev, start - prev));
                result.push_back(path);
                path.pop_back();
            }
            return;
        }
        // 不断开
        dfs(s, path, result, prev, start + 1);
        // 如果[prev, start-1] 是回文，则可以断开，也可以不断开（上一行已经做了）
        if (isPalindrome(s, prev, start - 1)) {
            // 断开
            path.push_back(s.substr(prev, start - prev));
            dfs(s, path, result, start, start + 1);
            path.pop_back();
        }
    }

    bool isPalindrome(const string &s, int start, int end) {
        while (start < end && s[start] == s[end]) {
            ++start;
            --end;
        }
        return start >= end;
    }
};



//LeetCode, Palindrome Partitioning
// 时间复杂度O(2^n)，空间复杂度O(n)
class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> path;  // 一个partition方案
        DFS(s, path, result, 0);
        return result;
    }
    // 搜索必须以s[start]开头的partition方案
    void DFS(string &s, vector<string>& path,
            vector<vector<string>> &result, int start) {
        if (start == s.size()) {
            result.push_back(path);
            return;
        }
        for (int i = start; i < s.size(); i++) {
            if (isPalindrome(s, start, i)) { // 从i位置砍一刀
                path.push_back(s.substr(start, i - start + 1));
                DFS(s, path, result, i + 1);  // 继续往下砍
                path.pop_back(); // 撤销上上行
            }
        }
    }
    bool isPalindrome(const string &s, int start, int end) {
        while (start < end && s[start] == s[end]) {
            ++start;
            --end;
        }
        return start >= end;
    }
};



// LeetCode, Palindrome Partitioning
// 动规，时间复杂度O(n^2)，空间复杂度O(1)
class Solution {
public:
    vector<vector<string> > partition(string s) {
        const int n = s.size();
        bool p[n][n]; // whether s[i,j] is palindrome
        fill_n(&p[0][0], n * n, false);
        for (int i = n - 1; i >= 0; --i)
            for (int j = i; j < n; ++j)
                p[i][j] = s[i] == s[j] && ((j - i < 2) || p[i + 1][j - 1]);

        vector<vector<string> > sub_palins[n]; // sub palindromes of s[0,i]
        for (int i = n - 1; i >= 0; --i) {
            for (int j = i; j < n; ++j)
                if (p[i][j]) {
                    const string palindrome = s.substr(i, j - i + 1);
                    if (j + 1 < n) {
                        for (auto v : sub_palins[j + 1]) {
                            v.insert(v.begin(), palindrome);
                            sub_palins[i].push_back(v);
                        }
                    } else {
                        sub_palins[i].push_back(vector<string> { palindrome });
                    }
                }
        }
        return sub_palins[0];
    }
};







