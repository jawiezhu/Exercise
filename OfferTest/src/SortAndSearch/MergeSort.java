package SortAndSearch;

import java.util.Arrays;

public class MergeSort {
	
	public static void mergeSort(int[] arr,int left,int right){
		//取待排序数组中间位置的下标，右移一位
		int mid=(left+right)>>1;
		
		if(left<right){
			//左边的数组递归排序
			mergeSort(arr,left,mid);
			//右边的数组递归排序
			mergeSort(arr,mid+1,right);
			//合并已经排好序的数组
			merge(arr,left,mid,right);
		}
		
		System.out.println(Arrays.toString(arr));
	}
	
	
	
	private static void merge(int[] arr, int left, int mid, int right) {
		//创建临时数组
		int[] temp=new int[right-left+1];
		//左边数组下标指针
		int l=left;
		//右边数组下标指针
		int r=mid+1;
		//临时数组的下标指针
		int index=0;
		
		//在左右两边的数组中选取较小的数
		//放入临时数组中 
		//直到选完至少一个数组的元素
		while(l<=mid && r<=right){
			if(arr[l]<arr[r]){
				temp[index++]=arr[l++];
			}else{
				temp[index++]=arr[r++];
			}
		}
		
		//把左边数组剩余的元素复制到临时数组中
		while(l<=mid){
			temp[index++]=arr[l++];
		}
		
		//把右边数组剩余的元素复制到临时数组中
		while(r<=right){
			temp[index++]=arr[r++];
		}
		
		//将临时数组中的元素复制到原来的数组中
		for(int i=0;i<temp.length;i++){
			arr[i+left]=temp[i];
		}
		
		
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int[] arr={88,3,7,1,2,11,0};
		mergeSort(arr,0,arr.length-1);
		
	}

}
