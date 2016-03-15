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
	
	
	public boolean isPalindrome2(String s) {

		   if(s == null || s.length() == 0 || s.length() == 1){
		       return true;
		   }

		    int left = 0;
		    int right = s.length() - 1;
		    s = s.toLowerCase();

		    while(left < right){
		        if(!Character.isLetterOrDigit(s.charAt(left))){
		            left++;
		        }else if(!Character.isLetterOrDigit(s.charAt(right))){
		            right--;
		        }else if(s.charAt(left) != s.charAt(right)){
		            return false;
		        }else{
		            left++;
		            right--;
		        }

		    }

		    return true;
		}
	
	
}
