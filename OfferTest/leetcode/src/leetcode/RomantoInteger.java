package leetcode;

import java.util.HashMap;
import java.util.Map;

public class RomantoInteger {
	public int romanToInt(String s) {
        int res=0;
        Map<Character,Integer> map=new HashMap<Character,Integer>();
        map.put('I',1);
        map.put('V',5);
        map.put('X',10);
        map.put('L',50);
        map.put('C',100);
        map.put('D',500);
        map.put('M',1000);
        
        for(int i=s.length()-1;i>=0;i--){
        	if(i==s.length()-1){
        		res=map.get(s.charAt(i));
        		continue;
        	}
        	
        	if(map.get(s.charAt(i))>=map.get(s.charAt(i+1)))
        		res+=map.get(s.charAt(i));
        	else
        		res-=map.get(s.charAt(i));
        }
        
        return res;

    }
}
