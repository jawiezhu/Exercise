package leetcode;

import java.util.List;

public class Triangle {
	//Bottom-Up
	
//	dp[i][j] = value[i][j] + min{dp[i-1][j], dp[i-1][j+1]}
//
//	因为每一层之和它下一层的值有关，因此只需要一个一位数组保存下层的值，
	
	
	public int minimumTotal(List<List<Integer>> triangle) {
        int[] total=new int[triangle.size()];
        int l=triangle.size()-1;
        
        for(int i=0;i<triangle.get(l).size();i++){
        	total[i]=triangle.get(l).get(i);
        }
        
        for(int i=triangle.size()-2;i>=0;i--){
        	for(int j=0;j<triangle.get(i+1).size()-1;j++){
        		total[j]=triangle.get(i).get(j)+Math.min(total[j], total[j+1]);
        	}
        }
        
        return total[0];
    }
}
