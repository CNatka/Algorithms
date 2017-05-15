/*-------------------------------------------------------------------------------------------
*   Name            : CNatka
*   Problem         : Nth Fibonacci Number
*   Source          : GeeksForGeeks
*   Link            : http://practice.geeksforgeeks.org/problems/nth-fibonacci-number/0
*   DS              : NA
*   Algo            : Matrix Multiplication
*   Date            : May 15, 2017  
*   Complexityy     : O(T*lgN)    ||  AC(0.083 sec)
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

void multiply(long long F[2][2], long long M[2][2])
{
    int x = ((F[0][0]*M[0][0])%MOD + (F[0][1]*M[1][0])%MOD)%MOD;
    int y = ((F[0][0]*M[0][1])%MOD + (F[0][1]*M[1][1])%MOD)%MOD;
    int z = ((F[1][0]*M[0][0])%MOD + (F[1][1]*M[1][0])%MOD)%MOD;
    int w = ((F[1][0]*M[0][1])%MOD + (F[1][1]*M[1][1])%MOD)%MOD;
    F[0][0] = x;
    F[0][1] = y;
    F[1][0] = z;
    F[1][1] = w;
}

void pow(long long F[2][2], int n)
{
    if(n==0 || n==1)    return;
    pow(F, n/2);
    multiply(F, F);
    if(n&1)
    {
        long long M[2][2] = {{1, 1}, {1, 0}};
        multiply(F, M);
    }
}

int fib(const int N)
{
    if(N==0) return 0;
    long long F[2][2] = {{1,1}, {1,0}};
    pow(F, N-1);
    return F[0][0];
}
int main()
{
    int T; scanf("%d", &T);
    while(T--)
    {
        int N; scanf("%d", &N);
        printf("%d\n",fib(N));
    }
	return 0;
}
