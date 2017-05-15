/*-------------------------------------------------------------------------------------------
*   Name            : CNatka
*   Problem         : partition problem
*   Source          : GeeksForGeeks
*   Link            : http://www.geeksforgeeks.org/dynamic-programming-set-18-partition-problem/
*   DS              : NA
*   Algo            : Dynamic Programming
*   Date            : May 15, 2017  
*   Complexityy     : O(n*n)    ||  AC(0.56 sec)
*   Solved          : After reading the code
*   Alternative Sol : NA
*   Note            : This code should be used for the purpose of learning only, use 
*                     it at your own risk   
---------------------------------------------------------------------------------------------*/

#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

bool partitionProblem(const vector<int> arr, const int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
      sum += arr[i];
    if (sum&1)  
       return false;
    sum = sum/2;
    bool DP[sum+1][n+1];
    for (int i = 0; i <= n; i++)
      DP[0][i] = true;
    for (int i = 1; i <= sum; i++)
      DP[i][0] = false;     
      
     for (int i = 1; i <= sum; i++)  
     {
       for (int j = 1; j <= n; j++)  
       {
         DP[i][j] = DP[i][j-1];
         if (i >= arr[j-1])
           DP[i][j] = DP[i][j] || DP[i - arr[j-1]][j-1];
       }        
     }    
     return DP[sum][n];
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
        if(partitionProblem(A, N))  printf("YES\n");
        else                        printf("NO\n");
    }
    return 0;
}
