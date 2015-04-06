class HammingWeight{
public:
	int HammingWeight(uint32_t n){
		int cnt=0;
		while(n!=0)
		{
			if(n%2==1) //满足尾数为1
				cnt++;
			n/=2;//除以2，右移一位
		}

		return cnt;
	}

};

//=================================================

class HammingWeight{
public:
	int HammingWeight(uint32_t n){
		int cnt=0;
		while(n!=0)
		{
			cnt+=n&1;//尾数按位与1
			n>>=1;//右移一位
		}
		return cnt;
	}
};

//=================================================

class HammingWeight{
public:
	int HammingWeight(uint32_t n){
		int cnt=0;
		while(n!=0)
		{
			cnt+=n&1;//尾数按位与1
			n>>=1;//右移一位
		}
		return cnt;
	}
};


//=================================================

class HammingWeight{
public:
	int HammingWeight(uint32_t n){
		int cnt=0;
		whilie(n!=0)
		{
			n&=n-1;
			cnt++;
		}
		return cnt;
	}
};

//=================================================

class HammingWeight{
public:
	int HammingWeight(uint32_t n){
		n=(n&0x55555555)+((n>>1)&0x55555555);
		n=(n&0x33333333)+((n>>2)&0x33333333);
		n=(n&0x0f0f0f0f)+((n>>4)&0x0f0f0f0f);
		n=(n&0x00ff00ff)+((n>>8)&0x00ff00ff);
		n=(n&0x0000ffff)+((n>>16)&0x0000ffff);
		return n;
	}
};


 
//=================================================

class HammingWeight{
	typedef unsigned __int64 uint64;  //assume this gives 64-bits
	const uint64 m1  = 0x5555555555555555; //binary: 0101...
	const uint64 m2  = 0x3333333333333333; //binary: 00110011..
	const uint64 m4  = 0x0f0f0f0f0f0f0f0f; //binary:  4 zeros,  4 ones ...
	const uint64 m8  = 0x00ff00ff00ff00ff; //binary:  8 zeros,  8 ones ...
	const uint64 m16 = 0x0000ffff0000ffff; //binary: 16 zeros, 16 ones ...
	const uint64 m32 = 0x00000000ffffffff; //binary: 32 zeros, 32 ones
	const uint64 hff = 0xffffffffffffffff; //binary: all ones
	const uint64 h01 = 0x0101010101010101; //the sum of 256 to the power of 0,1,2,3...
 
//This is a naive implementation, shown for comparison,
//and to help in understanding the better functions.
//It uses 24 arithmetic operations (shift, add, and).
public:
	int HammingWeight(uint64_t x){
		x = (x & m1 ) + ((x >>  1) & m1 ); //put count of each  2 bits into those  2 bits 
    	x = (x & m2 ) + ((x >>  2) & m2 ); //put count of each  4 bits into those  4 bits 
    	x = (x & m4 ) + ((x >>  4) & m4 ); //put count of each  8 bits into those  8 bits 
    	x = (x & m8 ) + ((x >>  8) & m8 ); //put count of each 16 bits into those 16 bits 
    	x = (x & m16) + ((x >> 16) & m16); //put count of each 32 bits into those 32 bits 
    	x = (x & m32) + ((x >> 32) & m32); //put count of each 64 bits into those 64 bits 
    	return x;
	}
};




//=================================================



//This uses fewer arithmetic operations than any other known  
//implementation on machines with slow multiplication.
//It uses 17 arithmetic operations.
int popcount_2(uint64 x) {
    x -= (x >> 1) & m1;             //put count of each 2 bits into those 2 bits
    x = (x & m2) + ((x >> 2) & m2); //put count of each 4 bits into those 4 bits 
    x = (x + (x >> 4)) & m4;        //put count of each 8 bits into those 8 bits 
    x += x >>  8;  //put count of each 16 bits into their lowest 8 bits
    x += x >> 16;  //put count of each 32 bits into their lowest 8 bits
    x += x >> 32;  //put count of each 64 bits into their lowest 8 bits
    return x & 0x7f;
}


//=================================================


//This uses fewer arithmetic operations than any other known  
//implementation on machines with fast multiplication.
//It uses 12 arithmetic operations, one of which is a multiply.
int popcount_3(uint64 x) {
    x -= (x >> 1) & m1;             //put count of each 2 bits into those 2 bits
    x = (x & m2) + ((x >> 2) & m2); //put count of each 4 bits into those 4 bits 
    x = (x + (x >> 4)) & m4;        //put count of each 8 bits into those 8 bits 
    return (x * h01)>>56;  //returns left 8 bits of x + (x<<8) + (x<<16) + (x<<24) + ... 
}


//=================================================


//This is better if most bits in x are 0.
//It uses 2 arithmetic operations and one comparison/branch  per "1" bit in x.
//It is the same as the previous function, but with the loop unrolled.
#define f(y) if ((x &= x-1) == 0) return y;
int popcount_5(uint64 x) {
    if (x == 0) return 0;
    f( 1) f( 2) f( 3) f( 4) f( 5) f( 6) f( 7) f( 8)
    f( 9) f(10) f(11) f(12) f(13) f(14) f(15) f(16)
    f(17) f(18) f(19) f(20) f(21) f(22) f(23) f(24)
    f(25) f(26) f(27) f(28) f(29) f(30) f(31) f(32)
    f(33) f(34) f(35) f(36) f(37) f(38) f(39) f(40)
    f(41) f(42) f(43) f(44) f(45) f(46) f(47) f(48)
    f(49) f(50) f(51) f(52) f(53) f(54) f(55) f(56)
    f(57) f(58) f(59) f(60) f(61) f(62) f(63)
    return 64;
}
 
//Use this instead if most bits in x are 1 instead of 0
#define f(y) if ((x |= x+1) == hff) return 64-y;



//=================================================

static unsigned char wordbits[65536] = { bitcounts of ints between 0 and 65535 };
static int popcount(uint32 i)
{
    return (wordbits[i&0xFFFF] + wordbits[i>>16]);
}

