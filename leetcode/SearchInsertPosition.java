/*
    Author : CNatka
    Date   : Aug 13, 2018
    time.  : 8 min 10 sec
    OJ     : Leetcode/Search Insert Position
    Link   : https://leetcode.com/problems/search-insert-position/description/
*/

class Solution {
    public int searchInsert(int[] nums, int target) {
        int len = nums.length;
        if(len==0) return 0;
        int hi = nums.length -1;
        int lo = 0;
        while(lo<=hi) {
            int mid = lo + (hi-lo)/2;
            if(nums[mid]==target) return mid;
            if(nums[mid]<target) lo = mid+1;
            else                 hi = mid-1;
        }
        return lo;
    }
}