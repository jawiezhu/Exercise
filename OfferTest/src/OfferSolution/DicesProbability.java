package OfferSolution;

public class DicesProbability {
	
	
//	����ѭ�������ӵĵ��������������˺ܶ��ظ��ļ��㣬ʱ������Ҫ�á�
//	���ǿ��Կ����������������洢���ӵ���ÿһ�������ֵĴ�������һ��ѭ���У�
//	��һ�������еĵ�n�����ֱ�ʾ���Ӻ�Ϊn���ֵĴ�������ô����һѭ���У����Ǽ���һ���µ����ӡ�
//	��ô��ʱ��Ϊn�����ӳ��ֵĴ�����Ӧ�õ�����һ��ѭ�������ӵ�����Ϊn-1��n-2��n-3��n-4��n-5��n-6���ܺ�
	
	
	/* 
	��k-1������ʱ��������һ�����ӣ�������ӵĵ���ֻ����Ϊ1��2��3��4��5��6����k�����ӵõ�������Ϊn������У� 
	(k-1,n-1)����k������Ͷ�˵���1 
	(k-1,n-2)����k������Ͷ�˵���2 
	(k-1,n-3)����k������Ͷ�˵���3 
	.... 
	(k-1,n-6)����k������Ͷ�˵���6 
	��k-1�����ӵĻ����ϣ�������һ�����ӳ��ֵ�����Ϊn�Ľ��ֻ����6������� 
	���ԣ�f(k,n)=f(k-1,n-1)+f(k-1,n-2)+f(k-1,n-3)+f(k-1,n-4)+f(k-1,n-5)+f(k-1,n-6) 
	��ʼ������1�����ӣ�f(1,1)=f(1,2)=f(1,3)=f(1,4)=f(1,5)=f(1,6)=1�� 
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
	
//	 ���ַ�����DP�еı�񷨣��������������ķ�ʽ���ѽ���������
//	 �ñ�񷨣�һ�д���һ�����ӣ��б�ʾ����Sֵ������һ����6*N�С�
//	 ������Ҫ��N�еģ���������ֻ����һ����ά�����飬��Ϊ���ڼ����ֵֻ��ǰһ�μ����ֵ��أ�
//	 ��������һ�б�����һ�μ���Ľ������һ�б������ڼ���Ľ�����������Խ�ʡ�����Ŀռ䡣
//	 �����е�N��ָ�м������ӣ�����˵�����˼������ӡ���һ��forѭ����ʾ��һ�����ӵ������
//	 Ȼ��ڶ���forѭ���е�k��ʾ��k�����ӡ������˵�k������ʱ���ڲ��forѭ����ʼ�Ժ͸�S��ֵ���з�����
//	 i��ʾ�ľ��Ǹ�����ͬ��S�������ѭ������ǵ�k�����ӵ�6�ֲ�ͬȡֵ��j��ʾ�ľ������ӵĵ�������
//	 Ȼ����whileѭ��������п��ܵĵõ���ΪS����ϵĸ��ʽ�����ӡ�
//	 flag�����úܼ򵥣������ڶ�ά������Ե�ʱֵ���Ѿ�����õ���ֵ����������ֻ������������кŴ���
	 
	
	 
//	���û����ĸ�����֪ʶ��������Ҫͳ�����п��ܵ�S���ֵĴ�����Ϊ�˷��㣬����������ĳ��S���ֵĸ��ʣ���ΪP(S),����
//	P(S) = P(S1) + P(S2) + ... + P(Sk)
//	S1,S2...Sk��ʾ��ΪS�ĸ���������ϡ����⣬
//	    P(Si) = P(a1) + P(a2) + ... + P(an)
//	���У�P(ai)��ʾ��i�����ӳ���ֵΪai�ĸ��ʡ�
//
//	�ܼ򵥵ģ�����һ�������۵Ķ������ܻ����ġ�����Ҫͳ�����п��ܵ�S���ֵĴ�����
//	��ֱ�Ӽ����ΪS�ĸ��ֿ��ܵ�������ϵĸ��ʣ�Ȼ���������ϵĸ�����ӣ��͵õ��˺�ΪS�ĸ����ˡ�
	 
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

//��ֱ�ӵķ��������n�����ӵ�����ȫ���У�Ȼ��һһ�������ֵ��ͳ�ƣ�
//������ÿ����ֵ�ĸ��ʣ�����ʹ�û��ڵݹ�ķ����������ֵ��Ƶ��.
//�Ȱ�n�����ӷ�Ϊ���ѣ���һ��ֻ��һ������һ����n-1����
//��������һ���п��ܳ��ִ�1��6�ĵ�����
//������Ҫ�����1��6��ÿһ�ֵ�����ʣ�µ�n-1����������������͡�
//��������ʣ�µ�n-1�����ӻ��Ƿֳ����ѣ���һ��ֻ��һ�����ڶ�����n-2����
//���ǰ���һ���Ǹ��������ӵĵ�������һ�ֵ������ӵĵ�����ӣ�
//�ٺ�ʣ�µ�n-2����������������͡�
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