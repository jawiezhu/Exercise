package OfferSolution;

import java.util.LinkedList;
import java.util.List;

public class LastNumberInCircle {
	public static int lastRemain(int n,int m){
		if(n<1 ||m<1) return -1;
		
		List<Integer> list=new LinkedList<Integer>();
		for(int i=0;i<n;i++){
			list.add(i);
		}
		
		int idx=0;
		
		int start=0;
		
		while(list.size()>1){
			
			for(int i=1;i<m;i++){
				idx=(idx+1)%list.size();
			}
			
			list.remove(idx);
		}
		
		return list.get(0);
	}
	
	public static void main(String[] args){
		System.out.println(lastRemain(5,3));
	}
	
	
	
	public static int lastRemain_2(int n,int m){
		if(n<1||m<1) return -1;
		int last=0;
		for(int i=2;i<=n;i++){
			last=(last+m) %i;
		}
		return last;
	}
	
}
