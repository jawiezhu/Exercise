package leetcode_Easy;

import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;

public class IsomorphicStrings {
	 public boolean isIsomorphic(String s, String t) {
	        if(s==null && t==null){
	        	return true;
	        }else if(s==null || t==null){
	        	return false;
	        }else if(s.length()==0 && t.length()==0){
	        	return true;
	        }else if(s.length()!=t.length()){
	        	return false;
	        }
	        
	        Map<Character,Character> map=new HashMap<Character,Character>(s.length());
	        Set<Character> set=new HashSet<Character>(t.length());
	        char sChar;
	        char tChar;
	        
	        for(int i=0;i<s.length();i++){
	        	sChar=s.charAt(i);
	        	tChar=t.charAt(i);
	        	
	        	if(!map.containsKey(sChar)){
	        		if(set.contains(tChar)){
	        			return false;
	        		}else{
	        			map.put(s.charAt(i), t.charAt(i));
	        			set.add(tChar);
	        		}
	        	}else{
	        		// 原先的键映射的值是map.get(sChar)，现在要映射的值是tChar
	                // 如果两个值不相等，说明已经映射了两次，不符合，返回false
	        		if(map.get(sChar)!=tChar){
	        			return false;
	        		}
	        	}
	        }
	        return true;
	 }
}
