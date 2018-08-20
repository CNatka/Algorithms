/*
    Author : CNatka
    Date   : Aug 14, 2018
    time.  : 8 min 10 sec
    OJ     : Leetcode/Climbing Stairs
    Link   : https://leetcode.com/problems/climbing-stairs/description/
*/

class Solution {
    public int climbStairs(int n) {
        int[] dp = new int[n+1];
        dp[0]=1;
        dp[1]=1;
        for(int i=2; i<=n; i++) {
            dp[i] = dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
}