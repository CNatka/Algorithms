
/*-------------------------------------------------------------------------------------------
*   Name            : CNatka
*   Problem         : maximum sum subarray
*   Source          : GeeksForGeeks
*   Link            : http://practice.geeksforgeeks.org/problems/kadanes-algorithm/0
*   DS              : NA
*   Algo            : Dynamic Programming
*   Date            : May 16, 2017  
*   Complexityy     : O(T*N)    ||  AC(0.135 sec)
*   Solved          : Read the code
*   Alternative Sol : NA
*   Note            : This code should be used for the purpose of learning only, use 
*                     it at your own risk   
---------------------------------------------------------------------------------------------*/

#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int maxSumSubarray(const vector<int> A, const int N)
{
    int gMax = A[0];
    int cMax = A[0];
    for(int i=1; i<N; i++)
    {
        cMax = max(A[i], cMax + A[i]);
        gMax = max(cMax, gMax);
    }
    return gMax;
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
        printf("%d\n", maxSumSubarray(A, N));
    }
	return 0;
}
