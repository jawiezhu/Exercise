package leetcode;

import java.util.Vector;

public class UniquePaths {
	
	
	public int uniquePaths(int m, int n) {
		int[][]dp=new int[m][n];
		
		for(int i=0;i<n;i++){
			dp[0][i]=1;
		}
		
		for(int i=0;i<m;i++){
			dp[i][0]=1;
		}
		
		for(int i=1;i<m;i++){
			for(int j=1;j<n;j++){
				dp[i][j]=dp[i-1][j]+dp[i][j-1];
			}
		}
		
		return dp[m-1][n-1];
    }
	
	
	 public int uniquePaths3(int m, int n)  
	    {  
	        int[] table=new int[n];
	        
	        for(int i=0;i<n;i++){
	        	table[i]=1;
	        }
	        
	        for (int i = 1; i < m; i++)  
	        {  
	            for (int j = 1; j < n; j++)  
	            {  
	                table[j] += table[j-1];  
	            }  
	        }  
	        return table[n-1];  
	    }  
	
	//���� TimeLimitExceeded
	public int uniquePaths2(int m, int n) {
        if(m==1 || n==1) return 1;  
        return uniquePaths(m-1, n) + uniquePaths(m, n-1);  
    }
	


}
