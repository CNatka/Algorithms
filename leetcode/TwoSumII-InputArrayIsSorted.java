/*
    Author : CNatka
    Date   : Aug 19, 2018
    OJ     : Two Sum II - Input array is sorted
    Link   : https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/description/
    
*/

class Solution {
    public int[] twoSum(int[] numbers, int target) {
        int len = numbers.length;
        int[] res = new int[2];
        int si= 0;
        int ei = len-1;
        while(si < ei) {
            int sum = numbers[si]+numbers[ei];
            if(sum == target) {
                res[0]=si+1;
                res[1]=ei+1;
                return res;
            }
            if(sum < target) si++;
            else ei--;
        }
        return res;
    }
}