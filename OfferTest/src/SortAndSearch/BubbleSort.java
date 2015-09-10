package SortAndSearch;

import java.util.Arrays;

public class BubbleSort {
	
	public static void bubbleSort(int[] arr){
		//最多做n-1趟排序，第k趟排序后，最后k个元素是有序的
		for(int i=0;i<arr.length-1;i++){
			//每一趟排序需要比较n-i-1次
			//对当前无序区间arr[0......length-i-1]进行排序(j的范围是在逐步缩小的)
			for(int j=0;j<arr.length-1-i;j++){
				//将较大的元素移到后面
				if(arr[j]>arr[j+1]){
					int temp=arr[j];
					arr[j]=arr[j+1];
					arr[j+1]=temp;
				}
			}
		}
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int[] arr={88,3,7,1,2,11,0};
		bubbleSort(arr);
		System.out.println(Arrays.toString(arr));
	}

}
