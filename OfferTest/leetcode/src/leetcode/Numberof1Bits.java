package leetcode;

public class Numberof1Bits {

	public static int hammingWeight(int n) {
		
		int cnt=0;
		
		while(n>0){
			cnt++;
			n=(n-1) &n;
		}
		
		return cnt;
    }
	
	public static int hammingWeight2(int n) {
		return Integer.bitCount(n);
    }
	
	
	public static void main(String[] args) {
		
		System.out.println(hammingWeight2(120));
		System.out.println(hammingWeight(120));	
	}

}
