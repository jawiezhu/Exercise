package SortAndSearch;

import java.util.Arrays;

public class MergeSort {
	
	public static void mergeSort(int[] arr,int left,int right){
		//ȡ�����������м�λ�õ��±꣬����һλ
		int mid=(left+right)>>1;
		
		if(left<right){
			//��ߵ�����ݹ�����
			mergeSort(arr,left,mid);
			//�ұߵ�����ݹ�����
			mergeSort(arr,mid+1,right);
			//�ϲ��Ѿ��ź��������
			merge(arr,left,mid,right);
		}
		
		System.out.println(Arrays.toString(arr));
	}
	
	
	
	private static void merge(int[] arr, int left, int mid, int right) {
		//������ʱ����
		int[] temp=new int[right-left+1];
		//��������±�ָ��
		int l=left;
		//�ұ������±�ָ��
		int r=mid+1;
		//��ʱ������±�ָ��
		int index=0;
		
		//���������ߵ�������ѡȡ��С����
		//������ʱ������ 
		//ֱ��ѡ������һ�������Ԫ��
		while(l<=mid && r<=right){
			if(arr[l]<arr[r]){
				temp[index++]=arr[l++];
			}else{
				temp[index++]=arr[r++];
			}
		}
		
		//���������ʣ���Ԫ�ظ��Ƶ���ʱ������
		while(l<=mid){
			temp[index++]=arr[l++];
		}
		
		//���ұ�����ʣ���Ԫ�ظ��Ƶ���ʱ������
		while(r<=right){
			temp[index++]=arr[r++];
		}
		
		//����ʱ�����е�Ԫ�ظ��Ƶ�ԭ����������
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
