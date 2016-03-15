package leetcode_Easy;

import java.util.Arrays;

public class MoveZeroes {
	public static void moveZeroes(int[] nums){
		if(nums.length<=1) return;
		int first=0;
		int sec=0;
		while(sec<nums.length){
			
			while(first<nums.length && nums[first]!=0){
				first++;
			}
			if(first==nums.length) return ;
			
			sec=first;
			
			while(sec<nums.length && nums[sec]==0){ //sec is no 0
				sec++;
			}
			
			if(sec==nums.length) return;
			
			swap(nums,first,sec);
			
		}
		
		
	}

	private static void swap(int[] nums, int first, int sec) {
		// TODO Auto-generated method stub
		int temp=nums[first];
		nums[first]=nums[sec];
		nums[sec]=temp;
	}
	
	public static void moveZeores2(int[] nums){
		int newIndex=0;
		
		for(int i=0;i<nums.length;i++){
			if(nums[i]!=0){
				nums[newIndex]=nums[i];
				newIndex++;
			}
		}
		
		for(;newIndex<nums.length;newIndex++){
			nums[newIndex]=0;
		}
	}
	
	public static void main(String[] args){
		int a[]={0,13,0,1,0,2,0,3,12};
		
		moveZeores2(a);
		
		System.out.println(Arrays.toString(a));
	}
}
