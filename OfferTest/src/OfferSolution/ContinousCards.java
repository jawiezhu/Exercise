package OfferSolution;

import java.util.Arrays;

public class ContinousCards {
	public boolean IsContinuous(int[] arr){
		if(arr==null) return false;
		Arrays.sort(arr); //ÉýÐò
		
		int numberofzero=0;
		int numberofGap=0;
		
		for(int i=0;i<arr.length && arr[i]==0;i++)
			numberofzero++;
		
		int small=numberofzero;
		int big=small+1;
		while(big<arr.length){
			if(arr[small]==arr[big])
				return false;
			
			numberofGap+=arr[big]-arr[small]-1;
			
			small=big;
			big++;
		}
		return (numberofGap>numberofzero) ? false : true;
	}
	

}
