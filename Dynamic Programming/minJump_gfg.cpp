/*-------------------------------------------------------------------------------------------
*   Name            : CNatka
*   Problem         : min Jump
*   Source          : GeeksForGeeks
*   Link            : http://practice.geeksforgeeks.org/problems/minimum-number-of-jumps/0
*   DS              : NA
*   Algo            : Dynamic Programming
*   Date            : May 16, 2017  
*   Complexityy     : O(T*n*n)    ||  AC(0.079 sec)
*   Solved          : self
*   Alternative Sol : NA
*   Note            : This code should be used for the purpose of learning only, use 
*                     it at your own risk   
---------------------------------------------------------------------------------------------*/

#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int minJump(const vector<int> A, const int n)
{
    vector<int> DP(n, -1);
    DP[0] = 0;
    for(int i=1; i<n; i++)
    {
        for(int j=0; j<i; j++)
        {
            if(DP[j] != -1 && i <= j+A[j])
            {
                if(DP[i] == -1) DP[i] = DP[j] + 1;
                else DP[i] = min(DP[i], DP[j] + 1);
            }
        }
    }
    return DP[n-1];
}

int main()
{
    int T; scanf("%d", &T);
    while(T--)
    {
        int n; scanf("%d", &n);
        vector<int> A(n);
        for(int i=0; i<n; i++)  scanf("%d", &A[i]);
        printf("%d\n", minJump(A, n));
    }
	return 0;
}
