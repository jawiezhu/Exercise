// Given two words word1 and word2, find the minimum number of steps required to convert word1 to word2. 
// (each operation is counted as 1 step.)

// You have the following 3 operations permitted on a word:

// a) Insert a character
// b) Delete a character
// c) Replace a character

class Solution {
public:
    int minDistance(string word1, string word2) {
        int len1=word1.size();
        int len2=word2.size();

        if(len1==0||len2==0) return max(len1,len2);

        vector<vector<int> > f(len1+1,vector<int>(len2+1));

        for(int i=0;i<=len1;i++) f[i][0]=i;
        for(int j=0;j<=len2;j++) f[0][j]=j;

        for(int i=1;i<=len1;i++)
        {
        	for(int j=1;j<=len2;j++)
        	{
        		if(word1[i-1]==word2[j-1])
        			f[i][j]=f[i-1][j-1];
        		else{
        			int tmp=min(f[i-1][j],f[i][j-1]);
        			f[i][j]=min(tmp,f[i-1][j-1])+1;
        		}

        	}
        }

        return f[len1][len2];
    }
};


//
// 设状态为{f[i][j]}，表示{A[0,i]}和{B[0,j]}之间的最小编辑距离。设{A[0,i]}的形式是{str1c}，{B[0,j]}的形式是{str2d}，
// \begin{enumerate} 
// \item 如果{c==d}，则{f[i][j]=f[i-1][j-1]}； 
// \item 如果{c!=d}， 
//     \begin{enumerate} 
//         \item 如果将c替换成d，则{f[i][j]=f[i-1][j-1]+1}； 
//         \item 如果在c后面添加一个d，则{f[i][j]=f[i][j-1]+1}； 
//         \item 如果将c删除，则{f[i][j]=f[i-1][j]+1}； 
//     \end{enumerate}
// LeetCode, Edit Distance
// 二维动规，时间复杂度O(n*m)，空间复杂度O(n*m)
class Solution {
public:
    int minDistance(const string &word1, const string &word2) {
        const size_t n = word1.size();
        const size_t m = word2.size();
        // 长度为n的字符串，有n+1个隔板
        int f[n + 1][m + 1];
        for (size_t i = 0; i <= n; i++)
            f[i][0] = i;
        for (size_t j = 0; j <= m; j++)
            f[0][j] = j;

        for (size_t i = 1; i <= n; i++) {
            for (size_t j = 1; j <= m; j++) {
                if (word1[i - 1] == word2[j - 1])
                    f[i][j] = f[i - 1][j - 1];
                else {
                    int mn = min(f[i - 1][j], f[i][j - 1]);
                    f[i][j] = 1 + min(f[i - 1][j - 1], mn);
                }
            }
        }
        return f[n][m];
    }
};


// LeetCode, Edit Distance
// 二维动规+滚动数组
// 时间复杂度O(n*m)，空间复杂度O(n)
class Solution {
public:
    int minDistance(const string &word1, const string &word2) {
        if (word1.length() < word2.length())
            return minDistance(word2, word1);

        int f[word2.length() + 1];
        int upper_left = 0; // 额外用一个变量记录f[i-1][j-1]

        for (size_t i = 0; i <= word2.size(); ++i)
            f[i] = i;

        for (size_t i = 1; i <= word1.size(); ++i) {
            upper_left = f[0];
            f[0] = i;

            for (size_t j = 1; j <= word2.size(); ++j) {
                int upper = f[j];

                if (word1[i - 1] == word2[j - 1])
                    f[j] = upper_left;
                else
                    f[j] = 1 + min(upper_left, min(f[j], f[j - 1]));

                upper_left = upper;
            }
        }

        return f[word2.length()];
    }
};


//===================
class Solution {
int min3(int a, int b, int c)
{
    int tmp = a <= b? a:b;
    
    if (tmp <= c)
        return tmp;
    
    return c;
        
}

public:
    int minDistance(string word1, string word2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int size1 = word1.size();
        int size2 = word2.size();
        
        if (size1 == 0 && size2 == 0)
            return 0;
        else if (size1 == 0)
            return size2;
        else if (size2 == 0)
            return size1;
            
        int **table = (int **)malloc(sizeof(int*)*(size2+1));
        
        for (int i = 0; i <= size2; i++)
        {
            table[i] = (int *)malloc(sizeof(int)*(size1+1));
            memset(table[i], 0, size1+1);
        }
        
        table[0][0] = 0;
        for (int i = 1; i<=size2; i++)
            table[i][0] = i;   

        for (int j = 1; j<=size1; j++)
            table[0][j] = j;
            
        for (int i = 1; i<=size2; i++)
        {
            for(int j = 1; j<=size1; j++)
            {
                if (word1[j-1] == word2[i-1])
                {
                    table[i][j] = table[i-1][j-1];    
                }
                else
                {
                    table[i][j] = min3(table[i-1][j], table[i][j-1], table[i-1][j-1])+1;
                }
            }
        }
        
        int retVal = table[size2][size1];
     
        for (int i = 0; i < size2; i++)
        {
            free(table[i]);
        }
        free(table);
        
        return retVal;
    }
};

