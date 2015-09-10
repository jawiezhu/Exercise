package OfferSolution;

public class SquenceOfBST {
	public boolean VerifyBST(int[] arr,int begin,int end){
		if(arr==null) return false;
		
		int root=arr[end];
		
		int i=begin;
		for(;i<end;i++){
			if(arr[i]>root)
				break;
		}
		
		int j=i;
		for(;j<end;j++){
			if(arr[j]<root)
				return false;
		}
		
		
		boolean left=true;
		if(i>0)
			left=VerifyBST(arr,begin,i-1);
		
		boolean right=true;
		if(i<end-1)
			right=VerifyBST(arr,i,end-1);
		
		return left&&right;
		
	}
}
