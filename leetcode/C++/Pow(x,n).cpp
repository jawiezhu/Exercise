// Implement pow(x, n).



class Solution {
public:
    double myPow(double x, int n) {
        double ret=1;
        while(n>0)
        {
        	ret=ret*x;
        	n--;
        }

        return ret;
    }
};


class Solution {
public:
    double myPow(double x, int n) {
       if(n==0) return 1.0;
       if(n<0) return 1.0/myPow(x,-n);
       return x*pow(x,n-1);
    }
};




class Solution {
public:
    double myPow(double x, int n) {
        if(n==0) return 1.0;
        if(n<0) return 1.0/myPow(x,-n);

        double half=myPow(x,n>>1);
        if(n%2==0)
        	return half*half;
        else
        	return half*half*x;
    }
};


//Runtime Error above.  
// 1.00000 -2147483648 Error


//用二分法，O(logn)。注意n < 0的处理
class Solution {
public:
    double power(double x, int n)
    {
        if (n == 0)
            return 1;
            
        double half = power(x, n / 2);
            
        if (n % 2 == 0)
            return half * half;
        else
            return half * half * x;
    }
    
    double myPow(double x, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (n < 0)
            return 1.0 / power(x, -n);
        else
            return power(x, n);       
    }
};


//最直观容易想到的方法就是用递归方法求n个x的乘积，注意考虑n的正负号，时间复杂度为O(n)
double pow(double x, int n)
{
	if(n==0)
		return 1.0;
	if(n<0)
		return 1.0/pow(x,-n);
	return x*pow(x,n-1);
}

//考虑到n个x相乘式子的对称关系，可以对上述方法进行改进，
//从而得到一种时间复杂度为O(logn)的方法，递归关系可以表示为pow(x,n) = pow(x,n/2)*pow(x,n-n/2)
double pow(double x, int n)
{
	if(n==0)
		return 1.0;
	if(n<0)
		return 1.0/pow(x,-n);
	double half = pow(x,n>>1);
	if(n%2==0)
		return half*half;
	else
		return half*half*x;
}

// Consider the binary representation of n.
//  For example, if it is "10001011", then x^n = x^(1+2+8+128) = x^1 * x^2 * x^8 * x^128. 
//  Thus, we don't want to loop n times to calculate x^n. To speed up, we loop through each bit, 
//  if the i-th bit is 1, 
//  then we add x^(1 << i) to the result. Since (1 << i) is a power of 2,
//   x^(1<<(i+1)) = square(x^(1<<i)). The loop executes for a maximum of log(n) times.
// 该方法通过扫描n的二进制表示形式里不同位置上的1，来计算x的幂次
double my_pow(double x, int n)
{
	if(n==0)
        	return 1.0;
	if(n<0)
		return 1.0 / pow(x,-n);
	double ans = 1.0 ;
	for(; n>0; x *= x, n>>=1)
	{
		if(n&1>0)
			ans *= x;
	}
	return ans;
}

// 为了正确计算x的n次幂，还需要考虑到以下一些情况：

// 1) x取值为0时，0的正数次幂是1，而负数次幂是没有意义的；判断x是否等于0不能直接用“==”。

// 2) 对于n取值INT_MIN时，-n并不是INT_MAX，这时需要格外小心。

// 3) 尽量使用移位运算来代替除法运算，加快算法执行的速度。

class Solution {
public:
    double pow(double x, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(n<0)
		{
			if(n==INT_MIN)
				return 1.0 / (pow(x,INT_MAX)*x);
			else
				return 1.0 / pow(x,-n);
		}
        if(n==0)
            return 1.0;
		double ans = 1.0 ;
		for(;n>0; x *= x, n>>=1)
		{
			if(n&1>0)
				ans *= x;
		}
		return ans;
    }
};


double pow(double x, int n) 
{
	long long index = n;
	double result = 0;
	int flag = 1;
	if (x<0 && n%2!=0)
		x = -x, flag = -1;
	if (index < 0)
		result = powI(x, -index);
	else
		result = powI(x, index);

	if (index < 0) return 1/result*flag;
	else return result*flag;
}

double powI(double x, long long n) // x>0, n>=0
{
	if (n == 0) return 1;
	else if (n == 1) return x;
	else if (n == 2) return x*x;
	else
	{
		if (n%2==0)
		{
			double mid = powI(x, n/2);
			return mid*mid;
		}
		else {
			double mid = powI(x, (n-1)/2);
			return mid*mid*x;
		}
	}
}

double pow(double x, int n) 
{
	if(n==0) return 1;
	if(n==1) return x;
	int exp = n<0?-n:n;
	double result= exp%2==0?pow(x*x,exp/2):pow(x*x,exp/2)*x;
	return n<0?1/result:result;
}

// 根据n进行循环并计算乘积，但是这样的时间开销比较大。最好能够再减少循环次数，例如n4可以表示成（n2）2。
// 将n表示成二进制的格式便能够轻松知道如何减少循环次数。
class Solution {
public:
    double pow(double x, int n) {
        if(n == 0){
            return 1;
        }
        else if(n < 0){
            x = 1 / x;
            n = -1 * n;
        }
        
        double result = 1;
        while(n > 0){
            if(n % 2 == 1){
                result *= x;
            }
            n /= 2;
            x *= x;
        }
        
        return result;
    }
};


//LeetCode, Pow(x, n)
// 时间复杂度 O(logn),空间复杂度 O(1)
class Solution {
public:
      double pow(double x, int n) {
          if (n < 0) return 1.0 / power(x, -n);
          else return power(x, n);
} private:
      double power(double x, int n) {
          if (n == 0) return 1;
          double v = power(x, n / 2);
          if (n % 2 == 0) return v * v;
          else return v * v * x;
} };