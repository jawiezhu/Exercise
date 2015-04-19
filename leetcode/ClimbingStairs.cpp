// You are climbing a stair case. It takes n steps to reach to the top.

// Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

class Solution {
public:
    int climbStairs(int n) {
        if(n==0)return 0;
        if(n==1)return 1;
        
        int i;
        i=1;
        int tmp=1;
        int sum=1;
        int cur=1;
        while(i<n)
        {
            tmp=sum+cur;
            sum=cur;
            cur=tmp;
            i++;
        }
        
        return cur;
    }
};