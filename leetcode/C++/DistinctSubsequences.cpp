// Given a string S and a string T, count the number of distinct subsequences of T in S.

// A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).

// Here is an example:
// S = "rabbbit", T = "rabbit"

// Return 3.
class Solution {
public:
    int numDistinct(string s, string t) {
        int lenS=s.size();
        int lenT=t.size();

        vector<vector<int> >f(lenS+1,vector<int>(lenT+1,0));

        for(int i=0;i<=lenS;i++) f[i][0]=1;

        for(int i=1;i<=lenS;i++)
        {
        	for(int j=1;j<=lenT;j++)
        	{
        		if(s[i-1]==t[j-1])
        			f[i][j]=f[i-1][j-1]+f[i-1][j];
        		else
        			f[i][j]=f[i-1][j];
        	}
        }

        return f[lenS][lenT];


    }
};


//设状态为$f(i,j)$，表示{T[0,j]}在{S[0,i]}里出现的次数。
//首先，无论{S[i]}和{T[j]}是否相等，若不使用{S[i]}，则$f(i,j)=f(i-1,j)$；
//若{S[i]==T[j]}，则可以使用{S[i]}，此时$f(i,j)=f(i-1,j)+f(i-1, j-1)$。
// LeetCode, Distinct Subsequences
// 二维动规+滚动数组
// 时间复杂度O(m*n)，空间复杂度O(n)
class Solution {
public:
    int numDistinct(const string &S, const string &T) {
        vector<int> f(T.size() + 1);
        f[0] = 1;
        for (int i = 0; i < S.size(); ++i) {
            for (int j = T.size() - 1; j >= 0; --j) {
                f[j + 1] += S[i] == T[j] ? f[j] : 0;
            }
        }

        return f[T.size()];
    }
};


// DP，化归为二维地图的走法问题。
//        r  a  b  b   i   t
//    1  0  0  0  0  0  0
// r  1 
// a  1
// b  1
// b  1
// b  1
// i  1
// t  1
// 设矩阵transArray，其中元素transArray[i][j]为S[0,...,i]到T[0,...,j]有多少种转换方式。
// 问题就转为从左上角只能走对角（匹配）或者往下（删除字符），到右下角一共有多少种走法。
// transArray[i][0]初始化为1的含义是：任何长度的S，如果转换为空串，那就只有删除全部字符这1种方式。
// 当S[i-1]==T[j-1]，说明可以从transArray[i-1][j-1]走对角到达transArray[i][j]（S[i-1]匹配T[j-1]），此外还可以从transArray[i-1][j]往下到达transArray[i][j]（删除S[i-1]）
// 当S[i-1]!=T[j-1]，说明只能从transArray[i-1][j]往下到达transArray[i][j]（删除S[i-1]）
class Solution {
public:
    int numDistinct(string S, string T) {
        int m = S.size();
        int n = T.size();
        
        vector<vector<int> > path(m+1, vector<int>(n+1, 0));
        for(int i = 0; i < m+1; i ++)
            path[i][0] = 1;
        
        for(int i = 1; i < m+1; i ++)
        {
            for(int j = 1; j < n+1; j ++)
            {
                if(S[i-1] == T[j-1])
                    path[i][j] = path[i-1][j-1] + path[i-1][j];
                else
                    path[i][j] = path[i-1][j];
            }
        }
        
        return path[m][n];
    }
};

//
// 题意解读：只可以用删除字符的方法从第一个字符串变换到第二个字符串，求出一共有多少种变换方法。
// 解题分析：dfs可以做，但大数据超时。
// 动态规划，定义dp[i][j]为字符串i变换到j的变换方法。
// 如果S[i]==T[j]，那么dp[i][j] = dp[i-1][j-1] + dp[i-1][j]。意思是：如果当前S[i]==T[j]，那么当前这个字母即可以保留也可以抛弃，所以变换方法等于保留这个字母的变换方法加上不用这个字母的变换方法。
// 如果S[i]!=T[i]，那么dp[i][j] = dp[i-1][j]，意思是如果当前字符不等，那么就只能抛弃当前这个字符。
// 递归公式中用到的dp[0][0] = 1，dp[i][0] = 0（把任意一个字符串变换为一个空串只有一个方法）
public class Solution {
    public int numDistinct(String S, String T) {
        if(S==null||T==null) {
            return 0;
        }
        if(S.length()<T.length()) {
            return 0;
        }
   	//递推公式用的
        int [][] dp = new int[S.length()+1][T.length()+1];
        dp[0][0] = 1;
        //任意一个字符串变换成一个空串都只有一种变换方法
        for(int i=0;i<S.length();i++) {
            dp[i][0] = 1;    
        }
        //递推公式
        for(int i=1;i<=S.length();i++) {
            for(int j=1;j<=T.length();j++) {
                //如果S和T的当前字符相等，那么有两种选法；否则S的当前字符不能要
                dp[i][j] = dp[i-1][j];
                if(S.charAt(i-1)==T.charAt(j-1)) {
                    dp[i][j] += dp[i-1][j-1];
                }
            }
        }
        return dp[S.length()][T.length()];
    }
}//



