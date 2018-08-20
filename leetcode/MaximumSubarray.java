/*
    Author : CNatka
    Date   : Aug 13, 2018
    time.  : 8 min 35 sec
    OJ     : Maximum Subarray
    Link   : https://leetcode.com/problems/maximum-subarray/description/
*/

class Solution {
    private int max(int a, int b) {
        return a>b?a:b;
    }
    public int maxSubArray(int[] nums) {
        int len = nums.length;
        if(len==0) return 0;
        int maxSum = nums[0];
        int[] mNums = new int[len];
        mNums[0] = nums[0];
        for(int i=1; i<len; i++) {
            int temp = mNums[i-1]+nums[i];
            if(temp > nums[i]) {
                maxSum = max(temp, maxSum);
                mNums[i] = temp;
            } else {
                mNums[i] = nums[i];
                maxSum = max(maxSum, nums[i]);
            }
        }
        return maxSum;
    }
}