package leetcode_Easy;

import java.util.Arrays;


public class ValidAnagram {
	
	
	public static boolean isAnagram(String s, String t) {
        if(s==null||t==null) return false;
        int cnts[]=new int[256];
        int cntt[]=new int[256];
        
        for(int i=0;i<256;i++){
        	cnts[i]=0;
        	cntt[i]=0;
        }
        
        for(int i=0;i<s.length();i++){
        	cnts[s.charAt(i)]+=1;
        }
        
        for(int i=0;i<t.length();i++){
        	cntt[t.charAt(i)]+=1;
        }
        
        for(int i=0;i<256;i++){
        	if(cntt[i]!=cnts[i])
        		return false;
        }
        
        return true;
    }
	
	//ох╪сты╪У
	public static boolean isAnagram2(String s, String t){
		int count[]=new int[26];
		for(int i=0;i<s.length();i++)
			count[s.charAt(i)-'a']++;
		for(int i=0;i<t.length();i++)
			count[t.charAt(i)-'a']--;
		
		for(int i=0;i<26;i++)
			if(count[i]!=0)
				return false;
		
		return true;
	}
	
	public boolean isAnagram3(String s, String t) 
	{
	    char[] sChar = s.toCharArray();
	    char[] tChar = t.toCharArray();

	    Arrays.sort(sChar);
	    Arrays.sort(tChar);

	    return Arrays.equals(sChar, tChar);   
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

}
