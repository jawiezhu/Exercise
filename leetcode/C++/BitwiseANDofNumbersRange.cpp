// Given a range [m, n] where 0 <= m <= n <= 2147483647, return the bitwise AND of all numbers in this range, inclusive.

// For example, given the range [5, 7], you should return 4.


//TIME LIMIT EXCEEDED
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        
        int ret=0;
         ret=m;

        for(int i=m;i<=n;i++)
        {
        	ret=ret&i;
        }

        return ret;
    }
};



//
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        if(m==0) return 0;

        int p=0;
        while(m!=n)
        {
        	m=m>>1;
        	n=n>>1;
        	p++;
        }

        return m<<p;
    }
};


//
//1)For any given m and n, as long as m != n, we always get 0 at right-most bit when we do AND operation on these numbers. It is because two adjacent numbers always have different right-most bit. There always be a 0!
//like:  5: 0101
// 　　　 6: 0110
//result:   0100
//2)So, we keep doing right shift until m is equal to n. And we count the number of times of right shift(keep this number in "count").  
//3)We do left shift to m. Do it "count" times. 


// 又是一道考察位操作Bit Operation的题，相似的题目在LeetCode中还真不少，
// 比如Repeated DNA Sequences 求重复的DNA序列， Single Number 单独的数字,   Single Number II 单独的数字之二 ， Grey Code 格雷码，和 Reverse Bits 翻转位 等等，
// 那么这道题其实并不难，我们先从题目中给的例子来分析，[5, 7]里共有三个数字，分别写出它们的二进制为：
// 101　　110　　111
// 相与后的结果为100，仔细观察我们可以得出，最后的数是该数字范围内所有的数的左边共同1的部分，如果上面那个例子不太明显，我们再来看一个范围[26, 30]，它们的二进制如下：
// 11010　　11011　　11100　　11101　　11110
// 发现了规律后，我们只要写代码找到左边公共1的部分即可，
// 我们可以从建立一个32位都是1的mask，然后每次向左移一位，比较m和n是否相同，
// 不同再继续左移一位，直至相同，然后把m和mask相与就是最终结果，代码如下：
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int d = INT_MAX;
        while ((m & d) != (n & d)) {
            d <<= 1;
        }
        return m & d;
    }
};

//此题还有另一种解法，不需要用mask，直接平移m和n，每次向右移一位，直到m和n相等，记录下所有平移的次数i，然后再把m左移i位即为最终结果
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int i = 0;
        while (m != n) {
            m >>= 1;
            n >>= 1;
            ++i;
        }
        return (m << i);
    }
};

