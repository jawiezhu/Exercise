
// Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.

// If the last word does not exist, return 0.

// Note: A word is defined as a character sequence consists of non-space characters only.

// For example, 
// Given s = "Hello World",
// return 5.


class Solution {
public:
    int lengthOfLastWord(const char *s) {
        int n=strlen(s);
        int i=0;
        int cnt=0;
        //i=n;
        while(s[n-1]==' ')
            n--;
            
        for(i=n-1;i>=0;i--)
        {
            if(s[i]!=' ')
                cnt++;
            else
                break;
                
        }
        return cnt;
    }
    
};



// LeetCode, Length of Last Word
// 偷懒，用 STL
// 时间复杂度O(n)，空间复杂度O(1)
class Solution {
public:
    int lengthOfLastWord(const char *s) {
        const string str(s);
        auto first = find_if(str.rbegin(), str.rend(), ::isalpha);
        auto last = find_if_not(first, str.rend(), ::isalpha);
        return distance(first, last);
    }
};


// LeetCode, Length of Last Word
// 顺序扫描，记录每个 word 的长度
// 时间复杂度O(n)，空间复杂度O(1)
class Solution {
public:
    int lengthOfLastWord(const char *s) {
        int len = 0;
        while (*s) {
            if (*s++ != ' ')
                ++len;
            else if (*s && *s != ' ')
                len = 0;
        }
        return len;
    }
};


//注意s=" a  b  "这种情况，从后遍历单词，遇到空格退出
class Solution {
public:
    int lengthOfLastWord(const char *s) {
        int len=strlen(s);
        int sum=0;
        while(s[len-1]==' ') len--;
        for(int i=len-1;i>=0;i--)
        {
            if(s[i]!=' ')   sum++;
            else break;
        }
        return sum;
    }
};



class Solution {
public:
    int lengthOfLastWord(const char *s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(s == NULL) return 0;
        int ans = 0;
        while(*s != '\0')
        {
            if(*s != ' ')
            {
                int curLen = 0;
                while(*s != '\0' && *s != ' ') s++, curLen++;
                ans = curLen;
            }
            else s++;
        }
        
        return ans;
    }
};

class Solution {
public:
    int lengthOfLastWord(const char *s) {
        int len = 0;
        while(s[len] != '\0') len++;
        if(len == 0) return 0;
        
        int start = len - 1, end = len - 1;
        while(end >= 0 && s[end] == ' ') end--;
        if(end < 0) return 0;
        start = end - 1;
        while(start >= 0 && s[start] != ' ') start--;
        
        return end - start;
    }
};



class Solution {
public:
    int lengthOfLastWord(const char *s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (s == NULL)
            return 0;
            
        const char *start = s;
        int len = 0;
        while(*s != '\0')
        {
            if (*s == ' ')
            {
                int l = s - start;                
                if (l != 0)
                    len = l;
                start = s + 1;
                s++;
            }
            else
                s++;
        }
        
        int l = s - start;
        if (l != 0)
            len = l;
            
        return len;
    }
};

