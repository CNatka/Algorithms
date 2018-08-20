/*
    Author : CNatka
    Date   : Aug 20, 2018
    OJ     : House Robber
    Link   : https://leetcode.com/problems/house-robber/description/
    
*/

class Solution {
    private int max(int a, int b) {
        return a > b ? a : b;
    }
    public int rob(int[] nums) {
        int len = nums.length;
        if(len == 0) return 0;
        int[] dp = new int[len];
        dp[0] = nums[0];
        int maxProfit = dp[0];
        for(int i=1; i<len; i++) {
            if(i<2) dp[i] = max(dp[i-1], nums[i]);
            else dp[i] = max(dp[i-1], dp[i-2]+nums[i]);
            maxProfit = max(dp[i], maxProfit);
        }
        return maxProfit;
    }
}