package leetcode_Easy;



public class RotateArray {

	public static void rotate(int[] nums, int k) {
		if(nums==null||k<0) return;
		k = (nums.length + (k % nums.length)) % nums.length;
		
        int	[] temp=new int[k];
        int j=0;
        if(k<nums.length){
        	for(int i=nums.length-k;i<nums.length;i++){
            	temp[j]=nums[i];
            	j++;
            }
            
            for(int i=nums.length-k-1;i>=0;i--){
            	nums[i+k]=nums[i];
            }
           
            for(int i=0;i<temp.length;i++){
            	nums[i]=temp[i];
            }
        }else{
        	return;
        }
        
     
    }
	
	
	//�Ƚ�kת����[0, n-1]�ڵ������ٶ�����������з�ת��
	//�ٶ�[0, k-1]λ�õ����ֽ��з�ת���ٶ�ʣ�µĲ��ֽ��з�ת��
	public static void rotate2(int[] nums, int k) {
		k=(nums.length+(k%nums.length))%nums.length;
		
		int tmp;
		for(int i=0,j=nums.length-1;i<j;i++,j--){
			tmp=nums[j];
			nums[i]=nums[j];
			nums[j]=tmp;
		}
		
		for(int i=0,j=k-1;i<j;i++,j--){
			tmp=nums[i];
			nums[i]=nums[j];
			nums[j]=tmp;
		}
		
		for(int i=k,j=nums.length-1;i<j;i++,j--){
			tmp=nums[i];
			nums[i]=nums[j];
			nums[j]=tmp;
		}
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int[] arr={1,2};
		rotate(arr,3);
	}

}
