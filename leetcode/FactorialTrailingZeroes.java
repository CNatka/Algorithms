/*
    Author : CNatka
    Date   : Aug 20, 2018
    OJ     : Factorial Trailing Zeroes
    Link   : https://leetcode.com/problems/factorial-trailing-zeroes/description/
    
*/

class Solution {
    public int trailingZeroes(int n) {
        int countOfFive = 0;
        long divider = 5;
        while(divider <= (long)n) {
            countOfFive += (int)n/divider;
            divider *= 5;
        }
        return countOfFive;
    }
}