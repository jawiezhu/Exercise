// Given an array and a value, remove all instances of that value in place and return the new length.

// The order of elements can be changed. It doesn't matter what you leave beyond the new length.


class Solution{
public:
	int removeElement(int a[],int n,int elem)
	{
		int i;
		int cnt;
		cnt=0;
		for(i=0;i<n;i++)
		{
			if(a[i]==elem)
			{
				cnt++;
			}else if(cnt>0)
			{
				a[i-cnt]=a[i];
			}

		}
        return n-cnt;
	  }
};

//============================
class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        int i,j;
        for(int i=0;i<n;i++)
        {
            if(A[i]==elem)
            {
                for(j=i;j<n-1;j++) A[j]=A[j+1];
                n--;
                i--;              //i--很重要，因为后一个元素向前移，i++以后可能就遍历不到当前的这个刚移动的结点
            }
        }
        return n;
    }
};

//==============
public class Solution {
    public int removeElement(int[] A, int elem) {
        int startPosition = 0;
        for (int i = 0; i < A.length; i++) {
            if (A[i] != elem) {
                A[startPosition] = A[i];
                startPosition++;
            }
        }
        return startPosition;
    }


//=============
// LeetCode, Remove Element
// 时间复杂度O(n)，空间复杂度O(1)
class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        int index = 0;
        for (int i = 0; i < n; ++i) {
            if (A[i] != elem) {
                A[index++] = A[i];
            }
        }
        return index;
    }
};

