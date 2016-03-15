package leetcode_Easy;

import java.util.Arrays;
import java.util.HashMap;
import java.util.HashSet;
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
	
	
	public boolean containsDuplicate2(int[] nums) {

        for(int i = 0; i < nums.length; i++) {
            for(int j = i + 1; j < nums.length; j++) {
                if(nums[i] == nums[j]) {
                    return true;
                }
            }
        }
        return false;
    }
	
	public boolean containsDuplicate3(int[] nums) {

        Arrays.sort(nums);
        for(int ind = 1; ind < nums.length; ind++) {
            if(nums[ind] == nums[ind - 1]) {
                return true;
            }
        }
        return false;
    }
	
	public boolean containsDuplicate4(int[] nums) {
        if (nums.length == 0) return false;
        HashSet<Integer> appeared = new HashSet<Integer>();
        for(int n : nums) {
            if (!appeared.add(n)) return true;
        }
        return false;
    }
	
	
	public static void main(String[] args) {
		int[] arr={1,2,3,4,5,5,7};
		System.out.println(containsDuplicate(arr));
	}	

}
