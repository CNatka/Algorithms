/*
    Author : CNatka
    Date   : Aug 20, 2018
    OJ     : Reverse Bits
    Link   : https://leetcode.com/problems/reverse-bits/description/
    
*/

public class Solution {
    // you need treat n as an unsigned value
    public int reverseBits(int n) {
        int res = 0;
        for(int i=31; i>=0; i--) {
            if((n & 1<<i) != 0)
            res |= 1<<(31-i);
        }
        return res;
    }
}