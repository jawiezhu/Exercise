package leetcode_Medium;

import java.util.ArrayList;
import java.util.List;

public class ReverseWordsinaString {
	public String reverseWords(String s) {
        String tmp=new String();
        tmp=s.trim();
        s=s.trim();
        if(s==null||tmp.length()==0) return s;
        
        String[] str=s.split(" ");
        StringBuilder newstr=new StringBuilder();
        
       for(int i=str.length-1;i>=0;i--){
        	//System.out.println(str[i]);
        	str[i]=str[i].trim();
        	if(str[i].length()!=0){
        		System.out.println(str[i]);
        		newstr.append(str[i]);
            	newstr.append(" ");
        	}
       }
        
        newstr.deleteCharAt(newstr.length()-1);
        
        return newstr.toString();
    }
	
	public String reverseWords2(String s) {
	    String[] strs = s.split(" ");
	    List<String> words = new ArrayList<String>();
	    for (int i = strs.length - 1; i >= 0; i--) {
	        if (!strs[i].isEmpty()) {
	            words.add(strs[i]);
	        }
	    }
	    //return String.join(" ", words);
		return s;
	    
	    
	}
	
}
