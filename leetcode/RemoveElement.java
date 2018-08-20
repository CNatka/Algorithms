/*
    Author : CNatka
    Date   : Aug 13, 2018
    OJ     : Leetcode/Remove Element
    Link   : https://leetcode.com/problems/remove-element/description/
*/

class Solution {
    public int removeElement(int[] nums, int val) {
        int j=0;
        int len = nums.length;
        int count = 0;
        // scan and keep all other element to left part 
        // at begining of every iteration j points to the place where next element will come and i points to 
        // number which is to be scanned, count is count before iteration
        for(int i=0; i<len; i++) {
            if(nums[i]!=val) {
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
                count++;
                j++;
            }
        }
        return count;
    }
}