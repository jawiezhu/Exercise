package OfferSolution;

public class ContinuesSquenceWithSum {
	public static void FindContinuousSequence(int sum){
		if(sum<3) return;
		
		int small=1;
		int big=2;
		int middle=(1+sum)/2;
		int curSum=small+big;
		
		while(small<middle){
			if(curSum==sum)
				Print(small,big);
			
			while(curSum>sum && small<middle){
				curSum-=small;
				small++;
				
				if(curSum==sum)
					Print(small,big);
			}
			big++;
			curSum+=big;
		}
	}
	
	public static void Print(int small,int big){
		for(int i=small;i<=big;i++)
			System.out.print(i+" ");
		System.out.println();
	}
	
	public static void main(String[] args){
		FindContinuousSequence(100);
	}
}