// 思路1：递归（TLE）
// 如果当前字符相同，结果加上S和T在该index之后的匹配方法数
// 如果当前字符不同，将S的指针向后移，递归计算
class Solution {
private:
    int cnt;
    int len_s;
    int len_t;
public:
    Solution():cnt(0){}
    void Count(string S,string T, int idx_ss, int idx_ts){
        if(idx_ts == len_t){
            cnt++;
            return;
        }
        int i,j,k;
        for (i=idx_ss; i<len_s; i++) {
            if (S[i] == T[idx_ts]) {
                Count(S, T, i + 1, idx_ts + 1);
            }
        }
    }
    
    int numDistinct(string S, string T) {
        len_s = S.length();
        len_t = T.length();
        Count(S, T, 0, 0);
        return cnt;
    }
};

//
// 思路2：DP
// 如果当前字符相同，dp[i][j]结果等于用S[i](dp[i-1][j-1])和不用S[i](dp[i-1][j])方法数求和
// 如果当前字符不同，dp[i][j] = dp[i-1][j]
class Solution {
private:
    int len_s;
    int len_t;
public:
    int Count(string S,string T){
        int i,j;
        int dp[len_s][len_t];
        memset(dp, 0, sizeof(dp));
        
        if (S[0]==T[0]) {
            dp[0][0] = 1;
        }
        
        for(i=1;i<len_s;i++){
            dp[i][0] = dp[i-1][0];
            if (T[0]==S[i]) {
                dp[i][0]++;
            }
        }
                
        for (i=1; i<len_s; i++) {
            for (j=1; j<len_t && j<=i; j++) {
                if (S[i]!=T[j]) {
                    dp[i][j] = dp[i-1][j];
                    //cout<<dp[i-1][j]<<endl;
                }
                else{
                    dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
                    //dp[i-1][j-1]: use S[i], as S[i]==T[j]
                    //dp[i-1][j]  : don't use S[i]
                    //cout<<dp[i][j]<<endl;
                }
            }
        }
        return dp[len_s-1][len_t-1];
    }
    
    int numDistinct(string S, string T) {
        len_s = S.length();
        len_t = T.length();
        return Count(S, T);
    }
};

//
map<pair<int,int>,int> record;
class Solution {
public:
    int numDistinct(string S, string T) {
        record.clear();
        return vis(S, 0 , S.size() , T , 0 , T.size());
    }
private:
    int vis(string s , int s1 , int e1 , string t , int s2 , int e2) {
        if(s1 == e1) {
            return s2 == e2 ? 1 : 0;
        }
        if(s2 == e2) return 1;
        auto tmp = record.find(make_pair(s1,s2));
        if(tmp != record.end()) return tmp->second;
        
        int cnt = 0;
        for(int i = s1 ; i < e1 ; ++i) {
            if(s[i] == t[s2]) {
                cnt += vis(s , i + 1 , e1 , t , s2 + 1 , e2);
            }
        }
        record.insert(make_pair(make_pair(s1,s2) , cnt));
        return cnt;
    }
};



//递归的算法去做，时间复杂度较高
class Solution {
public:
    string S;
    string T;
    int i;
    int j;
    int count;
    int numDistinct(string S, string T) {
        this->S = S;
        this->T = T;
        int i=0;
        int j=0;
        count =0;
        countDistinct();
        return count;
    }
    
    void countDistinct()
    {
        if(i>=S.size()&&j>=T.size())
        {
            count++;
        }
        else if(i>=S.size())
        {
            return;
        }
        else if(j>=T.size())
        {
            return;
        }
        else
        {
            if(S[i]==T[j])
            {
                i++;
                j++;
                countDistinct();
                j--;
                countDistinct();
                i--;
            }
            else
            {
                i++;
                countDistinct();
                i--;
            }
        }
    }
};


