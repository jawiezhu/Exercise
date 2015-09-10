package SortAndSearch;

import java.util.Arrays;

public class BubbleSort {
	
	public static void bubbleSort(int[] arr){
		//�����n-1�����򣬵�k����������k��Ԫ���������
		for(int i=0;i<arr.length-1;i++){
			//ÿһ��������Ҫ�Ƚ�n-i-1��
			//�Ե�ǰ��������arr[0......length-i-1]��������(j�ķ�Χ��������С��)
			for(int j=0;j<arr.length-1-i;j++){
				//���ϴ��Ԫ���Ƶ�����
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
