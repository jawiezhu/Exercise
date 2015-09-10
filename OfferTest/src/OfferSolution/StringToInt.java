package OfferSolution;

public class StringToInt {
	public static int atoi(String s){
		if(s==null || s.length()<1) return 0;
		
		s=s.trim();
		char flag='+';
		
		int i=0;
		if(s.charAt(0)=='-'){
			flag='-';
			i++;
		}else if(s.charAt(0)=='+'){
			i++;
		}
		
		double res=0;
		
		while(s.length()>i && s.charAt(i)>='0' && s.charAt(i)<='9'){
			res=res*10+(s.charAt(i)-'0');
			i++;
		}
		
		if(flag=='-')
			res=-res;
		
		if(res>Integer.MAX_VALUE)
			return Integer.MAX_VALUE;
		if(res<Integer.MIN_VALUE)
			return Integer.MIN_VALUE;
		
		return (int) res;
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		System.out.println(atoi("-0012a42"));
	}

}
