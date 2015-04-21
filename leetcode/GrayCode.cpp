// The gray code is a binary numeral system where two successive values differ in only one bit.

// Given a non-negative integer n representing the total number of bits in the code, print the sequence of gray code. A gray code sequence must begin with 0.

// For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:

// 00 - 0
// 01 - 1
// 11 - 3
// 10 - 2
// Note:
// For a given n, a gray code sequence is not uniquely defined.

// For example, [0,2,3,1] is also a valid gray code sequence according to the above definition.

// For now, the judge is able to judge based on one instance of gray code sequence. Sorry about that.

class Solution {
public:
  vector<int> grayCode(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> res;
		res.push_back(0);
		int highbit = 0;
		while(n--)
		{
			highbit = res.size();
			for(int i= res.size()-1; i >= 0; i--)
				res.push_back(highbit|res[i]);
		}
		return res;
    }
};

// 二进制码->格雷码（编码）：从最右边一位起，依次将每一位与左边一位异或（XOR），作为对应格雷码该位的值，最左边一位不变（相当于左边是0）；
// 格雷码->二进制码（解码）：从左边第二位起，将每位与左边一位解码后的值异或，作为该位解码后的值（最左边一位依然不变）。

// Gray Code 0 = 0, 下一项是toggle最右边的bit(LSB), 再下一项是toggle最右边值为 “1” bit的左边一个bit，
// 然后重复。直到最右边值为 “1” 的bit在最左边了，结束。
class Solution {  
public:  
    vector<int> grayCode(int n) {  
        // Start typing your C/C++ solution below  
        // DO NOT write int main() function  
        vector<int> result;  
        int nSize = 1 << n;  
        for (int i = 0; i < nSize; ++i)  
        {  
            result.push_back((i>>1)^i);  
        }  
        return result;  
    }  
}; 


// 数学解：
// 从第0个开始，第i个gray code为：(i>>1)^i
vector<int> grayCode(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> res;
    	int num = 1<<n;
        int i = 0;
		while(i<num)
			res.push_back((i>>1)^(i++));
		return res;
    }