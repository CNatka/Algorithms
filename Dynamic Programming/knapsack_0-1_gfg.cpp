/*-------------------------------------------------------------------------------------------
*   Name            : CNatka
*   Problem         : 0-1 knapsack
*   Source          : GeeksForGeeks
*   Link            : http://practice.geeksforgeeks.org/problems/0-1-knapsack-problem/0
*   DS              : NA
*   Algo            : Dynamic Programming
*   Date            : May 12, 2017  
*   Complexityy     : O(n*W)    ||  AC(0.086 sec)
*   Solved          : self
*   Alternative Sol : NA
*   Note            : This code should be used for the purpose of learning only, use 
*                     it at your own risk   
---------------------------------------------------------------------------------------------*/

#include <cstdio>
#include <vector>
using namespace std;
int knapsack(const vector<int> V, const vector<int> Wt, const int N, const int W)
{
    vector<vector<int> > DP;
    for(int i=0; i<=N; i++)
    {
        vector<int> temp(W+1, 0);
        DP.push_back(temp);
    }
    for(int i=0; i<=N; i++)
    {
        for(int j=0; j<=W; j++)
        {
            if(i==0 || j==0)    DP[i][j] = 0;
            else if(Wt[i-1] <= j)
                DP[i][j] = max(V[i-1]+DP[i-1][j-Wt[i-1]], DP[i-1][j]);
            else
                DP[i][j] = DP[i-1][j];
        }
    }
    return DP[N][W];
}

int main() 
{
	int T;
	scanf("%d", &T);
	while(T--)
	{
	    int N, W;
	    scanf("%d", &N);
	    scanf("%d", &W);
	    vector<int> V, Wt;
	    for(int i=0; i<N; i++)
	    {
	        int temp;
	        scanf("%d", &temp);
	        V.push_back(temp);
	    }
	    for(int i=0; i<N; i++)
	    {
	        int temp;
	        scanf("%d", &temp);
	        Wt.push_back(temp);
	    }
	    printf("%d\n", knapsack(V, Wt, N, W));
	}
	return 0;
}
