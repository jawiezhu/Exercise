package OfferSolution;

import java.util.Arrays;

public class DuplicationInArray {
	public static boolean duplicate(int arr[]){
		
		int cnt=0;
		int []dup=new int[arr.length-1];
		if(arr==null) return false;
		
		
		// �ж�������Ƿ���[0, number.length-1]֮��
		for(int i=0;i<arr.length-1;i++){
			if(arr[i]<0||arr[i]>arr.length-1)
				return false;
		}
		
		for(int i=0;i<arr.length-1;i++){
			// ��number[i]��i����ͬ��ʱ��һֱ����
			while(arr[i]!=i){
				
				 // ���iλ����number[i]λ�õ�������ͬ��˵�����ظ�����
				if(arr[i]==arr[arr[i]]){
					System.out.println(arr[i]);
					return true;
				}else{
					// �����ͬ�ͽ���
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
