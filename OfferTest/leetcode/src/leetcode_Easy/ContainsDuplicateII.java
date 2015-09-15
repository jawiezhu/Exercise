package leetcode_Easy;

import java.util.HashMap;
import java.util.Map;

public class ContainsDuplicateII {
	 public boolean containsNearbyDuplicate(int[] nums, int k) {
	        if(nums==null || nums.length<2 || k<1){
	        	return false;
	        }
	        
	        Map<Integer,Integer> map=new HashMap<Integer,Integer>();
	        for(int i=0;i<nums.length;i++){
	        	
	        	if(!map.containsKey(nums[i])){
	        		map.put(nums[i], i);
	        	}else{
	        		int value=map.get(nums[i]);
	        		if(i-value<=k){
	        			return true;
	        		}
	        		
	        		map.put(nums[i], i);
	        	}
	        }
	        
	        return false;
	 }
}
