package leetcode_Easy;

public class UglyNumber {
	
	public boolean isUgly(int num){
		if(num==0) return false;
		if(num==1) return true;
		while(num%2==0)
			num=num/2;
		while(num%3==0)
			num=num/3;
		while(num%5==0)
			num=num/5;
		if(num!=1)  return false;
		return true;
		
	}
	
	
	public boolean isUgly2(int num) {
	    if (num <= 0) {return false;}
	    if (num == 1) {return true;}
	    if (num % 2 == 0) {
	        return isUgly(num/2);
	    }
	    if (num % 3 == 0) {
	        return isUgly(num/3);
	    }
	    if (num % 5 == 0) {
	        return isUgly(num/5);
	    }
	    return false;
	}

}
