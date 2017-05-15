/*-------------------------------------------------------------------------------------------
*   Name            : CNatka
*   Problem         : maximum sum increasing subsequence
*   Source          : GeeksForGeeks
*   Link            : http://practice.geeksforgeeks.org/problems/maximum-sum-increasing-subsequence/0
*   DS              : NA
*   Algo            : Dynamic Programming
*   Date            : May 15, 2017  
*   Complexityy     : O(n*n)    ||  AC(0.061 sec)
*   Solved          : self
*   Alternative Sol : NA
*   Note            : This code should be used for the purpose of learning only, use 
*                     it at your own risk   
---------------------------------------------------------------------------------------------*/

#include <iostream>
#include <vector>
using namespace std;

int maxSumIncrSub(const vector<int> A)
{
    int n = A.size();
    vector<int> DP(n);
    DP[0] = A[0];
    for(int i=1; i<n; i++)
    {
        DP[i] = A[i];
        for(int j=0; j<i; j++)
        {
            if(A[i] > A[j]) DP[i] = max(DP[i], DP[j]+A[i]);
        }
    }
    int maxValue = DP[0];
    for(int i=1; i<n; i++)  maxValue = max(maxValue, DP[i]);
    return maxValue;
}

int main()
{
    int T; scanf("%d", &T);
    while(T--)
    {
        int N; scanf("%d", &N);
        vector<int> A(N);
        for(int i=0; i<N; i++)
        {
            scanf("%d", &A[i]);
        }
        printf("%d\n", maxSumIncrSub(A) );
    }
	return 0;
}
