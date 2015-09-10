package SortAndSearch;

import java.util.Arrays;

public class InsertionSort {

	public static void insertSort(int[] arr){
		// ��Ϊ��һ��Ԫ���Ѿ����򣬴ӵڶ���Ԫ�ؿ�ʼȡֵ�����Ѿ�����Ĳ���
		for(int i=1;i<arr.length;i++){
			//�������Ԫ��
			int key=arr[i];
			//�������λ���±�
			int index=i;
			// �Ӻ���ǰ���������Ѿ�����Ĳ��֣�Ѱ�Һ��ʵĲ���λ��
			for(int j=i-1;j>=0;j--){
				// ����������Ԫ�ؽ�С���򽫽ϴ��Ԫ����������ƶ����ճ����ʵĲ���λ��
				if(arr[j]>key){
					// ��Ϊarr[j+1]=arr[i]=key����Ԫ���Ѿ���ʱ�洢����key�У����Բ���������ݶ�ʧ
					arr[j+1]=arr[j];
					// ��¼�¸�λ�õ��±�
					index=j;
				}else{
					// �ҵ��˺��ʵĲ���λ�ã����˳����ѭ������ʼȡ��һ��Ԫ�أ�ֱ��ȡ������Ԫ��
					break;
				}
			}
			// ����Ԫ�ز��뵽���ʵ�λ��
			arr[index]=key;
		}
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int[] arr={88,3,7,1,2,11,0};
		insertSort(arr);
		System.out.println(Arrays.toString(arr));
	}

}
