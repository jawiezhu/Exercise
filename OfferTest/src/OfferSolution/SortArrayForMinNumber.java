package OfferSolution;

import java.util.Arrays;
import java.util.Comparator;

public class SortArrayForMinNumber {
	/*solution 1:  
     * if ab<ba,then a<b 
     * 1.sort the integer array. the comparator is "if ab<ba,then a<b" 
     * 2.append each integer in the array to create a string and that's the result. 
     */  
	public static String minNumFromIntArray(int[] x){
		String[] strs=stringOf(x);
		Arrays.sort(strs,new Comparator<String>(){
			public int compare(String o1,String o2){
				return (o1+o2).compareTo(o2+o1);
			}
		});
		
		StringBuilder sb=new StringBuilder();
		for(String each:strs){
			sb.append(each);
		}
		return sb.toString();
		
	}

	private static String[] stringOf(int[] x) {
		int len=x.length;
		String[] strs=new String[len];
		for(int i=0;i<len;i++){
			strs[i]=""+x[i];
		}
		return strs;
	}
	
	
	/*solution 2 
     * get all the permutations. 
     * find the min. 
     * Of course we use String instead of Big Integer. 
     */ 
	public static void minNumFromIntArray2(int[] x,int first,int last,AuxClass minStr){
		if(first==last){
			StringBuilder sb=new StringBuilder();
			for(int each:x){
				sb.append(each);
			}
			
			if(minStr.str==null){
				minStr.str=sb.toString();
			}else{
				if(minStr.str.compareTo(sb.toString())>0){
					minStr.str=sb.toString();
				}
			}
			return ;
		}
		
		
		for(int i=first;i<=last;i++){
			swap(x,first,i);
			minNumFromIntArray2(x,first+1,last,minStr);
			swap(x,first,i);
		}
	}
	
	private static void swap(int[] x, int first, int i) {
		// TODO Auto-generated method stub
		int temp=x[first];
		x[first]=x[i];
		x[i]=temp;
	}

	  /* 
     * when you use 'String' instead of inner class,you get 'null' all the time 
     */  
	static class AuxClass{
		String str;
	}
}
