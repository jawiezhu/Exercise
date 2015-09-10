package leetcode;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;

//两个指针 start, end.  如果nums[end+1] = nums[end]+1, 
//就移动end指针, 否则, 插入字符串nums[start]->nums[end]. 
public class SummaryRanges {
	
	
	public static List<String> summaryRanges(int[] nums) {
        
		List<String> ls=new LinkedList<String>();
		
		if(nums==null||nums.length<1) return ls;
		
		int s=0;
		for(int e=0;e<nums.length;){
			
			if(e<nums.length-1&&nums[e+1]-nums[e]==1){
				e++;
				
			}else{
				if(s==e){
					ls.add(getRange(nums[s],nums[s]));
				}else{
					ls.add(getRange(nums[s],nums[e]));
				}
				e++;
				s=e;
			}
			
		}
		return ls;
		
    }
	
	private static String getRange(int from,int to){
		String s=new String();
		if(from==to){
			s=String.valueOf(from);
		}else
			s=from+"->"+to;
		
		return s;
	}
	
	public static List<String> summaryRanges2(int[] nums) {  
        List<String> res = new ArrayList<String>();  
        if(nums==null || nums.length<1) return  res;  
          
        int s=0, e=0;  
        while(e<nums.length) {  
        	System.out.println(nums[e]);
            if(e+1<nums.length && nums[e+1]==nums[e]+1) {  
                e++;  
                //System.out.println(e);
            } else {  
            	
                if(s==e) {  
                    res.add(Integer.toString(nums[s]));  
                } else {  
                    String str = nums[s] + "->" + nums[e];  
                    res.add(str);  
                }  
                ++e;  
                s = e;  
            }  
        }  
        return res;  
    }  
	
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int [] a={1,3,4,6,7,8,9,20};
		System.out.println(summaryRanges2(a));
		System.out.println(summaryRanges(a));
	}

}
