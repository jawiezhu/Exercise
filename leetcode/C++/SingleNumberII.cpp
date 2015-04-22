// Given an array of integers, every element appears three times except for one. Find that single one.

// Note:
// Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

class Solution {
public:
    int singleNumber(int A[], int n) {
        if(n==0) return NULL;
        int bitnum[32]={0};
        int res=0;
        for(int i=0;i<32;i++)
        {
            for(int j=0;j<n;j++)
            {
                bitnum[i]+=(A[j]>>i)&1;
            }
            res|=(bitnum[i]%3)<<i;
        }
        
        return res;
    }
};


class Solution {
public:
    int singleNumber(int A[], int n) {
        int one,two,three;
        one=two=three=0;
        for(int i=0;i<n;i++)
        {//一定是出现3次，2次，1次这样的顺序，如果反过来的话，先更新了one的话，会影响到two和three的
            three =  two & A[i];//已经出现了两次，还出现了一次
            two = two | one & A[i];//出现了1次又出现了1次，在加上以前已经出现了2次的，为新的出现了2次的
            one = one | A[i];//出现了1次
            //将出现3次的其出现1次2次全部抹去
            one = one & ~three;
            two = two & ~three;
        }
         return one;
    }
};


int singleNumber(int A[], int n) {
    int ones = 0, twos = 0, threes = 0;
    for (int i = 0; i < n; i++) {
        twos |= ones & A[i];
        ones ^= A[i];// 异或3次 和 异或 1次的结果是一样的
       //对于ones 和 twos 把出现了3次的位置设置为0 （取反之后1的位置为0）
        threes = ones & twos;
        ones &= ~threes;
        twos &= ~threes;
    }
    return ones;
}


int singleNumber(int A[], int n) {
    int count[32] = {0};
    int result = 0;
    for (int i = 0; i < 32; i++) {
        for (int j = 0; j < n; j++) {
            if ((A[j] >> i) & 1) {
                count[i]++;
            }
        }
        result |= ((count[i] % 3) << i);
    }
    return result;
}