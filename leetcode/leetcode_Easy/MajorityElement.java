package leetcode_Easy;

public class MajorityElement {
	public int majorityElement(int[] nums){
		if(nums==null) return 0;
		int cnt=0;
		while(true){
			if(nums.length==1) 
				return nums[0];
			else{
				int i=(int) (Math.random()*(nums.length-1));
				for(int j=0;j<nums.length;j++){
					if(nums[j]==nums[i])
						cnt++;
				}
				if(cnt>(nums.length/2))
					return nums[i];
				else{
					cnt=0;
					continue;
				}
			}
			
		}
	}
	
	// Moore voting algorithm
	public int majorityElement3(int[] nums) {
	    int count=0, ret = 0;
	    for (int num: nums) {
	        if (count==0)
	            ret = num;
	        if (num!=ret)
	            count--;
	        else
	            count++;
	    }
	    return ret;
	}

}
