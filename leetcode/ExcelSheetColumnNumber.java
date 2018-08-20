/*
    Author : CNatka
    Date   : Aug 20, 2018
    OJ     : Excel Sheet Column Number
    Link   : https://leetcode.com/problems/excel-sheet-column-number/description/
    
*/

class Solution {
    public int titleToNumber(String s) {
       int len = s.length();
        if(len==0) return Integer.MIN_VALUE;
        int mul = 1;
        int res = 0;
        for(int i=len-1; i>=0; i--) {
            int digit = (int)(s.charAt(i) - 'A' + 1);
            res = mul*digit + res;
            mul *= 26;
        }
        return res;
    }
}