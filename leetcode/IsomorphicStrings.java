/*
    Author : CNatka
    Date   : Aug 20, 2018
    OJ     : Isomorphic Strings
    Link   : https://leetcode.com/problems/isomorphic-strings/description/
    
*/

class Solution {
    public boolean isIsomorphic(String s, String t) {
        int sLen = s.length();
        int tLen = t.length();
        if(sLen != tLen) return false;
        if(sLen == 0) return true;
        int[] sCount = new int[255];
        int[] tCount = new int[255];
        Map<Character, Character> map = new HashMap<>();
        for(int i=0; i<sLen; ++i) {
            char sChar = s.charAt(i);
            char tChar = t.charAt(i);
            if(map.containsKey(Character.valueOf(sChar))) {
                if(map.get(Character.valueOf(sChar)) != tChar) return false; 
            } else {
                map.put(sChar, tChar);
            }
            sCount[(int)(s.charAt(i))]++;
            tCount[(int)(t.charAt(i))]++;
        }
        Arrays.sort(sCount);
        Arrays.sort(tCount);
        for(int i=0; i<255; ++i) {
            if(sCount[i] != tCount[i]) {
                return false;
            }
        }
        return true;
    }
}