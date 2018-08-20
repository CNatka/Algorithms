/*
    Author : CNatka
    Date   : Aug 20, 2018
    OJ     : Contains Duplicate
    Link   : https://leetcode.com/problems/contains-duplicate/description/
    
*/

class Solution {
    public boolean containsDuplicate(int[] nums) {
        int len = nums.length;
        if(len<2) return false;
        Map<Integer, Integer> map = new HashMap<>();
        for(int i=0; i<len; ++i) {
            if(map.containsKey(Integer.valueOf(nums[i]))) return true;
            map.put(Integer.valueOf(nums[i]), i);
        }
        return false;
    }
}