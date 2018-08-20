/*
    Author : CNatka
    Date   : Aug 20, 2018
    OJ     : Number of 1 Bits
    Link   : https://leetcode.com/problems/number-of-1-bits/description/
    
*/

public class Solution {
    // you need to treat n as an unsigned value
    public int hammingWeight(int n) {
        int count=0;
        int temp = 1;
        for(int i=0; i<32; i++) {
            if((temp & n) != 0) count++;
            temp <<= 1;
        }
        return count;
    }
}