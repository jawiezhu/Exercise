package OfferSolution;

public class NumberAppearOnce {
	public void FindNumAppearOnce(int arr[],int length,int num1,int num2){
		if(arr==null||length<2) return ;
		
		int resultExclusiveOR=0;
		for(int i=0;i<length;i++)
			resultExclusiveOR^=arr[i];
		
		int indexOF1=FindFirstBitIs1(resultExclusiveOR);
		
		num1=0;
		num2=0;
		for(int j=0;j<length;j++){
			if(IsBit1(arr[j],indexOF1)){
				num1^=arr[j];
			}else
				num2^=arr[j];
		}
	}

	private boolean IsBit1(int num, int indexBit) {
		// TODO Auto-generated method stub
		num=num>>indexBit;
		return (num & 1)==1;
	}

	private int FindFirstBitIs1(int num) {
		// TODO Auto-generated method stub
		int indexBit=0;
		while(((num&1)==0)&&(indexBit<8*4)){
			num=num>>1;
			++indexBit;
		}
		return indexBit;
	}
}
