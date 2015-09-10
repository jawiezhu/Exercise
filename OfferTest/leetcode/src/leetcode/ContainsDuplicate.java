package leetcode;

import java.util.HashMap;
import java.util.Map;

public class ContainsDuplicate {

	public static  boolean containsDuplicate(int[] nums) {
		if(nums==null||nums.length==0) return false;
        Map<Integer,Integer> map=new HashMap<Integer,Integer>();
        for(int i=0;i<nums.length;i++){
        	if(!map.containsKey(nums[i]))
        		map.put(nums[i], 1);
        	else
        		return true;	
        }
        
        return false;
    }
	
	public static void main(String[] args) {
		int[] arr={1,2,3,4,5,5,7};
		System.out.println(containsDuplicate(arr));
	}	

}
