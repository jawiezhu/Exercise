package leetcode_Easy;

public class UniquePathsII {
	public int uniquePathsWithObstacles(int[][] obstacleGrid) {
        if(obstacleGrid == null || obstacleGrid.length < 1 || obstacleGrid[0].length < 1
                || obstacleGrid[0][0] == 1
                || obstacleGrid[obstacleGrid.length - 1][obstacleGrid[0].length - 1] == 1)
        	return 0;
        
        int rows=obstacleGrid.length;
        int cols=obstacleGrid[0].length;
        int[][] res=new int[rows][cols];
        
        if(obstacleGrid[0][0]==0){
        	res[0][0]=1;
        }else{
        	res[0][0]=0;
        }
        
        for(int i=1;i<cols;i++){
        	if(obstacleGrid[0][i]==0){
        		res[0][i]=res[0][i-1];
        	}else{
        		res[0][i]=0;
        	}
        }
        
        for(int i=1;i<rows;i++){
        	if(obstacleGrid[i][0]==0){
        		res[i][0]=res[i-1][0];
        	}else{
        		res[i][0]=0;
        	}
        }
        
        for(int i=1;i<rows;i++){
        	for(int j=1;j<cols;j++){
        		if(obstacleGrid[i][j]==0){
        			res[i][j]=res[i-1][j]+res[i][j-1];
        		}else{
        			res[i][j]=0;
        		}
        	}
        }
        
        return res[rows-1][cols-1];
        
    }
}
