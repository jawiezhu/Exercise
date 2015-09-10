package OfferSolution;

public class GreatetSumOfSubarrays {	
	boolean Invalid=false;
	public int FindGreast(int arr[]){
		if(arr==null){
			Invalid=true;
			return 0;
		}
		
		Invalid=false;
		
		int CurSum=0;
		int GreatestSum=Integer.MIN_VALUE;
		for(int i=0;i<arr.length;i++){
			if(CurSum<=0){
				CurSum=arr[i];
			}else
				CurSum+=arr[i];
			
			if(CurSum>GreatestSum){
				GreatestSum=CurSum;
			}
		}
		
		return GreatestSum;
	}
	
	
	public int maxSubArray(int[] A){
		int maxEndingHere=A[0];
		int maxSoFar=A[0];
		for(int i=0;i<A.length;i++){
			maxEndingHere=Math.max(maxEndingHere+A[i], A[i]);
			maxSoFar=Math.max(maxEndingHere,maxSoFar);
		}
		
		return maxSoFar;
	}
}
