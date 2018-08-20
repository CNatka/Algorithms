/*
    Author : CNatka
    Date   : Aug 14, 2018
    time.  : 29 min 27 sec
    OJ     : Plus One
    Link   : https://leetcode.com/problems/plus-one/description/
*/

import java.math.BigInteger;
class Solution {
    public int[] plusOne(int[] digits) {
        BigInteger num = BigInteger.ZERO;
        int len = digits.length;
        for(int i=0; i<len; i++) {
            num = num.multiply(BigInteger.valueOf(10));
            num = num.add(BigInteger.valueOf((long)digits[i]));
        }
        num = num.add(BigInteger.ONE);
        String str = num.toString();
        int[] res = new int[str.length()];
        for (int i=0; i<res.length; i++) {
            res[i] = str.charAt(i)-'0';
        }
        return res;
    }
}