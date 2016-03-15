package leetcode_Easy;

public class FactorialTrailingZeroes {
	 public int trailingZeroes(int n) {
	       int res=0;
	       long tmp=n;
	       for(long i=5;i<=tmp;i*=5){
	    	   res+=n/i;
	       }
	       
	       return res;
	 }
}
