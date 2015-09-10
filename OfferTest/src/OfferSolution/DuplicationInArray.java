package OfferSolution;

import java.util.Arrays;

public class DuplicationInArray {
	public static boolean duplicate(int arr[]){
		
		int cnt=0;
		int []dup=new int[arr.length-1];
		if(arr==null) return false;
		
		
		// 判断输入的是否在[0, number.length-1]之间
		for(int i=0;i<arr.length-1;i++){
			if(arr[i]<0||arr[i]>arr.length-1)
				return false;
		}
		
		for(int i=0;i<arr.length-1;i++){
			// 当number[i]与i不相同的时候一直交换
			while(arr[i]!=i){
				
				 // 如果i位置与number[i]位置的数字相同，说明有重复数字
				if(arr[i]==arr[arr[i]]){
					System.out.println(arr[i]);
					return true;
				}else{
					// 如果不同就交换
					int temp=arr[i];
					arr[i]=arr[temp];
					arr[temp]=temp;
				}
			}
		}
		
		return false;
	}
	
	public static void main(String[] args){
		int[] arr={2,4,1,0,4,5,3};
		duplicate(arr);
	}
}
