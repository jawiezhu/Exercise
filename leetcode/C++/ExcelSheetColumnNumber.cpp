// Related to question Excel Sheet Column Title

// Given a column title as appear in an Excel sheet, return its corresponding column number.

// For example:

//     A -> 1
//     B -> 2
//     C -> 3
//     ...
//     Z -> 26
//     AA -> 27
//     AB -> 28 
class Solution {
public:
    int titleToNumber(string s) {
        int num=0;
        for(int i=0;i<s.length();i++)
            num=num+pow(26,i)*(s[s.length()-i-1]-64);
            
        return num;
    }
};