package OfferSolution;

public class InversePairs {

//	���ù鲢�����˼�룬����ǰ��һ����������������������һ���������������
//	Ȼ����ǰ��һ������Ⱥ���һ�������д�����ĸ�����Ҳ�����������������������̼��������������������Ŀ�ˡ�
//
//	�״�㣺�ڶ��������ڹ鲢ʱ����Ҫarray�����������������ź�������飬
//	�鲢�Ľ���ǵõ��ź��������copy������ڵݹ����iPairsʱ��
//	������ǰ2�������ǵߵ��ģ������õ���array�����ź���ġ�
//
//	�����һ��ʱ��copy�����������array���򣬵ڶ��ξ����÷�������
	
	public static int iPairs(int[] array){
		if(array==null)
			throw new IllegalArgumentException();
		
		//������������
		int length=array.length;
		int[] copy=new int[length];
		System.arraycopy(array, 0,copy,0, length);
		int numberOfInversePairs=iPairs(array,copy,0,length-1);
		return numberOfInversePairs;
	}

	/**
	 * 
	 * @param array δ�鲢����
	 * @param copy ���ڴ洢�鲢�����ݵ�����
	 * @param begin ��ʼλ��
	 * @param end ����λ��
	 * @return
	 */
	private static int iPairs(int[] array, int[] copy, int begin, int end) {
		if(begin==end) return 0;
		int mid=(begin+end)/2;
		
		int left=iPairs(copy,array,begin,mid);
		int right=iPairs(copy,array,mid+1,end);
		
		int i=mid;
		int j=end;
		int pos=end;
		int count=0;
		
		while(i>=begin && j>=mid+1){
			if(array[i]>array[j]){
				copy[pos--]=array[i--];
				count+=j-mid;
			}else
				copy[pos--]=array[j--];
		}
		
		while(i>=begin)
			copy[pos--]=array[i--];
		while(j>=mid+1)
			copy[pos--]=array[j--];
		
		return left+right+count;
	}
}
