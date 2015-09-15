package leetcode_Easy;

public class ValidPalindrome {
	public boolean isPalindrome(String s) {
		if(s==null||s.length()==0) return true;
		 
		s = s.replaceAll("[^a-zA-Z0-9]", "").toLowerCase();
		System.out.println(s);
 
		for(int i = 0; i < s.length() ; i++){
			if(s.charAt(i) != s.charAt(s.length() - 1 - i)){
				return false;
			}
		}
 
		return true;
    }
}
