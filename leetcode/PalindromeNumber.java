/*
    Author : CNatka
    Date   : Aug 13, 2018
    OJ     : Leetcode/Palindrome Number
    Link   : https://leetcode.com/problems/palindrome-number/description/
    
    Solution
    step 1: if negative return false (-121 is not palindrome as per qus)
    step 2: get absolute value of given integer
    step 3: assign abs value to a static variable
    step 4: recursively compare char, ith from begining and ith from end
            ith from begining(left side) is given by actual number passed to the metho
            ith from end(right side) is given by static/global number or passed by reference which is divided by 10 while returning
            if ith digit mismatch at any point return false
*/

class Solution {
    private static int num = 0;
    private boolean isSingleDigit(int x) {
        if(x>=0 && x < 10) return true;
        return false;
    }
    private boolean checkPalindromicity(int x) {
        if(isSingleDigit(x)) {
            if(x==num%10) return true;
            return false;
        }
        if(!checkPalindromicity(x/10)) return false;
        num /= 10;
        if(x%10 == num%10) return true;
        return false;
    }
    public boolean isPalindrome(int x) {
        if(x<0) return false;
        int mask = x >>31;
        int absValue = (x+mask)^mask;
        num = absValue;
        return checkPalindromicity(absValue);
    }
}