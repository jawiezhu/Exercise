// Given an integer n, return the number of trailing zeroes in n!.

// Note: Your solution should be in logarithmic time complexity.


// 只有2和5相乘才会出现0，其中整十也可以看做是2和5相乘的结果，
// 所以，可以在n之前看看有多少个2以及多少个5就行了，又发现2的数量一定多于5的个数，
// 于是我们只看n前面有多少个5就行了，于是n/5就得到了5的个数，还有一点要注意的就是25这种，5和5相乘的结果，
// 所以，还要看n/5里面有多少个5，也就相当于看n里面有多少个25，还有125，625.。。

class Solution {
public:
    int trailingZeroes(int n) {
        int res=0;
        while(n)
        {
        	res+=n/5;
        	n/=5;
        }

        return res;
    }
};


// 对n!做质因数分解n!=2^x*3^y*5^z*...

// 显然0的个数等于min(x,z)，并且min(x,z)==z

// 证明：

// 对于阶乘而言，也就是1*2*3*...*n
// [n/k]代表1~n中能被k整除的个数
// 那么很显然
// [n/2] > [n/5] (左边是逢2增1，右边是逢5增1)
// [n/2^2] > [n/5^2](左边是逢4增1，右边是逢25增1)
// ……
// [n/2^p] > [n/5^p](左边是逢2^p增1，右边是逢5^p增1)
// 随着幂次p的上升，出现2^p的概率会远大于出现5^p的概率。
// 因此左边的加和一定大于右边的加和，也就是n!质因数分解中，2的次幂一定大于5的次幂

//从1到n中提取所有的5
class Solution {
public:
    int trailingZeroes(int n) {
        int ret = 0;
        for(int i = 1; i <= n; i ++)
        {
            int tmp = i;
            while(tmp%5 == 0)
            {
                ret ++;
                tmp /= 5;
            }
        }
        return ret;
    }
};

// 由上述分析可以看出，起作用的只有被5整除的那些数。能不能只对这些数进行计数呢？

// 存在这样的规律：[n/k]代表1~n中能被k整除的个数。


