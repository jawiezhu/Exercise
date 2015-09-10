package leetcode;

import java.util.HashMap;
import java.util.Map;

public class RemoveElement {
	public int removeElement(int[] nums,int val){
		if(nums==null) return 0;
		int cnt=0;
		for(int i=0;i<nums.length;i++){
			if(val==nums[i])
				cnt++;
			else if(cnt>0){
				nums[i-cnt]=nums[i];
			}
		}
		return nums.length-cnt;
	}
}
