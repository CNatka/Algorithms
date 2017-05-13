/*-------------------------------------------------------------------------------------------
*   Name            : CNatka
*   Problem         : coin change
*   Source          : GeeksForGeeks
*   Link            : http://practice.geeksforgeeks.org/problems/min-coin/0
*   DS              : NA
*   Algo            : Dynamic Programming
*   Date            : May 13, 2017  
*   Complexityy     : O(n*n)    ||  AC(2.895 sec)
*   Solved          : self
*   Alternative Sol : NA
*   Note            : This code should be used for the purpose of learning only, use 
*                     it at your own risk   
---------------------------------------------------------------------------------------------*/


#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int minCoin(const vector<int> S, const int n, const int N)
{
    vector<int> DP(N+1, -1);
    DP[0] = 0;
    for(int i=0; i<=N; i++)
    {
        for(int j=0; j<n; j++)
        {
           if(S[j]<=i && DP[i-S[j]] >= 0)
           {
               if(DP[i]<0)  DP[i] = DP[i-S[j]]+1;
               else DP[i] = min(DP[i], DP[i-S[j]]+1);
           }
        }
    }
    return DP[N];
}

int main()
{
    int T; scanf("%d", &T);
    while(T--)
    {
        int n, N;
        scanf("%d %d", &n, &N);
        vector<int> S;
        for(int i=0; i<n; i++)
        {
            int temp; scanf("%d", &temp);
            S.push_back(temp);
        }
        printf("%d\n", minCoin(S, n, N));
    }
    return 0;
}
