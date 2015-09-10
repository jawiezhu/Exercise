package OfferSolution;

public class InversePairs {

//	利用归并排序的思想，先求前面一半数组的逆序数，再求后面一半数组的逆序数，
//	然后求前面一半数组比后面一半数组中大的数的个数（也就是逆序数），这三个过程加起来就是整体的逆序数目了。
//
//	易错点：第二个方法在归并时，需要array的左右子数组是已排好序的数组，
//	归并的结果是得到排好序的数组copy。因此在递归调用iPairs时，
//	方法的前2个参数是颠倒的，这样得到的array才是排好序的。
//
//	比如第一次时用copy当辅助数组对array排序，第二次就正好反过来。
	
	public static int iPairs(int[] array){
		if(array==null)
			throw new IllegalArgumentException();
		
		//创建辅助数组
		int length=array.length;
		int[] copy=new int[length];
		System.arraycopy(array, 0,copy,0, length);
		int numberOfInversePairs=iPairs(array,copy,0,length-1);
		return numberOfInversePairs;
	}

	/**
	 * 
	 * @param array 未归并数组
	 * @param copy 用于存储归并后数据的数组
	 * @param begin 起始位置
	 * @param end 结束位置
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
