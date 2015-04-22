class Solution:
    # @param n, an integer
    # @return an integer
    def hammingWeight(self, n):
        cnt=0;
        while n !=0:
            cnt+=n&1
            n=n>>1
        return cnt