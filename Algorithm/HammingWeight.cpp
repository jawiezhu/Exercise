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