//
class Solution {
public:
    int minDistance(string word1, string word2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n1 = word1.size();
        int n2 = word2.size();
        vector<vector<int> > f(n1+1, vector<int>(n2+1, INT_MAX));
        //initialize
        for(int i = 0; i <= n1; ++i) f[i][0] = i;
        for(int j = 0; j <= n2; ++j) f[0][j] = j;
        //dp
        for(int i = 1; i <= n1; ++i)
        {
            for(int j = 1; j <= n2; ++j)
            {
                if(word1[i-1] == word2[j-1]) f[i][j] = f[i-1][j-1];
                int tmp = INT_MAX;
                tmp = min(tmp, f[i-1][j]);
                tmp = min(tmp, f[i][j-1]);
                tmp = min(tmp, f[i-1][j-1]);
                
                f[i][j] = min( f[i][j], tmp+1 );
            }
        }
        return f[n1][n2];
    }
};

//
class Solution {
public:
    int minDistance(string word1, string word2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > f(word1.size()+1, vector<int>(word2.size()+1));
        
        f[0][0] = 0;
        for(int i = 1; i <= word2.size(); i++)
            f[0][i] = i;
        
        for(int i = 1; i <= word1.size(); i++)
            f[i][0] = i;
            
        for(int i = 1; i <= word1.size(); i++)
            for(int j = 1; j <= word2.size(); j++)
            {
                f[i][j] = INT_MAX;
                if (word1[i-1] == word2[j-1]) 
                    f[i][j] = f[i-1][j-1];
                
                f[i][j] = min(f[i][j], f[i-1][j-1] + 1); //replace
                f[i][j] = min(f[i][j], min(f[i-1][j], f[i][j-1]) + 1); //delete or insert               
            }
            
        return f[word1.size()][word2.size()];
    }
};

//
//
// 利用动态规划的思路。dp[i][j]表示word1的前i个字母与word2的前j个字母的编辑距离。我们可以发现如下规律：
// 1）若word1[i+1]==word2[j+1] dp[i+1][j+1] = dp[i][j]；否则，dp[i+1][j+1] = dp[i][j] + 1。（利用替换原则）
// 2）dp[i+1][j+1]还可以取dp[i][j+1]与dp[i+1][j]中的较小值。（利用删除添加原则）
// 实际dp[i+1][j+1]应当取上述两种情况的较小值。
class Solution {
public:
    int minDistance(string word1, string word2) {
        int ** dp = new int*[word1.size() + 1];
        for(int i = 0; i < word1.size() + 1; i++){
            dp[i] = new int[word2.size() + 1];
        }
        
        for(int i = 0; i < word1.size() + 1; i++){
            dp[i][0] = i;
        }
        
        for(int i = 1; i < word2.size() + 1; i++){
            dp[0][i] = i;
        }
        
        for(int i = 0; i < word1.size(); i++){
            for(int j = 0; j < word2.size(); j++){
                if(word1[i] == word2[j]){
                    dp[i + 1][j + 1] = dp[i][j];
                }
                else{
                    dp[i + 1][j + 1] = dp[i][j] + 1;
                    
                    if(dp[i][j + 1] + 1 < dp[i + 1][j + 1]){
                        dp[i + 1][j + 1] = dp[i][j + 1] + 1;
                    }
                    
                    if(dp[i + 1][j] + 1 < dp[i + 1][j + 1]){
                        dp[i + 1][j + 1] = dp[i + 1][j] + 1;
                    }
                }
            }
        }
        
        return dp[word1.size()][word2.size()];
    }
};

//http://www.cnblogs.com/lihaozy/archive/2012/12/31/2840152.html
class Solution {
public:
    int minDistance(string word1, string word2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int row = word1.length() + 1;
        int col = word2.length() + 1;
        
        vector<vector<int> > f(row, vector<int>(col));

        for (int i = 0; i < row; i++)
            f[i][0] = i;

        for (int i = 0; i < col; i++)
            f[0][i] = i;

        for (int i = 1; i < row; i++)
            for (int j = 1; j < col; j++){
                if (word1[i-1] == word2[j-1])
                    f[i][j] = f[i-1][j-1];
                else
                    f[i][j] = f[i-1][j-1] + 1;
                f[i][j] = min(f[i][j], min(f[i-1][j]+1, f[i][j-1]+1));
            }

        return f[row-1][col-1];
    }
};