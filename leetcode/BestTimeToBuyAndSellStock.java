/*
    Author : CNatka
    Date   : Aug 19, 2018
    OJ     : Best Time to Buy and Sell Stock
    Link   : https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/
    
*/

class Solution {
    private int max(int a, int b) {
        return a > b ? a : b;
    }
    public int maxProfit(int[] prices) {
        int len = prices.length;
        if(len==0) return 0;
        int maxTillNow = prices[len-1];
        int profit = 0;
        for(int i=len-2; i>=0; i--) {
            if(prices[i]<=maxTillNow) {
                profit = max(profit, maxTillNow-prices[i]);
            }
            maxTillNow = max(maxTillNow, prices[i]);
        }
        return profit;
    }
}