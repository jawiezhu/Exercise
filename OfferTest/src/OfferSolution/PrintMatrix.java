package OfferSolution;

public class PrintMatrix {
	
	public static void  PrintMatrix(int [][] A){
		int n=A[0].length;
		int m=A.length;
		
		int row=0;
		int col=-1;
		
		while(true){
			
			
			for(int i=0;i<n;i++){
				col++;
				System.out.print(A[row][col]+" ");
			}
			m--;
			if(m==0) break;
			
			
			
			
			for(int i=0;i<m;i++){
				row++;
				System.out.print(A[row][col]+" ");
			}
			n--;
			if(n==0) break;
			
			
			for(int i=0;i<n;i++){
				col--;
				System.out.print(A[row][col]+" ");
			}
			m--;
			if(m==0) break;
			
			
			for(int i=0;i<m;i++){
				row--;
				System.out.print(A[row][col]+" ");
			}
			n--;
			if(n==0) break;
			
		}
		
		
		
		
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int[] A[]={{1,2,3,11},{4,5,6,12},{7,8,9,13}};
		PrintMatrix(A);
	}

}
