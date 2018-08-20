/*
    Author : CNatka
    Date   : Aug 20, 2018
    OJ     : Count Primes
    Link   : https://leetcode.com/problems/count-primes/description/
    
*/

class Solution {
    public int countPrimes(int n) {
        if(n<2) return 0;
        boolean[] nonPrime = new boolean[n+1];
        nonPrime[0] = true;
        nonPrime[1] = true;
        for (int i=2; i<n; ++i) {
            if (!nonPrime[i]) {
                if (i * 1L * i <= n)
                    for (int j=i*i; j<=n; j+=i)
                        nonPrime[j] = true;
            }
        }
        int count = 0;
        for(int i=0; i<n; i++) {
            if(!nonPrime[i]) count++;
        }
        return count;
    }
}