// 利用动态规划去做，我们用dp[i][j]表示S与T的前i个字符与前j个字符的匹配子串个数。可以知道：
// 1）初始条件：T为空字符串时，S为任意字符串都能匹配一次，所以dp[i][0]=1；S为空字符串，S不为空时，不能匹配，所以dp[0][j](j>1)=0。
// 2）若S的第i个字符等于T的第j个字符时，我们有两种匹配的选择：其一，若S的i-1字符匹配T的j-1字符，我们可以选择S的i字符与T的j字符匹配；其二，若S的i-1字符子串已经能与T的j字符匹配，放弃S的i字符与T的j字符。因此这个情况下，dp[i][j]=dp[i-1][j-1]+dp[i-1][j]。
// 3）若S的第i个字符不等于T的第j个字符时，这时只有当S的i-1字符子串已经能与T的j字符匹配，该子串能够匹配。因此这个情况下，dp[i][j]=dp[i-1][j]。
class Solution {
public:
    int** dp;
    int numDistinct(string S, string T) {
        if(S.size()<T.size())
        {
            return 0;
        }
        int** dp= new int*[S.size()+1];
        for(int k=0;k<=S.size();k++)
        {
            dp[k]= new int[T.size()+1];
        }
        for(int i=0;i<=S.size();i++)
        {
            dp[i][0]=1;
        }
        for(int i=1;i<=T.size();i++)
        {
            dp[0][i]=0;
        }
        for(int j=1;j<=T.size();j++)
        {
            for(int i=1;i<=S.size();i++)
            {
                if(S[i-1]==T[j-1])
                {
                    dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
                }
                else
                {
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        return dp[S.size()][T.size()];
    }
};

class Solution {
public:
    int numDistinct(string S, string T) {
        int** dp = new int*[S.size()+1];
        for(int i = 0; i < S.size() + 1; i++){
            dp[i] = new int[T.size()+1];
        }
        
        for(int i = 0; i < S.size() + 1; i++){
            dp[i][0] = 0;
        }
        
        for(int i = 0; i < T.size() + 1; i++){
            dp[0][i] = 0;
        }
        
        dp[0][0] = 1;
        
        int sum = 0;
        for(int i = 1; i < S.size() + 1; i++){
            for(int j = 1; j < T.size() + 1; j++){
                if(S[i-1] == T[j-1]){
                    dp[i][j] = 0;
                    for(int k = 0; k < i; k++){
                        dp[i][j] += dp[k][j-1];
                    }
                    if(j == T.size()){
                        sum += dp[i][j];
                    }
                }else{
                    dp[i][j] = 0;
                }
            }
        }
        
        return sum;
    }
};

// 思路分析：首先引用一个经验总结“When you see string problem that is about subsequence or matching, 
// dynamic programming method should come to your mind naturally.” 这类题目可以看作字符串编辑距离的变形题目，
// 这题的题意是我们只能进行删除操作，有多少做方法可以把S变成T。显然可以用动态规划做，令S与T的长度是m和n，
// 我们定义二维数组dp[m+1][n+1] 表示把S的前m个变成T的前n个的方法数，我们在最前面增加了一维对应空字符串，初始化如下

// dp[0][0] = 1//当S与T都是空时，有一种方法，不做任何删除即可

// dp[0][1 ... n] = 0//当S是空但是T不是空时，没有方案

// dp[1...m][0] = 1 //当T是空时，从S变成T只有一种方法，就是删除所有字符

// 接下来我们来想递推方程。当S[i]!=T[j]时 dp[i][j] = dp[i-1][j]，因为此时我们只能把S前i-1个变成T的前j个，
// 然后删除掉S[i]既可达到目的，因此有dp[i-1][j]种方法；当S[i]=T[j]时，显然上面的方法仍然可行，同时我们多了一种方法，
// 就是把S的前i-1个变成T的前j-1个，然后加上后面相等的字符自然可以匹配上，因此这时dp[i][j] = dp[i-1][j] + dp[i-1][j-1]。综上所述我们有

// dp[i][j] = dp[i-1][j] + (S.charAt(i-1) == T.charAt(j-1) ? dp[i-1][j-1] : 0)

// 有了递推方程，解决这题就变成二维数组填表了，很容易解决。这类字符串匹配题目还有很多，可以联系编辑距离那道题来想，
// 很多都可以用动态规划解决。最后引用一个经典的示意图，显示了题目中例子的计算过程，但是注意这个例子中行列的定义和我相反，
// 图中行对应T，列对应S，要加以区分，但是计算过程是相同的。来源 http://blog.csdn.net/abcbc/article/details/8978146


//    r a b b b i t
//   1 1 1 1 1 1 1 1
// r 0 1 1 1 1 1 1 1
// a 0 0 1 1 1 1 1 1
// b 0 0 0 1 2 3 3 3
// b 0 0 0 0 1 3 3 3
// i 0 0 0 0 0 0 3 3
// t 0 0 0 0 0 0 0 3  

public class Solution {
    public int numDistinct(String S, String T) {
        //varations of edit distance problems
        //you can only delete chars to change S to T
        //if(S.isEmpty()) return 0;
        //if(T.isEmpty()) return 1;
        int m = S.length();
        int n = T.length();
        int [][] dp = new int[m + 1][n + 1];
        dp[0][0] = 1;
        for(int i = 1; i <= m; i++){
            dp[i][0] = 1;
        }
        for(int i = 1; i <= n; i++){
            dp[0][i] = 0;
        }
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                dp[i][j] = dp[i-1][j] + (S.charAt(i-1) == T.charAt(j-1) ? dp[i-1][j-1] : 0);
            }
        }
        return dp[m][n];
    }
}//

//超时
class Solution {
public:
    int numDistinct(string S, string T) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int result=0;
        match(S,T,-1,-1,result);
        return result;
    }
    
    void match(string S, string T, int lastS, int lastT, int &result)
    {
        if(lastT==T.length()-1) 
        {
            result++;
            return;
        }
        
        for(int i=lastS+1;i<S.length();i++)
        {
            if(T[lastT+1]==S[i])
            {
                match(S,T,i,lastT+1,result);
            }
        }
        
    }
};



