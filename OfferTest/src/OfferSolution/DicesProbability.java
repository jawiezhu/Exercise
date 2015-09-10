package OfferSolution;

public class DicesProbability {
	
	
//	基于循环求骰子的点数，这样避免了很多重复的计算，时间性能要好。
//	我们可以考虑用两个数组来存储骰子点数每一总数出现的次数。在一次循环中，
//	第一个数组中的第n个数字表示骰子和为n出现的次数。那么在下一循环中，我们加上一个新的骰子。
//	那么此时和为n的骰子出现的次数，应该等于上一次循环中骰子点数和为n-1、n-2、n-3、n-4、n-5与n-6的总和
	
	
	/* 
	有k-1个骰子时，再增加一个骰子，这个骰子的点数只可能为1、2、3、4、5或6。那k个骰子得到点数和为n的情况有： 
	(k-1,n-1)：第k个骰子投了点数1 
	(k-1,n-2)：第k个骰子投了点数2 
	(k-1,n-3)：第k个骰子投了点数3 
	.... 
	(k-1,n-6)：第k个骰子投了点数6 
	在k-1个骰子的基础上，再增加一个骰子出现点数和为n的结果只有这6种情况！ 
	所以：f(k,n)=f(k-1,n-1)+f(k-1,n-2)+f(k-1,n-3)+f(k-1,n-4)+f(k-1,n-5)+f(k-1,n-6) 
	初始化：有1个骰子，f(1,1)=f(1,2)=f(1,3)=f(1,4)=f(1,5)=f(1,6)=1。 
	     */  
	 public static void printProbabilityOfDice2(int n){  
		 	int MAX=6;
	        if(n<1){  
	            return;  
	        }  
	        double total=Math.pow(MAX, n);   
	        int maxSum=n*MAX;  
	        double[][] f=new double[n+1][n*MAX+1];  
	        for(int i=1;i<=MAX;i++){  
	            f[1][i]=1;  
	        }  
	        for(int k=2;k<=n;k++){  
	            for(int sum=n;sum<=maxSum;sum++){  
	                for(int i=1;sum-i>=1&&i<=MAX;i++){  
	                    f[k][sum]+=f[k-1][sum-i];  
	                }  
	            }  
	        }  
	          
	        for(int sum=n;sum<=maxSum;sum++){  
	            System.out.println(sum+","+f[n][sum]+"/"+total);  
	        }  
	    }  
	
//	 这种方法是DP中的表格法，用至底向上填表的方式，把结果求出来。
//	 用表格法，一行代表一个骰子，列表示各个S值，所以一共有6*N列。
//	 本来是要用N行的，可是这里只用了一个二维的数组，因为现在计算的值只与前一次计算的值相关，
//	 所以其中一行保存上一次计算的结果，另一行保存正在计算的结果，这样可以节省大量的空间。
//	 代码中的N是指有几个骰子，或者说是掷了几次骰子。第一个for循环表示第一个骰子的情况，
//	 然后第二个for循环中的k表示第k个骰子。当到了第k个骰子时，内层的for循环开始对和个S的值进行分析，
//	 i表示的就是各个不同的S。在这个循环里，考虑第k个骰子的6种不同取值（j表示的就是骰子的点数），
//	 然后在while循环里把所有可能的得到和为S的组合的概率进行相加。
//	 flag的作用很简单，就是在二维数组里对当时值和已经计算得到的值进行区别，他只出现在数组的行号处。
	 
	
	 
//	利用基本的概率论知识，而不需要统计所有可能的S出现的次数。为了方便，这里先讨论某个S出现的概率，设为P(S),则有
//	P(S) = P(S1) + P(S2) + ... + P(Sk)
//	S1,S2...Sk表示和为S的各种骰子组合。另外，
//	    P(Si) = P(a1) + P(a2) + ... + P(an)
//	其中，P(ai)表示第i个骰子出现值为ai的概率。
//
//	很简单的，就是一个概率论的东西，很基本的。不需要统计所有可能的S出现的次数，
//	而直接计算和为S的各种可能的骰子组合的概率，然后把所有组合的概率相加，就得到了和为S的概率了。
	 
	public static void PrintProbability(int number){
		int gMaxValue=6;
		if(number<1) return;
		
		int maxSum=gMaxValue*number+1;
		int[][] probilities=new int[2][maxSum];
		int flag=0;
		for(int i=1;i<=gMaxValue;i++)
			probilities[flag][i]=1;
		
		for(int i=2;i<=number;i++){
			for(int j=0;j<i;j++)
				probilities[1-flag][j]=0;
			for(int j=i;j<=gMaxValue*i;j++){
				probilities[1-flag][j]=0;
				for(int k=1;k<=j && k<=gMaxValue;k++)
					probilities[1-flag][j]+=probilities[flag][j-k];
			}
			flag=1-flag;
		}
		double total=Math.pow(gMaxValue, number);
		for(int i=number;i<maxSum;i++){
			double ratio=probilities[flag][i]/total;
			System.out.println(i+":"+ratio);
		}
	}
	
	 public static void main(String[] args){
	        int number = 11;
	        PrintProbability(number);
	    }
}

//最直接的方法是求出n个骰子点数的全排列，然后一一计算其和值，统计，
//最后算出每个和值的概率，这里使用基于递归的方法来求各和值的频数.
//先把n个骰子分为两堆：第一堆只有一个，另一个有n-1个。
//单独的那一个有可能出现从1到6的点数。
//我们需要计算从1到6的每一种点数和剩下的n-1个骰子来计算点数和。
//接下来把剩下的n-1个骰子还是分成两堆，第一堆只有一个，第二堆有n-2个。
//我们把上一轮那个单独骰子的点数和这一轮单独骰子的点数相加，
//再和剩下的n-2个骰子来计算点数和。
class SolutionDices2{
	private int gMaxValue=6;
	
	public void printProbability(int number){
		if(number<1) return;
		int maxSum=number*gMaxValue;
		int[] probilities=new int[maxSum-number+1];
		probility(number,probilities);
		
		double total=Math.pow(gMaxValue, number);
		for(int i=number;i<maxSum;i++){
			double ratio=probilities[i-number]/total;
			System.out.println(i+":"+ratio);
		}
	}

	private void probility(int number, int[] probilities) {
		// TODO Auto-generated method stub
		for(int i=1;i<=gMaxValue;i++){
			probility(number,number,i,probilities);
		}
	}

	private void probility(int orignal, int current, int sum, int[] probilities) {
		// TODO Auto-generated method stub
		if(current==1){
			probilities[sum-orignal]++;
		}else{
			for(int i=1;i<=gMaxValue;i++){
				probility(orignal,current-1,sum+i,probilities);
			}
		}
	}
}