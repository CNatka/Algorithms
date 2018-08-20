/*
    Author : CNatka
    Date   : Aug 13, 2018
    OJ     : Leetcode/Roman to Integer
    Link   : https://leetcode.com/problems/roman-to-integer/description/
    
    Solution
    step 1: create a map using given romal character and their value
    step 2: iterate through the given roman number digits
            if cur char's numeral value is greater or equal to next char's numeral value then simply add it to ans
            if next one is greater than current one then subtract current one from next one and add result to ans
            after loop termination, check if last char was included or not, if not add it's value to ans
*/

class Solution {
    public int romanToInt(String s) {
        Map<Character, Integer> map = new HashMap<>();
        map.put('I', 1);
        map.put('V', 5);
        map.put('X', 10);
        map.put('L', 50);
        map.put('C', 100);
        map.put('D', 500);
        map.put('M', 1000);
        int num = 0;
        int i=0;
        for(; i<s.length()-1; i++) {
            int curNum = map.get(s.charAt(i));
            int nextNum = map.get(s.charAt(i+1));
            if(curNum<nextNum) {
                num += (nextNum-curNum);
                i++;
            } else {
                num += curNum;
            }
        }
        if(i<s.length()) num += map.get(s.charAt(s.length()-1));
        return num;
    }
}