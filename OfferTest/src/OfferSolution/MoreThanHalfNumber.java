package OfferSolution;

public class MoreThanHalfNumber {
	public int MoreThanHalfNum(int[] num){
		if(CheckInvalid(num))
			return 0;
		
		int res=num[0];
		int times=1;
		for(int i=1;i<num.length;i++){
			if(times==0){
				res=num[i];
				times=1;
			}else if(num[i]==res)
				times++;
			else
				times--;
		}
		
		if(!CheckMoreThanHalf(num,res))
			res=0;
		return res;
	}

	private boolean CheckMoreThanHalf(int[] num, int res) {
		// TODO Auto-generated method stub
		int times=0;
		for(int i=0;i<num.length;i++){
			if(num[i]==res)
				times++;
		}
		boolean isMoreThanHalf=true;
		if(times*2<=num.length){
			Invalid=true;
			isMoreThanHalf=false;
		}
		
		return isMoreThanHalf;
	}
	
	
	

	boolean Invalid=false;
	private boolean CheckInvalid(int[] num) {
		// TODO Auto-generated method stub
		Invalid=false;
		if(num==null||num.length<=0)
			Invalid=true;
		return Invalid;
	}
	
	
	public int MoreThan(int[] nums){
		if(CheckInvalid(nums))
			return 0;
		
		int middle=nums.length>>1;
		int start=0;
		int end=nums.length-1;
		int index=Partition(nums,nums.length,start,end);
		while(index!=middle){
			if(index>middle){
				end=index-1;
				index=Partition(nums,nums.length,start,end);
			}else
			{
				start=index+1;
				index=Partition(nums,nums.length,start,end);
			}
		}
		
		int res=nums[middle];
		if(!CheckMoreThanHalf(nums,res))
			res=0;
		return res;
	}

	private int Partition(int[] nums, int length, int start, int end) {
		// TODO Auto-generated method stub
		return 0;
	}
}
