/*-------------------------------------------------------------------------------------------
*   Name            : CNatka
*   Problem         : Egg Dropping Puzzle
*   Source          : GeeksForGeeks
*   Link            : http://practice.geeksforgeeks.org/problems/egg-dropping-puzzle/0
*   Algo            : Dynamic Programming
*   Date            : May 13, 2017  
*   Complexityy     : O(n*k*k)    ||  AC(0.179 sec)
*   Solved          : after reading the solution
*   Alternative Sol : NA
*   Note            : This code should be used for the purpose of learning only, use 
*                     it at your own risk   
---------------------------------------------------------------------------------------------*/

#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
const int INF = 1000000000;
int eggDrop(const int n, const int k)
{
    vector<vector<int> > DP;
    for(int i=0; i<=n; i++)
    {
        vector<int> temp(k+1);
        DP.push_back(temp);
    }
    for(int i=1; i<=n; i++)
    {
        DP[i][0] = 0;
        DP[i][1] = 1;
    }
    for(int i=1; i<=k; i++)
    {
        DP[1][i] = i;
    }
    for(int i=2; i<=n; i++)
    {
        for(int j=2; j<=k; j++)
        {
            DP[i][j] = INF;
            for(int l=1; l<=j; l++)
            {
                int res = max(DP[i-1][l-1], DP[i][j-l])+1;
                DP[i][j] = min(DP[i][j], res);
            }
        }
    }
    return DP[n][k];
}

int main()
{
    int T; scanf("%d", &T);
    while(T--)
    {
        int n, k;
        scanf("%d %d", &n, &k);
        printf("%d\n", eggDrop(n, k));
    }
    return 0;
}
