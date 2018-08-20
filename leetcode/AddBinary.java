/*
    Author : CNatka
    Date   : Aug 14, 2018
    OJ     : Add Binary
    Link   : https://leetcode.com/problems/add-binary/description/
*/


/*
    Author : CNatka
    Date   : Aug 14, 2018
    OJ     : Add Binary
    Link   : https://leetcode.com/problems/add-binary/description/
*/


class Solution {
    private int max(int a, int b) {
        return a > b ? a : b;
    }
    public String addBinary(String a, String b) {
        int aLen = a.length();
        int bLen = b.length();
        int len = max(aLen, bLen);
        String sString="";
        String lString="";
        if(aLen == len) {
            lString = a;
            sString = b;
        } else {
            lString = b;
            sString = a;
        }
        StringBuffer temp = new StringBuffer();
        for(int i=0; i<len-sString.length();i++)
            temp.insert(0, "0");
        sString = temp.toString()+sString;
        
        int carry = 0;
        StringBuffer resB = new StringBuffer();
        for(int i=len-1; i>=0; i--) {
            int sum = sString.charAt(i)-'0' + lString.charAt(i)-'0' + carry;
            carry = sum/2;
            if(sum%2==0) resB.insert(0, "0");
            else         resB.insert(0, "1");
        }
        if(carry == 1) resB.insert(0, "1");
        return resB.toString();
    }
}