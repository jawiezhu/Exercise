package leetcode_Easy;

import java.util.ArrayList;
import java.util.List;

public class PascalsTriangle {

	public List<List<Integer>> generate(int numRows) {
        List<List<Integer>> res=new ArrayList<List<Integer>>();
        if(numRows<=0)
        	return res;
        
        List<Integer> pre=new ArrayList<Integer>();
        pre.add(1);
        res.add(pre);
        
        for(int i=2;i<=numRows;i++){
        	List<Integer> cur=new ArrayList<Integer>();
        	
        	cur.add(1);
        	for(int j=0;j<pre.size()-1;j++){
        		cur.add(pre.get(j)+pre.get(j+1));
        	}
        	cur.add(1);
        	
        	res.add(cur);
        	pre=cur;
        	
        }
        
        return res;
    }

}
