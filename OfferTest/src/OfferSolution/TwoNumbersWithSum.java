package OfferSolution;

import java.util.HashMap;
import java.util.Map;

public class TwoNumbersWithSum {
	public static void TwoSum(int arr[],int target){
		Map<Integer,Integer> map=new HashMap<Integer,Integer>();
		for(int i=0;i<arr.length;i++){
			int x=arr[i];
			if(map.containsKey(target-x))
			{
				System.out.println((target-x)+"=="+x);
				break;
			}
			map.put(x, i);
		}
	}
	
	public static void main(String[] args){
		int arr[]={1,2,4,7,11,15};
		TwoSum2(arr,17);
	}
	
	public static void TwoSum2(int arr[],int target){
		int i=0;
		int j=arr.length-1;
		
		while(i<j){
			if(arr[i]+arr[j]<target)
				i++;
			if(arr[i]+arr[j]>target)
				j--;
			if(arr[i]+arr[j]==target){
				System.out.println(arr[i]+"=="+arr[j]);
				break;
			}
				
		}
	}
}


