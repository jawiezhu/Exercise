
// Write a function that takes an unsigned integer and returns the number of ’1' bits it has (also known as the Hamming weight).

// For example, the 32-bit integer ’11' has binary representation 00000000000000000000000000001011, so the function should return 3.

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int cnt=0;
        while(n!=0)
        {
            cnt+=n&1; //not cnt=cnt+n&1  because + is prior than &, and & than +=
            n=n>>1;
        }
        return cnt;
    }
};

class Solution{
public:
	int hammingWeight(uint32_t n){
		int cnt=0;
		while(n!=0)
		{
			if(n%2==1) //The end is 1.
				cnt++;
			n/=2;
		}
		return cnt;
	}
};




