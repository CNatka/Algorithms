/*
    Author : CNatka
    Date   : Aug 12, 2018
    OJ     : Leetcode/Reverse Integer
    Link   : https://leetcode.com/problems/reverse-integer/description/
    
    Solution
    step 1: get sign of given input
    step 2: get absolute value of given integer
    step 3: calculate reverse of absolute number calculated in step 2 in a long value
    step 4: assign sign
    step 5: check if it overflows/underflows and return result
*/
class Solution {
    
    private int getSign(int x) {
        return x<0 ? -1 : 1;
    }
    public int reverse(int x) {
        int sign = getSign(x);
        int mask = x >> 31;
        int absValue = (x+mask)^mask;
        long newNum = 0;
        while(absValue>0) {
            int digitAtPositionZero = absValue%10;
            newNum = newNum*10 + digitAtPositionZero;
            absValue /= 10;
        }
        newNum = newNum*sign;
        if(newNum > Integer.MAX_VALUE || newNum < Integer.MIN_VALUE) return 0;
        return (int)newNum;
    }
}
