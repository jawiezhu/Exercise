package leetcode;

public class StringtoInteger {
	
	
	public static int myAtoi(String str) {
		if(str==null||str.length()<1) return 0;
		str=str.trim();
		double res=0;
		char flag='0';
		
		int i=0;
		
			if(str.charAt(i)=='-')
			{
				flag='-';i++;
			}else if(str.charAt(i)=='+'){
				flag='+';i++;
			}
	
		
		
		
//		if(str.charAt(i)>='0'&&str.charAt(i)<='9'){
//			for(;i<str.length();i++)
//			{
//				//System.out.println(str.charAt(i));
//				if(!Character.isDigit(str.charAt(i)))
//					break;
//				res=res*10+(str.charAt(i)-'0');
//			}
//		}
		
		while(i<str.length() && str.charAt(i)>='0' &&str.charAt(i)<='9')
		{
			res=res*10+(str.charAt(i)-'0');
			i++;
		}
	
			
		
		if(flag=='-')
			res=-res;
		else
			res=res;
		
		if(res>Integer.MAX_VALUE)
			return Integer.MAX_VALUE;
		if(res<Integer.MIN_VALUE)
			return Integer.MIN_VALUE;
		
		return (int)res;
    }
	
	
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		System.out.println(myAtoi("-0012a42"));
	}

}
