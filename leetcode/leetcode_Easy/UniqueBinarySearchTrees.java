package leetcode_Easy;

public class UniqueBinarySearchTrees {
	 //一共n个，root是1个(可能是1:n中的一个)，左边分到比root小的i-1个，右边分到比root大的n-i个，左边的组合数*右边的组合数
	//Time Limit Exceeded
	public int numTrees(int n) {
        if(n==1||n==0) return 1;
        int num=0;
        for(int i=1;i<=n;i++){
        	num+=numTrees(i-1)*numTrees(n-i);
        }
        
        return num;
    }
	
	
	/*
	The case for 3 elements example
	Count[3] = Count[0]*Count[2]  (1 as root)
	              + Count[1]*Count[1]  (2 as root)
	              + Count[2]*Count[0]  (3 as root)

	Therefore, we can get the equation:
	Count[i] = ∑ Count[0...k] * [ k+1....i]     0<=k<i-1  
	*/
	public int numTrees2(int n) {
        int []count=new int[n+2];
        count[0]=1;
        count[1]=1;
        for(int i=2;i<=n;i++){
        	for(int j=0;j<i;j++){
        		//如果左子树的个数为j，那么右子树为i - j - 1
        		count[i]+=count[j]*count[i-j-1];
        	}
        }
        return count[n];
    }
}
