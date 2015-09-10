package OfferSolution;

public class LeftRotateString {
	public char[] Left(String s,int n){
		if(s!=null){
			int length=s.length();
			if(length>0 && n>0 && n<length){
				reverse(s.getBytes(),0,n-1);
				
				reverse(s.getBytes(),n,length-1);
				
				reverse(s.getBytes(),0,length-1);
				
			}
		}
		
		return s.toCharArray();
	}
	
	private void reverse(byte[] bs, int begin, int end) {
		// TODO Auto-generated method stub
		for(int i=0;i<(end-begin)/2;i++){
			char temp=(char) bs[begin+i];
			bs[begin+i]=bs[end-i-1];
			bs[end-i-1]=(byte) temp;
		}
	}
}
