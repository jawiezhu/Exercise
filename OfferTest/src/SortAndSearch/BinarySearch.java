package SortAndSearch;

public class BinarySearch {

	public static int binarysearch(int[] arr,int target){
		int len=arr.length;
		int L=0;
		int R=len-1;
		int mid=0;
		
		while(L<=R){
			mid=(L+R)/2;
			if(target<arr[mid]){
				R=mid-1;
			}else if(target>arr[mid]){
				L=mid+1;
			}else{
				return mid;
			}
		}
		return -1;
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int []arr={1,4,6,7,8,22};
		System.out.println(binarysearch(arr,6));
	}

}
