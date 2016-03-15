package leetcode_Medium;

public class MaximumSubarray {
	/**
	 * global[i]��ȫ�����ţ���local[i]���ֲ����ţ�
	 * ��ô��i+1���ı��ʽ�ǣ�
local[i+1]=Math.max(A[i], local[i]+A[i])��
���Ǿֲ�������һ��Ҫ������ǰԪ�أ����Բ�Ȼ������һ���ľֲ�����local[i]+��ǰԪ��A[i]
����Ϊlocal[i]һ��������i��Ԫ�أ����Բ�Υ����������
�������local[i]�Ǹ��ģ���ô�������Ͳ��粻��Ҫ�ģ�
���Բ�Ȼ����ֱ����A[i]��

global[i+1]=Math(local[i+1],global[i])��
���˵�ǰһ���ľֲ����ţ���ôȫ�����ž��ǵ�ǰ�ľֲ����Ż��߻���ԭ����ȫ������
������������ᱻ���ǽ�������Ϊ���ŵĽ������������ǰԪ�أ�
��ôǰ��ᱻά����ȫ���������棬���������ǰԪ�أ���ô��������ֲ����ţ���
	 * @param nums
	 * @return
	 */
	public int maxSubArray(int[] nums) {
        if(nums==null || nums.length==0) return 0;
        int local=nums[0];
        int global=nums[0];
        for(int i=0;i<nums.length;i++){
        	local=Math.max(nums[i], local+nums[i]);
        	global=Math.max(local, global);
        }
        
        return global;
    }
	
	
	
	/*
	 * ��̬�滮���⣬��֪��ǰk��Ԫ�ص���������к�ΪmaxSub
	 *�Ѿ�����¼�����ˣ��Լ�һ����ʱ��sum���������˵�k+1���Ԫ�أ�����������������������ƣ�
	 * �������k+1���Ԫ��֮ǰ�ĺ���С��0�ģ���ô��������k+1���Ԫ�شӶ�ȥ��������������û�й��׵ģ�
	 * ���Կ��԰�sum ��0�� 
	 */
	public int maxSubArray2(int[] nums) {
		if (nums == null || nums.length < 1) {
            throw new IllegalArgumentException();
        }
		
		int max=Integer.MIN_VALUE;
		int curSum=0;
		
		for(int i:nums){
			// ��ǰ��С��0���ͽ���ǰֵ����curSum
			if(curSum<=0){
				curSum=i;
			}else{// ��������ۼ�
				curSum+=i;
			}
			// ����ϴ��ֵ
			if(max<curSum){
				max=curSum;
			}
		}
		return max;
    }
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

}
