/*
    Author : CNatka
    Date   : Aug 19, 2018
    OJ     : Valid Palindrome
    Link   : https://leetcode.com/problems/valid-palindrome/description/
    
*/

class Solution {
    public boolean isPalindrome(String s) {
        int len = s.length();
        if(len <= 1) return true;
        int si = 0, ei = len-1;
        while(si < ei) {
            char sChar = s.charAt(si);
            char eChar = s.charAt(ei);
            if(!Character.isDigit(sChar) && !Character.isLetter(sChar)) {
                si++;
                continue;
            }
            if(!Character.isDigit(eChar) && !Character.isLetter(eChar)) {
                ei--;
                continue;
            }
            if(Character.toLowerCase(sChar) != Character.toLowerCase(eChar) ) return false;
                si++;
                ei--;
        }
        return true;
    }
}