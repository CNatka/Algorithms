/*
    Author : CNatka
    Date   : Aug 13, 2018
    OJ     : Leetcode/Remove Duplicates from Sorted Array
    Link   : https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/
*/

class Solution {
    public int removeDuplicates(int[] nums) {
        
        int count = 0;
        int len = nums.length;
        if(len<1) return 0;
        int num = nums[0];
        int j=0;
        // Loop invariant : for every iteration, it starts with a new number which has not been counted yet
        // j is position where new number will come in final result
        for(int i=0; i<len ; i++) {
            num = nums[i];
            count++;
            // this loop will always terminate at last index of num
            while(i+1<len && nums[i+1]==num) i++;
            nums[j] = num;
            j++;
        }
        return count;
    }
}