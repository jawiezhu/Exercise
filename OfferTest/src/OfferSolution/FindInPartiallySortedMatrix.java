package OfferSolution;

public class FindInPartiallySortedMatrix {

	public static boolean Find(int matrix[][],int target){
		if(matrix==null) return false;
		
		int row=0;
		int col=matrix[0].length-1;
		
		while(row<matrix.length&&col>0){
			if(matrix[row][col]==target){
				return true;
			}else if(matrix[row][col]<target){
				row++;
			}else
				col--;
		}
		return false;
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int[][] matrix={{1,2,8,9},{2,4,9,12},{4,7,10,13}};
		System.out.println(Find(matrix,11));
		
	}

}
