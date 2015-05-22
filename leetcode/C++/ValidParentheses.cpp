// Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

// The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.

//遇到左边符号进栈，右边符号就将栈顶出栈，若和当前遍历的符号相对应则继续遍历下一个符号，若不对应返回false
class Solution {
public:
    bool isValid(string s) {
		stack<char> stk;
		char c;

		for(int i=0;i<s.size();i++)
		{
			if(s[i]=='('||s[i]=='['||s[i]=='{')
				stk.push(s[i]);
			else if(stk.empty())
				return false;
			else if(s[i]==')')
			{
				c=stk.top();
				if(c=='(')
					stk.pop();
				else
					return false;
			}
			else if(s[i]==']')
			{
				c=stk.top();
				if(c=='[')
					stk.pop();
				else
					return false;
			}
			else if(s[i]=='}')
			{
				c=stk.top();
				if(c=='{')
					stk.pop();
				else
					return false;
			}
		}

		if(stk.empty()==false) return false;

		return true;        
    }
};


//这一题是典型的使用压栈的方式解决的问题，题目中还有一种valid情况没有说明，需要我们自己考虑的，就是"({[]})"这种层层嵌套但
// 可以完全匹配的，也是valid的一种。解题思路是这样的：我们对字符串S中的每一个字符C，如果C不是右括号，就压入栈stack中。
// 如果C是右括号，判断stack是不是空的，空则说明没有左括号，直接返回not valid，非空就取出栈顶的字符pre来对比，如果是匹配
// 的，就弹出栈顶的字符，继续取S中的下一个字符；如果不匹配，说明不是valid的，直接返回。当我们遍历了一次字符串S后，注意
// 这里还有一种情况，就是stack中还有残留的字符没有得到匹配，即此时stack不是空的，这时说明S不是valid的，因为只要valid，一
// 定全都可以得到匹配使左括号弹出。
class Solution {
public:
    bool isValid(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        stack<char> st;
        
        for(int i = 0; i < s.size(); i++)
            if (s[i] == ')' || s[i] == ']' || s[i] == '}')
            {
                if (st.empty())
                    return false;
                else
                {
                    char c = st.top();
                    st.pop();
                    if ((c == '(' && s[i] != ')') || (c == '[' && s[i] != ']') || (c == '{' && s[i] != '}'))
                        return false;
                }
            }
            else
                st.push(s[i]);
                
        return st.empty();
    }
};


// LeetCode, Valid Parentheses
// 时间复杂度O(n)，空间复杂度O(n)
class Solution {
public:
    bool isValid (string const& s) {
        string left = "([{";
        string right = ")]}";
        stack<char> stk;

        for (auto c : s) {
            if (left.find(c) != string::npos) {
                stk.push (c);
            } else {
                if (stk.empty () || stk.top () != left[right.find (c)])
                    return false;
                else
                    stk.pop ();
            }
        }
        return stk.empty();
    }
};


