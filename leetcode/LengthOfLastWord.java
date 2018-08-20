/*
    Author : CNatka
    Date   : Aug 13, 2018
    time.  : 6 min 39 sec
    OJ     : Length of Last Word
    Link   : https://leetcode.com/problems/length-of-last-word/description/
*/

class Solution {
    public int lengthOfLastWord(String s) {
        int len = s.length();
        if(len==0) return 0;
        int i=len-1;
        for(; i>=0; i--) {
           if(s.charAt(i)==' ') continue;
            break;
        }
        int count = 1;
        if(i<0) count=0;
        for(i--; i>=0; i--) {
            if(s.charAt(i) == ' ') break;
            count++;
        }
        return count;
    }
}