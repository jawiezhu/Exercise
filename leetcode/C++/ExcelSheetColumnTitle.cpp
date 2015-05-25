// Given a positive integer, return its corresponding column title as appear in an Excel sheet.

// For example:

//     1 -> A
//     2 -> B
//     3 -> C
//     ...
//     26 -> Z
//     27 -> AA
//     28 -> AB 

//一个10进制数转换为一个26进制的数
class Solution {
public:
    string convertToTitle(int n) {
        if(n<1) return "";
        else
        {
        	string ret="";
        	while(n)
        	{
        		n--;
        		char c=n%26+'A';
        		ret=c+ret;
        		n/=26;
        	}
  			return ret;
        }
    }
};