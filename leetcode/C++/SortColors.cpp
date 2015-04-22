// Given an array with n objects colored red, white or blue, 
// sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.

// Here, we will use the integ rs 0, 1, and 2 to represent the color red, white, and blue respectively.

// Note:
// You are not suppose to use the library's sort function for this problem.

// click to show follow up.

// Follow up:
// A rather straight forward solution is a two-pass algorithm using counting sort.
// First, iterate the array counting number of 0's, 1's, and 2's, then overwrite array with total number of 0's, then 1's and followed by 2's.

// Could you come up with an one-pass algorithm using only constant space?
//计数排序
class Solution {
public:
    void sortColors(int A[], int n) {
        int num0=0;
        int num1=0;
        int num2=0;

        for(int i=0;i<n;i++)
        {
        	if(A[i]==0)
        		num0++;
        	if(A[i]==1)
        		num1++;
        	if(A[i]==2)
        		num2++;
        }

        for(int i=0;i<num0;i++)
        	A[i]=0;
        for(int i=num0;i<num0+num1;i++)
        	A[i]=1;
        for(int i=num0+num1;i<n;i++)
        	A[i]=2;
    }
};


// 如果只能扫一遍，很容易想到的就是左边存放0和1，右边存放2.两边往中间靠。

// 设置两个index，left记录第一个1的位置，left左边为0，right记录第一个非2的位置，right右边为2.

// 然后使用i从头到尾扫一遍，直到与right相遇。

// i遇到0就换到左边去，遇到2就换到右边去，遇到1就跳过。

// 需要注意的是：由于left记录第一个1的位置，因此A[left]与A[i]交换后，A[left]为0,A[i]为1，因此i++；

// 而right记录第一个非2的位置，可能为0或1，因此A[right]与A[i]交换后，A[right]为2,A[i]为0或1，i不能前进，要后续判断。

// 由此该数组分为4段：[0,left)-->0; [left,i)-->1; [i,right]-->乱序; (right,n-1]-->2

// 0  0  0  1  1  1  2  1  0  2  1  2  2  2

//            ^         ^             ^

//           left         i            right

class Solution{
public:
	void sortColors(int A[],int n){
		int left=0;
		int right=n-1;
		int i=0;
		while(i<=right)
		{
			if(A[i]==0)
			{
				swap(A[left],A[i]);
				left++;
				i++;
			}else if(A[i]==1)
			{
				i++;
			}
			else
			{
				swap(A[i],A[right]);
				right--;
			}
		}
	}
};

//平移插入
class Solution{
public:
	void sortColors(int A[],int n){
		int i=-1;
		int j=-1;
		int k=-1;
		for(int p=0;p<n;p++)
		{
			//根据第i个数字，挪动0~i-1串。
			if(A[p]==0)
			{
				A[++k]=2;
				A[++j]=1;
				A[++i]=0;
			}else if(A[p]==1)
			{
				A[++k]=2;
				A[++j]=1;
			}else
				A[++k]=2;
		}
	}
};


//EX:
#include <iostream>
using namespace std;


void print(int A[])
{
	for(int i=0;i<9;i++)
		cout<<A[i]<<" ";
	cout<<endl;
}

void sortColors(int A[],int n){
		int i=-1;
		int j=-1;
		int k=-1;
		for(int p=0;p<n;p++)
		{
			//根据第i个数字，挪动0~i-1串。
			if(A[p]==0)
			{
				A[++k]=2;
				print(A);
				A[++j]=1;
				print(A);
				A[++i]=0;
				print(A);
				cout<<"k:"<<k<<" "<<"j:"<<j<<" "<<"i:"<<i<<endl;
			}else if(A[p]==1)
			{
				A[++k]=2;
				print(A);
				A[++j]=1;
				print(A);
				cout<<"k:"<<k<<" "<<"j:"<<j<<" "<<"i:"<<i<<endl;

			}else{
				A[++k]=2;
				print(A);
				cout<<"k:"<<k<<" "<<"j:"<<j<<" "<<"i:"<<i<<endl;
			}
				
		}
	}

int main()
{
	int A[9]={1,0,1,2,0,1,2,2,0};
	sortColors(A,9);
	for(int i=0;i<9;i++)
		cout<<A[i]<<" ";
}

//=============
// LeetCode, Sort Colors
// 重新实现 partition()
// 时间复杂度O(n)，空间复杂度O(1)
class Solution {
public:
    void sortColors(int A[], int n) {
        partition(partition(A, A + n, bind1st(equal_to<int>(), 0)), A + n,
                bind1st(equal_to<int>(), 1));
    }
private:
    template<typename ForwardIterator, typename UnaryPredicate>
    ForwardIterator partition(ForwardIterator first, ForwardIterator last,
            UnaryPredicate pred) {
        auto pos = first;

        for (; first != last; ++first)
            if (pred(*first))
                swap(*first, *pos++);

        return pos;
    }
};

