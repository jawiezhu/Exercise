// Description:
// Count the number of prime numbers less than a non-negative number, n.

class Solution {
public:
    int countPrimes(int n) {
        vector<bool> num(n-1,true);
        num[0]=false;
        int res=0;
        int limit=sqrt(n);

        for(int i=2;i<=limit;i++)
        {
            if(num[i-1])
            {
               for(int j=i*i;j<n;j+=i)
               {
                  num[j-1]=false;
               }
            }
        }

        for(int j=0;j<n-1;j++)
        {
            if(num[j])
               res++;
        }

        return res;
    }
};

//
// 第二个提示埃拉托斯特尼筛法Sieve of Eratosthenes中，这个算法的过程如下图所示，我们从2开始遍历到根号n，先找到第一个质数2，
// 然后将其所有的倍数全部标记出来，然后到下一个质数3，标记其所有倍数，一次类推，直到根号n，此时数组中未被标记的数字就是质数。
// 我们需要一个n-1长度的bool型数组来记录每个数字是否被标记，长度为n-1的原因是题目说是小于n的质数个数，并不包括n。
//  然后我们用两个for循环来实现埃拉托斯特尼筛法


//
// 首先，我试图在遍历的过程中保存之前所有的质数，然后对于对于一个自然数 N：
// 只需用小于 N 的素数去除就可以了。
// 而且，不必用从 2 到 N一1 的所有质数去除，只需用小于等于（根号N）的所有素数去除就可以了。
int countPrimes(int n) {
    int count = 0;
    vector<int> primes;  // 保存质数
    primes.push_back(3);
    primes.push_back(5);
    primes.push_back(7);
    for(int i=9; i<n; i=i+2)  // 只考虑奇数
    {
        bool flag = true;
        for(int j=0; j<primes.size()&&primes[j]<=pow(i,0.5); ++j)
            if(i%primes[j] == 0)
            {
                flag = false;
                break;
            }

        if(flag) {
            ++count;
            primes.push_back(i);
        }
    }
    return count+4;  // 加上前四个
}
//1500000超时

int countPrimes(int n) {
    bool *Del = new bool[n]; // 标记是否被划去
    Del[2] = false;

    for(int i=3; i<n; ++i)
        if(i%2 == 0)
            Del[i] = true;  // 2的倍数全部划去
        else
            Del[i] = false;

    for(int i=3; i<n; i+=2)
        if(!Del[i])  // 之后第一个未被划去
        {
            if(i*i>n)  break;  // 当前素数的平方大于n，跳出循环
            for(int j=2; i*j<n; ++j)
                Del[i*j] = true;
        }

    int count = 0;
    for(int i=2; i<n; ++i)
        if(!Del[i])
            ++count;

    delete [] Del;
    return count;
}



