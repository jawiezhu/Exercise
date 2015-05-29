// Implement int sqrt(int x).

// Compute and return the square root of x.
class Solution {
public:
    int mySqrt(int x) {
        unsigned long long begin=0;
        unsigned long long end=(x+1)/2;
        unsigned long long mid;
        unsigned long long tmp;

        while(begin<end)
        {
        	mid=begin+(end-begin)/2;
        	tmp=mid*mid;

        	if(tmp==x) return mid;
        	else if(tmp<x) begin=mid+1;
        	else end=mid-1;
        }

        tmp=end*end;

        if(tmp>x)
        	return end-1;
        else
        	return end;
    }
};


//
// 计算x2 = n的解，令f(x)=x2-n，相当于求解f(x)=0的解，如左图所示。
//    首先取x0，如果x0不是解，做一个经过(x0,f(x0))这个点的切线，与x轴的交点为x1。
//    同样的道理，如果x1不是解，做一个经过(x1,f(x1))这个点的切线，与x轴的交点为x2。
//    以此类推。
//    以这样的方式得到的xi会无限趋近于f(x)=0的解。
//    判断xi是否是f(x)=0的解有两种方法：
//    一是直接计算f(xi)的值判断是否为0，二是判断前后两个解xi和xi-1是否无限接近。
// 经过(xi, f(xi))这个点的切线方程为f(x) = f(xi) + f’(xi)(x - xi)，其中f'(x)为f(x)的导数，本题中为2x。令切线方程等于0，即可求出xi+1=xi - f(xi) / f'(xi)。
// 继续化简，xi+1=xi - (xi2 - n) / (2xi) = xi - xi / 2 + n / (2xi) = xi / 2 + n / 2xi = (xi + n/xi) / 2。
//有了迭代公式xi+1= (xi + n/xi) / 2，程序就好写了。关于牛顿迭代法，可以参考wikipedia以及百度百科。
int sqrt(int x) {
		// Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (x ==0)
            return 0;
        double pre;
        double cur = 1;
        do
        {
            pre = cur;
            cur = x / (2 * pre) + pre / 2.0;
        } while (abs(cur - pre) > 0.00001);
        return int(cur);
    }

//
class Solution {
public:
    int sqrt(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        double ans = x;
        
        while(abs(ans * ans - x) > 0.0001)
        {
            ans = (ans + x / ans) / 2;
        }
        
        return (int)ans;
    }
};

//
//利用二分法查找：第一种可能性是直接找到能够麻烦要求的数；
//第二种可能性是找到相邻的两个数，可以比较两个数哪一个离target更近，不过题目当中希望找的是更小的那个数。
class Solution {
public:
    int sqrt(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(x<=1)
        {
            return x;
        }
        
        int left = 1;
        int right = x;
        
        while(left<=right)
        {
            int mid = left + ((right-left)>>1);
            if(mid == x/mid)
            {
                return mid;
            }
            else if(mid < x/mid)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        
        return right;
        
        /*int r = right * right;
        int l = left * left;
        if((x-r) > (l-x))
        {
            return left;
        }
        else
        {
            return right;
        }*/
    }
};


//LeetCode, Pow(x, n)
// 二分法，$x^n = x^{n/2} * x^{n/2} * x^{n\%2}$
// 时间复杂度O(logn)，空间复杂度O(1)
class Solution {
public:
    double pow(double x, int n) {
        if (n < 0) return 1.0 / power(x, -n);
        else return power(x, n);
    }
private:
    double power(double x, int n) {
        if (n == 0) return 1;
        double v = power(x, n / 2);
        if (n % 2 == 0) return v * v;
        else return v * v * x;
    }
};
