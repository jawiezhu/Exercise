// Write a function to find the longest common prefix string amongst an array of strings.


class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==0) return "";

        string prefix=strs[0];

        for(int i=1;i<strs.size();i++)
        {
        	if(prefix.size()==0||strs[i].size()==0) return "";

        	
        	int len=0;
        	if(prefix.size()<strs[i].size())
        		len=prefix.size();
        	else
        		len=strs[i].size();

        	int j;
        	for(j=0;j<len;j++)
        	{
        		if(prefix[j]!=strs[i][j])
        			break;
        	}

        	prefix=prefix.substr(0,j);
        }

        return prefix;
    }
};


// 2个字符串的最长公共前缀，其长度肯定不会超过最短的字符串的长度，设最短的字符串长度为n，那么只要比较这2个字符串的前n个字符即可。
// 如此得出这2个字符串的最长公共前缀prefix后，再拿prefix作为新的字符串和数组中的下一个字符串比较，方法同上。
// 需要注意的是，如果数组中的某个字符串长度为0，或者求得的当前最长公共前缀的长度为0，就直接返回空字串。

//从位置0开始，对每一个位置比较所有字符串，直到遇到一个不匹配。
// LeetCode, Longest Common Prefix
// 纵向扫描，从位置0开始，对每一个位置比较所有字符串，直到遇到一个不匹配
// 时间复杂度O(n1+n2+...)
// @author 周倩 (http://weibo.com/zhouditty)
class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        if (strs.empty()) return "";

        for (int idx = 0; idx < strs[0].size(); ++idx) { // 纵向扫描
            for (int i = 1; i < strs.size(); ++i) {
                if (strs[i][idx] != strs[0][idx]) return strs[0].substr(0,idx);
            }
        }
        return strs[0];
    }
};


// LeetCode, Longest Common Prefix
// 横向扫描，每个字符串与第0个字符串，从左到右比较，直到遇到一个不匹配，
// 然后继续下一个字符串
// 时间复杂度O(n1+n2+...)
class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        if (strs.empty()) return "";

        int right_most = strs[0].size() - 1;
        for (size_t i = 1; i < strs.size(); i++)
            for (int j = 0; j <= right_most; j++)
                if (strs[i][j] != strs[0][j])  // 不会越界，请参考string::[]的文档
                    right_most = j - 1;

        return strs[0].substr(0, right_most + 1);
    }
};


//===================
string longestCommonPrefix(vector<string> &strs) {
     if(strs.empty()) {
         return "";
     }
 
     int minLen = 0;
     for(int i = 0; i < strs.size(); i++) {
         if(minLen < strs[i].size()) {
             minLen = strs[i].size();
         }
     }
 
     string result;
     int index = 0;
     bool same = true;
     while(index < minLen && same) {
         for(int i = 1; i < strs.size(); i++) {
             if(strs[i][index] != strs[i - 1][index]) {
                 same = false;
                 break;
             }
         }
         if(same) {
             result.push_back(strs[0][index]);
             index++;  
         }
     }
 
     return result;
 }

//==================
//  算法流程：
// 判断输入的字符串数量，小于2时候做出相应返回。
// 获取最短字符串的长度。
// 设定标记flag，控制跳出循环，与长度返回的长度len。
// 在最短字符串长度的范围内循环。
// 循环中每次遍历全部字符串len 位的字符。
// 遇到不同设置flag 跳出循环，如果全部都相同len+1 进入下次循环。
// 返回长度。
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        int nvec = strs.size();
        if(nvec<1) return "";
        if(nvec<2) return strs[0];
        int nmin = strs[0].length(),len=0;
        bool flag = true;
        for(int i =1;i<nvec;i++){
            if(nmin>strs[i].length())   nmin = strs[i].length();
        }
        while(len<nmin){
            for(int i=1;i<nvec&&flag;i++){
                if(strs[i][len]==strs[0][len])  continue;
                flag = false;
            }
            if(!flag)   break;
            len++;
        }
        return strs[0].substr(0,len);
    }
};

int main()
{
    vector<string> strs={"289","25324","22434","232","234"};
    Solution sol;
    cout<<sol.longestCommonPrefix(strs)<<endl;
    return 0;
}

//===================

string longestCommonPrefix(vector<string> &strs) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int row = strs.size();
		if(row < 1) return "";
		if(row == 1) return strs[0];
		int strlength = strs[0].length();
		for(int i = 1; i < row; ++i)
			if(strs[i].length() < strlength) strlength = strs[i].length();
		int count = 0;
		bool flag = true;
		for(int i=0; i< strlength && flag; ++i)
		{
			char commonchar = strs[0][count];
			int j = 0;
			for(; j < row; ++j)
				if(strs[j][count] != commonchar)
				    {flag = false; break;}
			if((j == row) && (flag = true))count++;
		}
		return strs[0].substr(0,count);		
    }

//================
// 解法一：
// 思路：设置一个位数记录器num，遍历所有字符串的第num位。如果都相同，则num++。
// 直到某字符串结束或者所有字符串的第num位不都相同，则返回[0~num-1]位，即最长公共前缀。
class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        if(strs.empty())
            return "";
        else if(strs.size() == 1)
            return strs[0];
        else
        {
            string ret = "";
            int num = 0;
            char c = strs[0][num];
            while(true)
            {
                for(vector<string>::size_type st = 0; st < strs.size(); st ++)
                {
                    if(num < strs[st].size() && strs[st][num] == c)
                    {//match
                        if(st == strs.size()-1)
                        {//end
                            ret += c;
                            num ++;
                            c = strs[0][num];
                        }
                    }
                    else
                        return ret;
                }
            }
        }
    }
    
};

//
class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        string ret = "";
        char c;
        int index = 0;
        if(strs.empty())
            return ret;
        while(true)
        {
            for(int i = 0; i < strs.size(); i ++)
            {
                if(i == 0)
                {
                    if(index < strs[0].size())
                        c = strs[0][index];
                    else
                        return ret;
                }
                // no else, 0 may equals to strs.size()-1
                if(i == strs.size()-1)
                {
                    if(index >= strs[i].size() || strs[i][index] != c)
                        return ret;
                    else
                    {
                        ret += c;
                        index ++;
                    }
                }
                if(i != 0 && i != strs.size()-1)
                {
                    if(index >= strs[i].size() || strs[i][index] != c)
                        return ret;
                }
            }
        }
        return ret;
    }
};

//模拟法
class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (strs.size() == 0)
            return "";
            
        string s = strs[0];
        
        for(int i = 1; i < strs.size(); i++)
        {
            int j = 0;
            
            int len = min(strs[i].size(), s.size());
            
            while(j < len)
            {
                if (strs[i][j] != s[j])
                    break;
                j++;
            }
            
            s.erase(j, s.size());
        }
        
        return s;
    }
};
