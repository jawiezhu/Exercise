package OfferSolution;

import java.util.HashMap;
import java.util.Map;

public class NumberOfK {
	public static void NumberOfK(int arr[]){
		Map<Integer,Cnt> map=new HashMap<Integer,Cnt>();
		for(int i=0;i<arr.length;i++){
			if(map.containsKey(arr[i])){
				map.get(arr[i]).add();
			}else{
				map.put(arr[i], new Cnt(1));
			}
		}
		
		System.out.println(map.get(3).getCount());
	}
	
	public static void main(String[] args){
		int arr[]={1,2,3,3,3,3,4,5};
		NumberOfK(arr);
	}
}
class Cnt{
	private int count;
	public Cnt(int x){
		this.count=x;
	}
	
	public void add(){
		count++;
	}
	
	public int getCount(){
		return count;
	}
}




class Solution2{
	public static int GetFirstK(int arr[],int length,int k,int start,int end){
		if(start>end) return -1;
		
		int middleIndex=(start+end)/2;
		int middleData=arr[middleIndex];
		
		if(middleData==k){
			if((middleIndex>0&&arr[middleIndex-1]!=k)||middleIndex==0)
				return middleIndex;
			else
				end=middleIndex-1;
		}else if(middleData>k)
			end=middleIndex-1;
		else
			start=middleIndex+1;
		
		return GetFirstK(arr,length,k,start,end);
	}
	
	public static int GetLastK(int arr[],int length,int k,int start,int end){
		if(start>end) return -1;
		int middleIndex=(start+end)/2;
		int middleData=arr[middleIndex];
		
		if(middleData==k){
			if((middleIndex<length-1 && arr[middleIndex+1]!=k)||middleIndex==length-1)
				return middleIndex;
			else
				start=middleIndex+1;
		}else if(middleData<k)
			start=middleIndex+1;
		else
			end=middleIndex-1;
		
		return GetLastK(arr,length,k,start,end);
		
	}
	
	public int GetNumberOfK(int[] arr,int length,int k){
		int number=0;
		if(arr!=null && length>0){
			int first=GetFirstK(arr,length,k,0,length-1);
			int last=GetLastK(arr,length,k,0,length-1);
			
			if(first>-1 && last>-1)
				number=last-first+1;
		}
		
		return number;
	}
}
