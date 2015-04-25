// Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

// For example, given n = 3, a solution set is:

// "((()))", "(()())", "(())()", "()(())", "()()()"
//对于第k个元素，考虑以下两种情况：

// 前k - 1个元素中'('出现次数小于n，第k个元素可以是'('。
// 前k - 1个元素中')'出现的次数小于'('，第k个元素可以是')'。

//递归求解括号数，括号总数可用卡特兰数表示，1/n*C(2n,n)。
class Solution {
public:
    void unguarded_generate(vector<string> &result,string curr,int m,int n)
    {
        if (m==0&&n==0)
        {
            result.push_back(curr);
        }
        else
        {
            if(m!=0)
            {
                unguarded_generate(result,curr+"(",m-1,n);
            }
        
            if(m<n&&n!=0)
            {
                unguarded_generate(result,curr+")",m,n-1);
            }
        }
    }
 
    vector<string> generateParenthesis(int n) 
    {
        vector<string> ret;
        if(n>0)
        {
            unguarded_generate(ret,string(),n,n);
        }
        return ret;
    }
};



//用二叉树形象的表示这种关系。然后再把二叉树转化为代码的形式。因为二叉树的定义就是递归定义的，因此本题很明显应该使用递归的形式。
//结果，其中左分支都是添加左括号，又分支都是添加右括号。
// 在什么情况下添加左括号呢？很明显，最多能添加n个左括号，在递归调用的时候，在能传递到最底层的共用字符串中先添加"("，然后left-1，递归调用就可以。
// 那什么时候添加右括号呢？当左括号个数大于右括号的个数时添加右括号。
// 那我们是先添加右括号还是先添加左括号呢？对于这个问题，认真想想其实是无所谓的，只会影响在vector中最后字符串的顺序而已。


//
// 1 ()
// 2 ()(),(())
// 3 ()()(), (())(), (()()), ()(()), ((()))

// 规律是这样的 ，假设我们已经产生了n-1对括号的所有组合，那么在这个基础上我们可以产生所有的n对括号的组合，
// 我们把一个(放在每个n-1对括号组合的开头，然后在每个每一个括号配好对的位置插入一个)。这样我们就产生了一个n对括号的组合。
vector<string> generateParenthesis(int n) {
       vector<string> result;
       vector<string> temp;
       int count = 0;
       string newComb;
       result.push_back("()");
   
       if(n == 1) {
           return result;
       }
       else {
           for(int k = 1; k < n; k++) {
               for(int i = 0; i < result.size(); i++) {
                   count = 0;
                   newComb = result[i];
                   newComb.insert(newComb.begin(), ')');
                   newComb.insert(newComb.begin(), '(');
                   temp.push_back(newComb);
   
                   for(int j = 0; j < result[0].size(); j++) {
                       if(result[i][j] == '(') {
                           count++;
                       }
                       else {
                           count--;
                       }
                       if(!count) {
                           newComb = result[i];
                           newComb.insert(newComb.begin() + j, ')');
                           newComb.insert(newComb.begin(), '(');
                           temp.push_back(newComb);
                       }
                   }
               }
               result = temp;
               temp.clear();
           }
   
       }
       return result;
   }


//该问题解的个数就是卡特兰数，但是现在不是求个数，而是要将所有合法的括号排列打印出来。
// 该问题和《编程之美》的买票找零问题一样，通过买票找零问题我们可以知道，
// 针对一个长度为2n的合法排列，第1到2n个位置都满足如下规则：左括号的个数大于等于右括号的个数。
// 所以，我们就可以按照这个规则去打印括号：
// 假设在位置k我们还剩余left个左括号和right个右括号，如果left>0，则我们可以直接打印左括号，而不违背规则。
// 能否打印右括号，我们还必须验证left和right的值是否满足规则，
// 如果left>=right，则我们不能打印右括号，因为打印会违背合法排列的规则，否则可以打印右括号。
// 如果left和right均为零，则说明我们已经完成一个合法排列，可以将其打印出来。
// 通过深搜，我们可以很快地解决问题，针对n=2，用二叉树表示。

void generate(int leftNum,int rightNum,string s,vector<string> &result)
    {
        if(leftNum==0&&rightNum==0)
        {
            result.push_back(s);
        }
        if(leftNum>0)
        {
            generate(leftNum-1,rightNum,s+'(',result);
        }
        if(rightNum>0&&leftNum<rightNum)
        {
            generate(leftNum,rightNum-1,s+')',result);
        }
}

// 数组的入栈出栈顺序问题：给定一个长度为n的不重复数组，求所有可能的入栈出栈顺序。
// 该问题解的个数也是卡特兰数，根据上面的思路，我们也可以写出一个类似的代码：
void inoutstack(int in,int out,deque<int> &q,stack<int> &s,deque<int> seq,vector<deque<int>> &result)
    {
        if(!in&&!out)
        {
            result.push_back(q);
            return;
        }

        if(in>0)
        {
            s.push(seq.front());
            seq.pop_front();
            inoutstack(in-1,out,q,s,seq,result);
            seq.push_front(s.top());
            s.pop();
        }

        if(out>0&&in<out)
        {
            q.push_back(s.top());
            s.pop();
            inoutstack(in,out-1,q,s,seq,result);
            s.push(q.back());
            q.pop_back();
        }
    }