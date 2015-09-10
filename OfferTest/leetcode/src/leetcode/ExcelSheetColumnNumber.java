package leetcode;

public class ExcelSheetColumnNumber {
	 public int titleToNumber(String s) {
	      int num=0;
	      for(int i=0;i<s.length();i++){
	    	  num=(int) (num+Math.pow(26, i)*(s.charAt(s.length()-i-1)-64));
	      }
	      
	      return num;
	 }
}
