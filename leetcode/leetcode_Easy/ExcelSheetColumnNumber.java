package leetcode_Easy;

public class ExcelSheetColumnNumber {
	 public int titleToNumber(String s) {
	      int num=0;
	      for(int i=0;i<s.length();i++){
	    	  num=(int) (num+Math.pow(26, i)*(s.charAt(s.length()-i-1)-64));
	      }
	      
	      return num;
	 }
	 
	 public int titleToNumber2(String s) {
		    int result = 0;
		    for(int i = 0 ; i < s.length(); i++) {
		      result = result * 26 + (s.charAt(i) - 'A' + 1);
		    }
		    return result;
		  }
}
