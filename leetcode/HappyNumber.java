/*
    Author : CNatka
    Date   : Aug 20, 2018
    OJ     : Happy Number
    Link   : https://leetcode.com/problems/happy-number/description/
    
*/

class Solution {
    private long getSquaredSum(long pn) {
        long res = 0;
        while(pn != 0) {
            long rem = pn%10;
            res += rem*rem;
            pn /= 10;
        }
        return res;
    }
    public boolean isHappy(int n) {
        if(n == 1) return true;
        long pn = (long)n;
        Set<Long> set = new HashSet<>();
        while(true) {
            set.add(pn);
            long num = getSquaredSum((long) pn);
            if(num == 1) return true;
            if(set.contains(num)) return false;
            if(num<=0) return false;
            pn = num;
        }
    }
}