package OfferSolution;

public class ReplaceBlank {
	
	public static String ReplaceBlank(String s){
		if(s==null) return null;
		
		StringBuilder str=new StringBuilder();
		int begin=0;
		for(int i=0;i<s.length();i++)
		{
			if(s.charAt(i)==' '){
				str.append(s.substring(begin, i)+"%20");
				begin=i+1;
			}
			if(i==s.length()-1)
			{
				str.append(s.substring(begin, i+1));
			}
			
		}
		return str.toString();
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		System.out.println(ReplaceBlank("azhu     !"));

	}

}
