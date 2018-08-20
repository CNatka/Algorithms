/*
    Author : CNatka
    Date   : Aug 13, 2018
    time.  : 14 min 27 sec
    OJ     : Leetcode/Count and Say
    Link   : https://leetcode.com/problems/count-and-say/description/
*/

class Solution {
    public String countAndSay(int n) {
        String res = "1";
        for(int i=1; i<n; i++) {
            String newRes = "";
            int len = res.length();
            for(int j=0; j<len; j++) {
                char digit = res.charAt(j);
                int count=1;
                while(j+1<len && res.charAt(j+1)==digit) {
                    count++;
                    j++;
                }
                newRes = newRes+String.valueOf(count)+(digit-'0');
            }
            res = newRes;
        }
        return res;
    }
}