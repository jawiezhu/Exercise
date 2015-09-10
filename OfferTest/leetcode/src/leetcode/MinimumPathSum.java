package leetcode;

public class MinimumPathSum {
	/*
	 * 设dp[i][j]表示从左上角到grid[i][j]的最小路径和。
	 * 那么dp[i][j] = grid[i][j] + min( dp[i-1][j], dp[i][j-1] );
	 */
	public int minPathSum(int[][] grid) {
		if(grid==null||grid.length<1||grid[0].length<1){
			return 0;
		}
		
		int[][] res=new int[grid.length][grid[0].length];
		
		res[0][0]=grid[0][0];
		
		for(int i=1;i<res[0].length;i++){
			res[0][i]=res[0][i-1]+grid[0][i];
		}
		
		for(int i=1;i<res.length;i++){
			res[i][0]=res[i-1][0]+grid[i][0];
		}
		
		for(int i=1;i<res.length;i++){
			for(int j=1;j<res[0].length;j++){
				res[i][j]=Math.min(res[i-1][j], res[i][j-1])+grid[i][j];
			}
		}
		
		return res[res.length-1][res[0].length-1];
    }
	

	
	public int minPathSum2(int[][] grid) {
		return dfs(0,0,grid);
	}

	private int dfs(int i, int j, int[][] grid) {
		
		if(i==grid.length-1 && j==grid[0].length-1){
			return grid[i][j];
		}
		
		if(i<grid.length-1 && j<grid[0].length-1){
			int r1=grid[i][j]+dfs(i+1,j,grid);
			int r2=grid[i][j]+dfs(i,j+1,grid);
			return Math.min(r1, r2);
		}
		
		if(i<grid.length-1)
			return grid[i][j]+dfs(i+1,j,grid);
		
		if(j<grid.length-1)
			return grid[i][j]+dfs(i,j+1,grid);
		
		
		return 0;
	}
	

}
