/*-------------------------------------------------------------------------------------------
*   Name            : CNatka
*   Problem         : Nth Fibonacci Number
*   Source          : GeeksForGeeks
*   Link            : http://practice.geeksforgeeks.org/problems/nth-fibonacci-number/0
*   DS              : NA
*   Algo            : Dynamic Programming
*   Date            : May 15, 2017  
*   Complexityy     : O(T*N)    ||  AC(0.077 sec)
*   Solved          : After reading the code
*   Alternative Sol : NA
*   Note            : This code should be used for the purpose of learning only, use 
*                     it at your own risk   
---------------------------------------------------------------------------------------------*/

#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
const int MOD = 1000000007;
int main()
{
    int T; scanf("%d", &T);
    vector<long long> DP(1001, 0);
    DP[1] = 1;
    for(int i=2; i<1001; i++)
    {
        DP[i] = DP[i-1] + DP[i-2];
        DP[i] = DP[i]%MOD;
    }
    while(T--)
    {
        int N; scanf("%d", &N);
        printf("%lld\n", DP[N]);
    }
	return 0;
}
