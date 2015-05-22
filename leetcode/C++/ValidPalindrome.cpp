// Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

// For example,
// "A man, a plan, a canal: Panama" is a palindrome.
// "race a car" is not a palindrome.

// Note:
// Have you consider that the string might be empty? This is a good question to ask during an interview.

// For the purpose of this problem, we define empty string as valid palindrome.

class Solution {
public:
    bool isPalindrome(string s) {
        int len=s.size();
        int start=0;
        int end=len-1;

        while(start<=end)
        {
        	while(start<=end&&!isalnum(s[start]))
        		start++;
        	while(start<=end&&!isalnum(s[end]))
        		end--;

        	if(start>end) break;

        	if(isdigit(s[start])&&s[start]!=s[end]) return false;

        	if(tolower(s[start])!=tolower(s[end])) return false;

        	start++;
        	end--;
        }

        return true;

    }
};

//=====================================
bool isAlphanumberic(char a) {
        if(a >= 48 && a <= 57 ||
          (a >= 65 && a <= 90) ||
          (a >= 97 && a <= 122))
            return true;
        return false;
    }
    bool isPalindrome(string s) {
        if(s.size() == 0 )
            return true;
        int start = 0;
        int end = s.size() - 1;
        while(start < end) {
            if(isAlphanumberic(s[start]) && isAlphanumberic(s[end]) ){
                if(s[start] >= 97)
                    s[start] -= 32;
                if(s[end] >= 97)
                    s[end] -= 32;
                if(s[start] != s[end]) {
                    return false;
                }else {
                    start ++;
                    end --;
                }
            }else if(!isAlphanumberic(s[start])){
                start ++;
            }else if(!isAlphanumberic(s[end])) {
                end --;
            }
        }
        return true;
    }

//===========================

// Leet Code, Valid Palindrome
// 时间复杂度O(n)，空间复杂度O(1)
class Solution {
public:
    bool isPalindrome(string s) {
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        auto left = s.begin(), right = prev(s.end());
        while (left < right) {
            if (!::isalnum(*left))  ++left;
            else if (!::isalnum(*right)) --right;
            else if (*left != *right) return false;
            else{ left++, right--; }
        }
        return true;
    }
};




//============
class Solution {
public:
    bool isPalindrome(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int i=0,j=s.length()-1;
        bool flag=true;
        while(i<j){
            if(!((s[i]>='A'&&s[i]<='Z')||(s[i]>='a'&&s[i]<='z')||(s[i]>='0'&&s[i]<='9'))){
                i++;
                continue;
            }
            if(!((s[j]>='A'&&s[j]<='Z')||(s[j]>='a'&&s[j]<='z')||(s[j]>='0'&&s[j]<='9'))){
                j--;
                continue;
            }
            if(s[i]>='A'&&s[i]<='Z')
                s[i]=s[i]+'a'-'A';
            if(s[j]>='A'&&s[j]<='Z')
                s[j]=s[j]+'a'-'A';
            
            if(s[i]!=s[j]){
                flag=false;
                break;
            }
            else{
                i++;
                j--;
            }
        }
        return flag;
    }
};

// //===========
// 验证一个字符串是否是回文字符串。首先看看wiki上对于回文的解释：回文，亦称回环，是正读反读都能读通的句子，
// 亦有将文字排列成圆圈者，Famous examples include "Amore, Roma", "A man, a plan, a canal: Panama" and "No 'x' in 'Nixon'"。 
// 判读一个字符串是否是回文，一种方法可以将字符串倒置然后和原字符串进行比较。
// 这里采用一种类似字符串翻转的方法，通过从前后两个方向来比较判断是否是回文。本题中的有效字符是字母和数字，并且忽略字母大小写。 
class Solution {
public:
  bool isPalindrome(string s) {
    int n = s.size();
    int i=0, j=n-1;
    while(i<j){
      if( !isalpha(s[i]) ) {
        ++i;
        continue;
      }
      if( !isalpha(s[j]) ) {
        --j;
        continue;
      }
      if(s[i] != s[j]) return false;
      ++i,--j;
    }
    return true;
  }
  //判断是否是字母数字，如果是大写字母则将其转化为小写字母
  bool isalpha(char &c){
    if((c>='A'&&c<='Z')){
      c = c-'A'+'a';
      return true;
    }
    return (c>='a'&&c<='z') || (c>='0'&&c<='9');
  }
};

//==================
class Solution {
public:
    bool isPalindrome(string s) {
        int strLen = s.size();
        int pos_h = 0;
        int pos_t = 0;
        char *copy = new char[strLen];
        int num = 0;
        for(int i=0;i<strLen;i++)
        {
            if(s[i] >= 65 && s[i]  <= 90 || s[i] >= 48 && s[i] <= 57)
              {
                  *(copy+num) = s[i];
                  num++;
              }
              else if(s[i] >= 97 && s[i]  <= 122)
              {
                  *(copy+num) = s[i] - 32;
                  num++;
              }
        }
       if(num == 0 || num == 1)
            return true;
        pos_h = 0;
        pos_t = num - 1;
        for(int i=0;i<num/2;i++)
            {
               if(copy[pos_h] != copy[pos_t])
                    break;
               pos_h++;;
               pos_t--;
            }
            if(pos_h < pos_t )
                return false;
            else
                return true;
    }
};

//
// 判断回文，只是遇到非字母数字要跳过，并且字母大小写不敏感。

// 常用的ASCII还是应该记住：
// A   65
// a   97
// 0   48
class Solution {
public:
	bool isPalindrome(string s) {
		if (s.length() == 0)
			return true;
		int i = 0, j = s.length() - 1;
		while (i<j)
		{
			if (!((s[i] >= '0' && s[i] <= '9') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')))
			{
				++i;
				continue;
			}
			
			if (!((s[j] >= '0' && s[j] <= '9') || (s[j] >= 'a' && s[j] <= 'z') || (s[j] >= 'A' && s[j] <= 'Z')))
			{
				--j;
				continue;
			}
	
			if (!(s[i] == s[j] || abs(s[i] - s[j]) == 32))
				return false;
			++i;
			--j;
		}
		return true;
	}
};
//==========
// 左右分别往中间扫描，如果不同则返回false，如果两端碰面了则返回true
// 代码里写了很多注释，我认为这类题难点在于循环的判断条件以及跳出条件
// 因此对于每一个循环都需要明确它的进入条件以及跳出条件。
class Solution {
public:
    bool alphanumeric(char c)
    {
        if((c >= 'a' && c <= 'z') ||
           (c >= 'A' && c <= 'Z') ||
           (c >= '0' && c <= '9'))
            return true;
        else
            return false;
    }
    bool isPalindrome(string s) {
        if(s == "")
            return true;
        int i = 0;
        int j = s.size()-1;
        while(i < j)
        {
            while(!alphanumeric(s[i]))
                i ++;
            while(!alphanumeric(s[j]))
                j --;
            if(i < j && tolower(s[i]) != tolower(s[j]))
                return false;
            i ++;
            j --;
        }
        return true;
    }
};

