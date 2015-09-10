package OfferSolution;

public class KLeastNumbers {
	public void GetLeastNumbers(int input[],int output[],int k){
		
		if(input==null||output==null||k>input.length||k<=0)
			return;
		
		//int middle=nums.length>>1;
		int start=0;
		int end=input.length-1;
		int index=Partition(input,input.length,start,end);
		while(index!=k-1){
			if(index>k-1){
				end=index-1;
				index=Partition(input,input.length,start,end);
			}else
			{
				start=index+1;
				index=Partition(input,input.length,start,end);
			}
		}
		
		for(int i=0;i<k;i++)
			output[i]=input[i];
	}

	private int Partition(int[] input, int length, int start, int end) {
		// TODO Auto-generated method stub
		return 0;
	}
}
