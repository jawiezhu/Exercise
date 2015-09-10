package OfferSolution;

import java.util.Arrays;

public class ReorderArray {

	public static void Reorder(int[] A){
		if(A==null) return ;
		
		int L=0;
		int R=A.length-1;
		while(L<=R){
			if(A[L]%2==0 && A[R]%2!=0){
				int tmp=A[L];
				A[L]=A[R];
				A[R]=tmp;
			}else if(A[L]%2==0 && A[R]%2==0){
				R--;
			}else if(A[L]%2!=0 && A[R]%2!=0){
				L++;
			}else if(A[L]%2!=0 && A[R]%2==0){
				L++;
				R--;
			}
		}
		
		System.out.println(Arrays.toString(A));
	}
	
	
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int []A={2,1,4,3,6,7,8};
		Reorder(A);
	}

}
