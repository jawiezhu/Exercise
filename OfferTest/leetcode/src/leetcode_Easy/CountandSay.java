package leetcode_Easy;

public class CountandSay {
	public String countAndSay(int n) {
        if(n<1) return null;
        String res="1";
        for(int i=2;i<=n;i++){
        	res=countAndSay(res);
        }
        
        return res;
    }

	private String countAndSay(String str) {
		// TODO Auto-generated method stub
		StringBuilder builder=new StringBuilder(128);
		int count=1;
		for(int i=1;i<str.length();i++){
			if(str.charAt(i)==str.charAt(i-1)){
				count++;
			}else{
				builder.append(count);
				builder.append(str.charAt(i-1));
				count=1;
			}
		}
		
		builder.append(count);
		builder.append(str.charAt(str.length()-1));
		
		return builder.toString();
	}
}
