/*
    Author : CNatka
    Date   : Aug 20, 2018
    OJ     : Contains Duplicate II
    Link   : https://leetcode.com/problems/contains-duplicate-ii/description/
    
*/

class Solution {
    private int min(int a, int b) {
        return a < b ? a : b;
    }
    public boolean containsNearbyDuplicate(int[] nums, int k) {
        int len = nums.length;
        for(int i=0; i<len-1; ++i) {
            int limit = min(i+k, len-1);
            for(int j=i+1; j<=limit; ++j) {
                if(nums[i] == nums[j]) return true;
            }
        }
        return false;
    }
}