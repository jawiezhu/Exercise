package leetcode_Medium;

import java.util.Arrays;
import java.util.HashMap;
import java.util.Iterator;
import java.util.Map;

public class SingleNumberIII {
	public static int[] singleNumber(int[] nums){
		
		if(nums.length<=0 || nums==null) return null;
		
		Map<Integer,Integer> map=new HashMap<Integer,Integer>();
		int[] res=new int[2];
		for(int i=0;i<nums.length;i++){
			if(map.containsKey(nums[i]))
				map.put(nums[i], 2);
			else{
				map.put(nums[i],1);
			}
		}
		//System.out.println(map.toString());
		Iterator iter=map.entrySet().iterator();
		int i=0;
		while(iter.hasNext()){
			Map.Entry<Integer, Integer>entry=(Map.Entry<Integer, Integer>) iter.next();
			if(entry.getValue()==1){
				res[i]=entry.getKey();
				i++;
			}
		}
		
		return res;
	}
	
	
	public static void main(String[] args){
		int [] a={1,2,1,3,2,5};
		System.out.println(Arrays.toString(singleNumber2(a)));
	}
	
	
	
	
	public static int[] singleNumber2(int[] nums){
		int []res=new int[2];
		int result=nums[0];
		for(int i=1;i<nums.length;i++){
			result=result ^ nums[i];
			System.out.println(result);
		}
			
		
		System.out.println(result);
		
		
		res[0]=0;
		res[1]=0;
		int n=result & (~(result-1));
		
		System.out.println(n);
		for(int i=0;i<nums.length;i++){
			int tmp=n&nums[i];
			System.out.println("n&nums[i]("+nums[i]+")"+":"+tmp);
			if((n&nums[i])!=0){
				res[0]=res[0]^nums[i];
				System.out.println(res[0]);
			}
			else{
				res[1]=res[1]^nums[i];
				System.out.println(res[0]);
			}
				
		}
		
		return res;
	}
}
