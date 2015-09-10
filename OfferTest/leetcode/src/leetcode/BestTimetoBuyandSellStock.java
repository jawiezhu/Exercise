package leetcode;

public class BestTimetoBuyandSellStock {
	
	public int maxProfit(int[] prices) {
		if(prices==null||prices.length<1) return 0;
        int low=Integer.MAX_VALUE;
        int res=0;
        
        for(int i=0;i<prices.length;i++){
        	low=Math.min(low, prices[i]);
        	res=Math.max(res,prices[i]-low);
        }
        
        return res;
    }
	

}
