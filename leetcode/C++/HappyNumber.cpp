// Write an algorithm to determine if a number is "happy".

// A happy number is a number defined by the following process: Starting with any positive integer, replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers.

// Example: 19 is a happy number

// 1^2 + 9^2 = 82
// 8^2 + 2^2 = 68
// 6^2 + 8^2 = 100
// 1^2 + 0^2 + 0^2 = 1

class Solution {
public:
	int cnt=0;

	int Sum(int m)
	{
		cnt++;
		int sum=0;
        int tmp=0;
		while(m>0)
		{
			tmp=m%10;
        	sum=sum+pow(tmp,2);
        	m=m/10;
		}
		if(sum==1)
		{
			return 1;
		}
		if(cnt>=100&&sum!=1)
		{
			return 0;
		}
		
		Sum(sum);
	}

    bool isHappy(int n) {
        if(n==0) return false;

        if(Sum(n)==1) return true;
        if(Sum(n)==0) return false;
    }
};


//改用HastSet存放中间数就行了，
//如果得到的新结果在中间数集合中出现了，那么一定会陷入循环并且得到的不是1。
public boolean isHappy(int n) {
        Set<Integer> res = new HashSet<>();
        int sum = n;
        while (sum != 1) {
            n = sum;
            sum = 0;
            while (n != 0) {
                sum += (n % 10) * (n % 10);
                n /= 10;
            }
            if (res.contains(sum)) {
                return false;
            }
            res.add(sum);
        }
        return true;
    }


//int型数的范围32位下上限是4294967296，也就是10位，9*9*10的话也才810，我开一个1000的数组就可以完成这个工作了。
// 整个模拟过程就是，
// 1.对每一个循环的当前数字求各位平方和
// 2.如果平方和等于1，那么返回true
// 3.如果平方和不为1，去标记数组中寻找，如果出现过，说明出现循环了，返回false
// 4.把这个下标的数组元素做标记，表示出现过了
public static boolean isHappy(int n) {
    	
    	int[] hash = new int[1000];
    	
    	for(int i=0;i<1000;i++){
    		hash[i] = 0;
    	}
    	
    	int m = n;
    	
    	boolean flag = false;
    	
    	while(true){
    		m=getSum(m);
    		if(m==1){
    			flag = true;
    			break;
    		}else if(hash[m]==1||m==n){
    			break;
    		}
    		hash[m] = 1;
    	}
    	return flag;
    }
    
    public static int getSum(int n){
    	int sum = 0;
    	while(n>0){
    		int t = n%10;
    		sum += t*t;
    		n /= 10;
    	}
    	return sum;
    }



//============
class Solution {
public:
    bool isHappy(int n) {
        if (n < 1)
            return false;
        if (n == 1)
            return true;
        unordered_set<int> showedNums;
        showedNums.insert(n);

        while(true)
        {
            int s = 0;
            while(n)
            {
                s += (n % 10) * (n % 10);
                n = n / 10;
            }

            if (s == 1)
                return true;
            else if (showedNums.find(s) != showedNums.end())
                return false;
            n = s;
            showedNums.insert(s);
        }
    }
};