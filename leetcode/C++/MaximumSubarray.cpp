// Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

// For example, given the array [−2,1,−3,4,−1,2,1,−5,4],
// the contiguous subarray [4,−1,2,1] has the largest sum = 6.



class Solution {
public:
    int maxSubArray(int A[], int n) {
        if(n<=0) return 0;
        
        int sum=0;
        int max=INT_MIN;
        
        
        for(int i=0;i<n;i++)
        {
            sum+=A[i];
            if(sum>max) max=sum;
            if(sum<0) sum=0;
            
        }
        return max;
    }
};

//分治法
int myMaxSubArray(int A[], int m, int n)
{
    if (m == n) return A[m];

    int mid = (m+n)/2;
    int maxPre = myMaxSubArray(A, m, mid);
    int maxEnd = myMaxSubArray(A, mid+1, n);

    int leftMax = INT_MIN;
    int rightMax = INT_MIN;
    int sum = 0;
    for (int i = mid; i >= m; i--)
    {
        sum += A[i];
        if (sum > leftMax)
            leftMax = sum;
    }
    sum = 0;
    for (int i = mid+1; i <=n; i++)
    {
        sum += A[i];
        if (sum > rightMax)
            rightMax = sum;
    }
    sum = leftMax + rightMax;

    return std::max(sum, std::max(maxPre, maxEnd));
}

int maxSubArray(int A[], int n) 
{
    if (n <= 0) return 0;

    return myMaxSubArray(A, 0, n-1);
}


//=====================================
int myMaxSubArray(int A[], int m, int n)
{
    if (m == n) return A[m];
    if (m > n) return INT_MIN;

    int mid = (m+n)/2;//mid 的取值范围 [m, n],如果m, n 相同则 mid == m == n
    int maxPre = myMaxSubArray(A, m, mid-1);
    int maxEnd = myMaxSubArray(A, mid+1, n);//根据可能mid == n，这个分支有可能产生mid+1 > n的情况，所以需要判断 if（m>n)
                                            //但事实真的是这样吗？假如不加这个if语句呢，通过分析程序发现，如果不加if语句则
                                            //两个for循环根本不会执行。
                                            //虽然for不会执行就不会出现数组下标越界读取错误，但可能再次递归调用，本着剪枝的原则
                                            //我觉得还是应该加上这个if语句

    int leftMax = INT_MIN;
    int rightMax = INT_MIN;
    int sum = 0;
    for (int i = mid; i >= m; i--)
    {
        sum += A[i];
        if (sum > leftMax)
            leftMax = sum;
    }
    sum = 0;
    for (int i = mid+1; i <=n; i++)
    {
        sum += A[i];
        if (sum > rightMax)
            rightMax = sum;
    }

    //这里不得不提的子问题，最开始的时候这里只有sum = leftMax + rightMax;这句，
    //但int maxPre = myMaxSubArray(A, m, mid-1);这里写的是mid才可以，因为这样才能把
    //所有子问题全部包括。如果坚持这里要缩小子问题，那sum的取值就应该是如下写法，这样才能
    //把[m,mid]和[mid+1,n]子问题包含。
    //建议是写成myMaxSubArray(A, m, mid)，这样程序的逻辑简单些

    if (leftMax < 0 || rightMax < 0)
        sum = std::max(leftMax, rightMax);
    else
        sum = leftMax + rightMax;

    return std::max(sum, std::max(maxPre, maxEnd));
}

int maxSubArray(int A[], int n) 
{
    if (n <= 0) return 0;

    return myMaxSubArray(A, 0, n-1);
}

