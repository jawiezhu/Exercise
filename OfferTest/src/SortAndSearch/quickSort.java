package SortAndSearch;

import java.util.Arrays;

public class quickSort {
	
	public static void quickSort(int[] arr,int left,int right){
		int index=partition(arr,left,right);
		if(left<index-1)
			quickSort(arr,left,index-1);
		if(index<right)
			quickSort(arr,index,right);
	}
	
	private static int partition(int[] arr, int left, int right) {
		int i=left;
		int j=right;
		int tmp;
		int pivot=arr[(left+right)/2];
		
		while(i<=j){
			while(arr[i]<pivot)
				i++;
			while(arr[j]>pivot)
				j--;
			if(i<=j){
				tmp=arr[i];
				arr[i]=arr[j];
				arr[j]=tmp;
				i++;
				j--;
			}
		}
		
		return i;
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int[] arr={88,3,7,1,2,11,0,-2};
		quickSort(arr,0,arr.length-1);
		System.out.println(Arrays.toString(arr));
	}

}
