package leetcode_Easy;

public class ClimbingStairs {
	 public static int climbStairs(int n) {
		 int one=2;
		 int two=1;
		 int sum=0;
		 if(n==1) return two;
		 if(n==2) return one;
		 while(n>2){
			 sum=one+two;
			 two=one;
			 one=sum;
			 n--;
		 }
		 
		 return sum;
		 
	 }
	 
	 
	 public static int climbStairs2(int n){
		 int res=0;
		 
		 if(n==1){
			 res=1;
		 }else if(n==2){
			 res=2;
		 }else if(n>2){
			 int []ways=new int[n];
			 
			 ways[0]=1;
			 ways[1]=2;
			 for(int i=2;i<ways.length;i++){
				 ways[i]=ways[i=1]+ways[i-2];
			 }
			 
			 res=ways[ways.length-1];
		 }
		 return res;
	 }
	 
	 
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		System.out.println(climbStairs(4));

	}

}
