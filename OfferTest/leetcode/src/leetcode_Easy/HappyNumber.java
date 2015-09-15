package leetcode_Easy;

import java.util.HashSet;

public class HappyNumber {
	public boolean isHappy(int n) {
        if(n<1) return false;
        
        HashSet<Integer> set=new HashSet<Integer>();
        
        int tmp;
        int newN;
        
        while(n!=1 && !set.contains(n)){
        	set.add(n);
        	newN=0;
        	while(n>0){
        		tmp=n%10;
        		n/=10;
        		newN+=tmp*tmp;
        	}
        	n=newN;
        }
        
        return n==1;
    }
}
