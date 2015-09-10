package OfferSolution;

public class UglyNumber {
	public int GetUgly(int index){
		if(index<=0) return 0;
		int number=0;
		int uglyCnt=0;
		while(uglyCnt<index){
			number++;
			if(isUgly(number)){
				uglyCnt++;
			}
		}
		
		return number;
	}

	private boolean isUgly(int number) {
		// TODO Auto-generated method stub
		while(number % 2==0)
			number/=2;
		while(number % 3==0)
			number/=3;
		while(number % 5==0)
			number/=5;
			
		return (number==1)?true:false;
	}
	
	
//	使用三个变量记录乘以2、3、5之后有可能成为下一个丑数的位置。然后通过min(a,b,c)函数得到本次的丑数。
//	循环经过n次循环就得到了前n个丑数，返回想要的即可。
//
//	pMul_2,pMul_3,pMul_5，这三个变量记录的是这样的下标：
//	这三个下标的数有可能乘以2、3、5之后，是下一个丑数【取三者中的较小者】。
//
//	代码中，pMul_2++,pMul_3++,pMul_5++，分别代表了将产生d这个丑数的位置向后移动一位。
//	这样新位置就可以用来产生下一个丑数了。
	public int Solution2(int n){
		int[] data=new int[n+1];
		for(int i=0;i<data.length;i++){
			data[i]=0;
		}
		
		data[0]=1;
		int pMul_2=0;
		int pMul_3=0;
		int pMul_5=0;
		int index=0;
		while(index<n){
			index++;
			int d=min(data[pMul_2]*2,data[pMul_3]*3,data[pMul_5]*5);
			data[index]=d;
			
			while(data[pMul_2]*2==data[index])
				pMul_2++;
			
			while(data[pMul_3]*3==data[index])
				pMul_3++;
			
			while(data[pMul_5]*5==data[index])
				pMul_5++;
			
		}
		return data[n];
	}

	private int min(int i, int j, int k) {
		// TODO Auto-generated method stub
		return min(min(i,j),min(j,k));
	
	}

	private int min(int i, int j) {
		// TODO Auto-generated method stub
		return i>j?j:i;
		
	}
}
