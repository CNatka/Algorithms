/*
    Author : CNatka
    Date   : Aug 20, 2018
    OJ     : Majority Element
    Link   : https://leetcode.com/problems/majority-element/description/
    
*/

class Solution {
    public int majorityElement(int[] nums) {
        int len = nums.length;
        if(len==0) return Integer.MAX_VALUE;
        int index = 0;
        int count = 1;
        for(int i=1; i<len; i++) {
            if(nums[i]==nums[index]) count++;
            else count--;
            if(count==0) {
                index=i;
                count=1;
            }
        }
        return nums[index];
    }
}