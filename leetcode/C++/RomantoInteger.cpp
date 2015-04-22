// Roman to Integer
// Given a roman numeral, convert it to an integer.

// Input is guaranteed to be within the range from 1 to 3999.

class Solution {
public:
    int romanToInt(string s) {
        
        int result=0;
        map<char,int> roman;
        roman['I']=1;
        roman['V']=5;
        roman['X']=10;
        roman['L']=50;
        roman['C']=100;
        roman['D']=500;
        roman['M']=1000;

        for(int i=s.length()-1;i>=0;i--)
        {
        	if(i==s.length()-1)
        	{
        		result=roman[s[i]];
        		continue;
        	}
        	if(roman[s[i]]>=roman[s[i+1]])
        		result+=roman[s[i]];
        	else
        		result-=roman[s[i]];
        }

        return result;
    }
};


// class Solution {
// public:
//     int romanToInt(string s) {
//         int ret = toNumber(s[0]);
//         for (int i = 1; i < s.length(); i++) {
//             if (toNumber(s[i - 1]) < toNumber(s[i])) {
//                 ret += toNumber(s[i]) - 2 * toNumber(s[i - 1]);
//             } else {
//                 ret += toNumber(s[i]);
//             }
//         }
//         return ret;
//     }
    
//     int toNumber(char ch) {
//         switch (ch) {
//             case 'I': return 1;
//             case 'V': return 5;
//             case 'X': return 10;
//             case 'L': return 50;
//             case 'C': return 100;
//             case 'D': return 500;
//             case 'M': return 1000;
//         }
//         return 0;
//     }
// };