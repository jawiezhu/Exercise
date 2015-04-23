// Say you have an array for which the ith element is the price of a given stock on day i.

// If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), 
// design an algorithm to find the maximum profit.
// 给一个数prices[]，prices[i]代表股票在第i天的售价，求出只做一次交易(一次买入和卖出)能得到的最大收益。

// 只需要找出最大的差值即可，即 max(prices[j] – prices[i]) ，i < j。
// 一次遍历即可，在遍历的时间用遍历low记录 prices[o....i] 中的最小值，
// 就是当前为止的最低售价，时间复杂度为 O(n)。
class Solution {
public:
    int maxProfit(vector<int>& prices) {
    	if(prices.size()==0) return NULL;
        int low=prices[0];
        int ans=0;
        for(int i=0;i<prices.size();i++)
        {
        	if(prices[i]<low)
        		low=prices[i];
        	else if(prices[i]-low>ans)
        		ans=prices[i]-low;

        }
		return ans;
    }
};


//用类似动态规划的思想，到第i天买入，
//那么我能赚到的最大利润是多少呢？就是i + 1 ~ n天中最大的股价减去第i天的。
//找最大股价的问题可以在找第i+1~n天的最大利润时顺便记录，
//这样就得出了一个线性方法。
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (prices.size() == 0)
            return 0;
            
        int maxPrice = prices[prices.size()-1];
        int ans = 0;
        for(int i = prices.size() - 1; i >= 0; i--)
        {
            maxPrice = max(maxPrice, prices[i]);
            ans = max(ans, maxPrice - prices[i]);
        }
        
        return ans;
    }
};


//顺序扫描股票价格，找到股票价格的第一个上升区间，
//以区间最低价买入，最高价卖出，后面扫描到上升区间时，根据区间的边界更新最低价和最高价
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int len = prices.size();
        if(len <= 1)return 0;
        int i = 0;
        int ibuy = 0, isell = 0, leastBuy = 0; //leastBuy为前面已经扫描过的最低价格
        bool setted = false;
        while(i < len - 1)
        {
            int buy, sell;
            while(i+1 < len && prices[i+1] < prices[i])i++;//递减区间
            buy = i++;

            while(i < len && prices[i] >= prices[i-1])i++;//递增区间
            sell = i-1;
            //此时从prices[buy]~prices[sell]是递增区间

            if(prices[buy] <= prices[ibuy])
            {
                if(prices[sell] - prices[buy] >= prices[isell] - prices[ibuy])
                {
                    ibuy = buy;
                    isell = sell;
                }
            }
            else
            {
                if(prices[sell] > prices[isell])
                    isell = sell;
            }
            if(prices[buy] > prices[leastBuy])
                ibuy = leastBuy;

            if(prices[leastBuy] > prices[buy])leastBuy = buy;
        }
        return prices[isell] - prices[ibuy];
    }
};


// 设dp[i]是[0,1,2...i]区间的最大利润，则该问题的一维动态规划方程如下

// dp[i+1] = max{dp[i], prices[i+1] - minprices}  ,minprices是区间[0,1,2...,i]内的最低价格

// 我们要求解的最大利润 = max{dp[0], dp[1], dp[2], ..., dp[n-1]} 代码如下：

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int len = prices.size();
        if(len <= 1)return 0;
        int res = prices[1] - prices[0], minprice = prices[0];
        for(int i = 2; i < len; i++)
        {
            minprice = min(prices[i-1], minprice);
            if(res < prices[i] - minprice)
                res = prices[i] - minprice;
        }
        if(res < 0)return 0;
        else return res;
    }
};


//按照股票差价构成新数组 prices[1]-prices[0], prices[2]-prices[1],
// prices[3]-prices[2], ..., prices[n-1]-prices[n-2]。求新数组的最大子段和就是我们求得最大利润，
//假设最大子段和是从新数组第 i 到第 j 项，
//那么子段和= prices[j]-prices[j-1]+prices[j-1]-prices[j-2]+...+prices[i]-prices[i-1] = prices[j]-prices[i-1], 
//即prices[j]是最大价格，prices[i-1]是最小价格，且他们满足前后顺序关系。代码如下：
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int len = prices.size();
        if(len <= 1)return 0;
        int res = 0, currsum = 0;
        for(int i = 1; i < len; i++)
        {
            if(currsum <= 0)
                currsum = prices[i] - prices[i-1];
            else
                currsum += prices[i] - prices[i-1];
            if(currsum > res)
                res = currsum;
        }
        return res;
    }
};
