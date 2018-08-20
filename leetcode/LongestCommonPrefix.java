/*
    Author : CNatka
    Date   : Aug 13, 2018
    OJ     : Leetcode/Longest Common Prefix
    Link   : https://leetcode.com/problems/longest-common-prefix/description/
    
    Solution
    step 1: compare corresponding char of each string
    step 2: break as soon as fail or any string exhausts
    step 3: return the substring of length, no of successfull iteration
*/

class Solution {
    private String lcp = "";
    public String longestCommonPrefix(String[] strs) {
        if(strs.length<1 || strs[0].length()<1) return "";
        char c = strs[0].charAt(0);
        int len = strs.length;
        int index = 0;
        while(true) {
            int i=0;
            for(; i<len; i++) {
                if(index>=strs[i].length() || strs[i].charAt(index) != c) {
                    break;
                }
            }
            if(i==len) {
                index++;
                if(index<strs[0].length()) {
                    c = strs[0].charAt(index);
                } else break;
            } else break;
        }
        return strs[0].substring(0, index);
    }
}