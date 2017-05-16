/*-------------------------------------------------------------------------------------------
*   Name            : CNatka
*   Problem         : ugly number
*   Source          : GeeksForGeeks
*   Link            : http://practice.geeksforgeeks.org/problems/ugly-numbers/0
*   DS              : NA
*   Algo            : Dynamic Programming
*   Date            : May 16, 2017  
*   Complexityy     : O(T*n)    ||  AC(0.094 sec)
*   Solved          : Read the code
*   Alternative Sol : NA
*   Note            : This code should be used for the purpose of learning only, use 
*                     it at your own risk   
---------------------------------------------------------------------------------------------*/

#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int uglyNumber(const int N)
{
    vector<int> DP(N);
    DP[0] = 1;
    int i2=0, i3=0, i5=0, m2 = 2, m3 = 3, m5 = 5, next=1;
    for(int i=1; i<N; i++)
    {
        next = min(m2, min(m3, m5));
        DP[i] = next;
        if(next == m2)
        {
            i2++;
            m2 = DP[i2]*2;
        }
        if(next == m3)
        {
            i3++;
            m3 = DP[i3]*3;
        }
        if(next == m5)
        {
            i5++;
            m5 = DP[i5]*5;
        }
    }
    return next;
}

int main()
{
    int T; scanf("%d", &T);
    while(T--)
    {
        int N;
        scanf("%d", &N);
        printf("%d\n", uglyNumber(N));
    }
	return 0;
}
