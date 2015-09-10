package OfferSolution;

public class MinNumberInRotateArray {

	public int FindMin(int[] A){
		int L=0;
		int R=A.length-1;
		
		while(L<R&&A[L]>=A[R]){
			int M=(L+R)/2;
			
			if(A[L]>A[M]){
				R=M;
			}else if(A[R]<A[M]){
				L=M+1;
			}else{
				L=L+1;
			}
		}
		return A[L];
	}
	
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

}
