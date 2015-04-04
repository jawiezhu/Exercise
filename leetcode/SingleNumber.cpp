//Given an array of integers, every element appears twice except for one. 
//Find that single one.

class Solution {
public:
    int singleNumber(int A[], int n) {
        if(n==0||A==NULL) return 0;
        int tmp=A[0];
        int i=0;
        for(i=1;i<n;i++)
        {
            tmp=tmp^A[i];
        } 
        return tmp;
    }
};