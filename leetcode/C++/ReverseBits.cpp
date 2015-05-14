// Reverse bits of a given 32 bits unsigned integer.

// For example, given input 43261596 (represented in binary as 00000010100101000001111010011100), return 964176192 (represented in binary as 00111001011110000010100101000000).

// Follow up:
// If this function is called many times, how would you optimize it?

// Related problem: Reverse Integer
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
       	uint32_t bit[32]={0};
       	uint32_t ret=0;

       	int mid=1;

       	for(int i=0;i<32;i++)
       	{
       		bit[i]=(n>>i)&1;
       	}

       	for(int j=31;j>=0;j--)
       	{
       		ret=ret+bit[j]*mid;
       		mid=mid*2;
       	}

       	return ret;

    }
};


//取出每一位置的值后直接左移31~0位，然后相加
uint32_t reverseBits(uint32_t n){
   int i,bin=0;
     for (i = 0; i < 32; i++) 
     bin+=(n >> i & 1)<<(31-i);
    return bin;
}

uint32_t reverseBits(uint32_t n) {
int i;
uint32_t res = 0;
for(i = 0; i < 32; i++) {
    res = (res << 1) ^ (n & 1);
    n >>= 1;
}
return res;
}

// 1：“按位与”运算符（&）用法是如果两个相应的二进制位都为1，则该位的结果值为1否则为0。0&0=0，1&0=0,1&1=1
// 2：“按位或”运算符（|）用法是如果两个相应的二进制位有一个为1，则该位的结果值为1否则为0。0&0=0，1&0=0,1&1=10，1&0=1,1&1=1
// 3：“异或”运算符（^）用法是如果两个相应的二进制位为同号，则该位的结果值为1否则为0。0&0=0，1&0=1,1&1=0


//遍历输入数的位，输出数反向添加，循环时候需要注意先移位后修改，反过来会错的。
#include<iostream>
using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t m=0;
        for(int i=0;i<32;i++){
            m<<=1;
            m = m|(n & 1);
            n>>=1;
        }
        return m;
    }
};

int main()
{
    uint32_t n = 1;
    Solution sol;
    cout<<sol.reverseBits(n)<<endl;
    return 0;
}


class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0;
        for (int i = 0; i < 32; ++i) {
            res |= (((n >> i) & 1) << (31 - i));
        }
        return res;
   }
};


unsigned int reverse_bits(unsigned int value)
{
    unsigned int answer;
    unsigned int i;
    
    answer = 0;
    
    /*把一个unsigned int 数字1一直左移，直到它变成全0的时候，也就得到了该机器内unsigned int的长度*/
    for (i = 1; i != 0; i <<= 1)
    {
        answer <<= 1;
        if (value & 1) { answer |= 1; }
        value >>= 1;
    }
    
    return answer;
}

