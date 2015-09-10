package sort;

import java.util.Arrays;

public class BubbleSort1 {
	public static void main(String[] args){
		int []arr={9,8,7,6,5};
		bubblesort2(arr);
		int []a={9,1,2,3,4};
		bubblesort3(a);
		
		String[] str={"a","abcd","abc","def"};
		boolean sorted=true;
		int len=str.length;
		for(int j=0;j<len-1;j++){
			sorted=true;
			for(int i=0;i<len-1-j;i++){
				if(((Comparable)str[i]).compareTo(str[i+1])>0){
					String temp=str[i];
					str[i]=str[i+1];
					str[i+1]=temp;
					sorted=false;
				}
				System.out.println(Arrays.toString(str));
			}
			if(sorted)
				break;
		}
	}
	
	
	//bubblesort v1
	public static void bubblesort1(int[] arr){
//		for(int j=arr.length-1;j>0;j--)
		for(int j=0;j<arr.length-1;j++)
		{
			for(int i=0;i<arr.length-1;i++)//û��Ҫ�Ƚ���ô���
			{
				if(arr[i]>arr[i+1]){
					Integer a=arr[i];
					Integer b=arr[i+1];
					final Swap<Integer> s=new Swap<Integer>(a,b);
					arr[i]=s.getA();
					arr[i+1]=s.getB();
				}
			}
			System.out.println(Arrays.toString(arr));
		}
		
	}
	
	//bubblesort v2 ��Щ�ȽϹ������ٱȽϴ���
	public static void bubblesort2(int[] arr){
//		for(int j=arr.length-1;j>0;j--)
		for(int j=0;j<arr.length-1;j++)
		{
			for(int i=0;i<arr.length-1-j;i++)//ÿһ�� ��ȥ j������
			{
				if(arr[i]>arr[i+1]){
					Integer a=arr[i];
					Integer b=arr[i+1];
					final Swap<Integer> s=new Swap<Integer>(a,b);
					arr[i]=s.getA();
					arr[i+1]=s.getB();
				}
			}
			System.out.println(Arrays.toString(arr));
		}
		
	}
	
	//bubblesort vfinal ������������
	public static void bubblesort3(int[] arr){
		boolean sorted=true;
		int len=arr.length;
		for(int j=0;j<len-1;j++){
			 sorted=true;//�ٶ�����
			 for(int i=0;i<len-1-j;i++){
				 if(arr[i]>arr[i+1]){
						Integer a=arr[i];
						Integer b=arr[i+1];
						final Swap<Integer> s=new Swap<Integer>(a,b);
						arr[i]=s.getA();
						arr[i+1]=s.getB();
						sorted=false;
					}
				 System.out.println(Arrays.toString(arr));
			 }
			 if(sorted){
				 break;
			 }
		}
	}
	

}

class Swap<T>{
	private final T a;
	private final T b;
	public Swap(T a,T b){
		this.a=b;
		this.b=a;
	}
	
	public T getA(){
		return a;
	}
	
	public T getB(){
		return b;
	}
}
