/*-------------------------------------------------------------------------------------------
*   Name            : CNatka
*   Problem         : Number of string without consecutive Ones
*   Source          : GeeksForGeeks
*   Link            : http://practice.geeksforgeeks.org/problems/consecutive-1s-not-allowed/0
*   DS              : NA
*   Algo            : Dynamic Programming
*   Date            : May 16, 2017  
*   Complexityy     : O(T*N)    ||  AC(0.098 sec)
*   Solved          : Read the code
*   Alternative Sol : NA
*   Note            : This code should be used for the purpose of learning only, use 
*                     it at your own risk   
---------------------------------------------------------------------------------------------*/

#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
const int MOD = 1000000007;
long long countString(const int N)
{
    vector<long long> DP1(N), DP2(N);
    DP1[0] = 1;     //ending with zero
    DP2[0] = 1;     // ending with one
    for(int i=1; i<N; i++)
    {
        DP1[i] = (DP1[i-1] + DP2[i-1])%MOD;
        DP2[i] = DP1[i-1];
    }
    return (DP1[N-1]+DP2[N-1])%MOD;
}

int main()
{
    int T; scanf("%d", &T);
    while(T--)
    {
        int N; scanf("%d", &N);
        printf("%lld\n", countString(N));
    }
    return 0;
}
