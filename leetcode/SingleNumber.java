/*
    Author : CNatka
    Date   : Aug 19, 2018
    OJ     : Single Number
    Link   : https://leetcode.com/problems/single-number/description/
    
*/

class Solution {
    public int singleNumber(int[] nums) {
        int len = nums.length;
        int num=0;
        for(int i=0; i<len; i++) {
            num ^= nums[i];
        }
        return num;
    }
}