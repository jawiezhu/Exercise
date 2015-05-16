// The count-and-say sequence is the sequence of integers beginning as follows:
// 1, 11, 21, 1211, 111221, ...

// 1 is read off as "one 1" or 11.
// 11 is read off as "two 1s" or 21.
// 21 is read off as "one 2, then one 1" or 1211.
// Given an integer n, generate the n^th sequence.

// Note: The sequence of integers will be represented as a string.

class Solution {
public:
	string count(const string &say)
	{
		stringstream ss;
		int count=0;
		char last=say[0];

		for(size_t i=0;i<=say.size();++i)
		{
			if(say[i]==last)
			{
				++count;
			}else{
				ss<<count<<last;
				count=1;
				last=say[i];
			}
		}

		return ss.str();
	}



    string countAndSay(int n) {
        if(n==0) return string();

        string say="1";

        for(int i=1;i<n;i++)
        {
        	say=count(say);
        }

        return say;
    }
};


// 题意是n=1时输出字符串1；n=2时，数上次字符串中的数值个数，
// 因为上次字符串有1个1，所以输出11；n=3时，由于上次字符是11，有2个1，所以输出21；
// n=4时，由于上次字符串是21，有1个2和1个1，所以输出1211。依次类推，写个countAndSay(n)函数返回字符串。


// LeetCode, Count and Say
// @author 连城 (http://weibo.com/lianchengzju)
// 时间复杂度O(n^2)，空间复杂度O(n)
class Solution {
public:
    string countAndSay(int n) {
        string s("1");

        while (--n)
            s = getNext(s);

        return s;
    }

    string getNext(const string &s) {
        stringstream ss;

        for (auto i = s.begin(); i != s.end(); ) {
            auto j = find_if(i, s.end(), bind1st(not_equal_to<char>(), *i));
            ss << distance(i, j) << *i;
            i = j;
        }

        return ss.str();
    }
};


//==============================
string toString(int n) {
        string str;
        while(true){
            str.insert(str.begin(), (n % 10) + 48);
            n = n / 10;
            if(n == 0)
                break;
        }
        return str;
    }
    
    string countAndSay(int n) {
        string seq;
        seq.push_back('1');
        for(int i = 2; i <= n; i ++) {
            string tmp;
            char current_char = seq[0];
            int count = 1;
            for(int j = 1; j < seq.size(); j ++) {
                if(seq[j] == current_char){
                    count ++;
                }else{
                    tmp += toString(count);
                    tmp += current_char; 
                    current_char = seq[j];
                    count = 1;
                }
            }
            tmp += toString(count);
            tmp += current_char;
            
            seq = tmp;
        }
        return seq;
    }


//=================

// public class Solution {
//     String countAndSayForOneString(String input) {
//         char tmp = input.charAt(0);
//         int  num = 1;
//         StringBuffer newString = new StringBuffer("");
//         for(int k=1;k<input.length();k++) {
//             if(input.charAt(k)==tmp) {
//         		num++;
//         		continue;
//         	}
//         	newString.append(Integer.toString(num) + tmp);
//         	tmp = input.charAt(k);
//         	num = 1;
//         }
//         newString.append(Integer.toString(num) + tmp);
//         return newString.toString();
//     }
    
//     public String countAndSay(int n) {
//         String result = "1";
// 		int i = 1;
// 		while(i<n) {
//         	result = countAndSayForOneString(result);
//     		i++;
//         }
// 		return result;
//     }
// }

//==================

class Solution {
public:
    string revolution(string s)
	{
		string ret;
		char pre =s[0];
		int count = 1;
		for(int i = 1; i < s.size(); i ++)
		{
			if(s[i]==pre)
			{
				count ++;
			}else{
				
				char tmp =  count+'0';
				ret = ret + tmp + pre;
				pre = s[i];
				count = 1;
			}
		}
		char tmp =  count+'0';
		ret = ret + tmp + pre;
		return   ret;
	}
    string countAndSay(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		string ret = "1";
		int j = 1;
		while( j< n){
			ret=revolution(ret);
			j++;
		}
		return ret;
    }
};



