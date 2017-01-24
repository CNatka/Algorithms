/*--------------------------------------------------------------------------------------------------------
*	Name			:	CNatka
*	Problem			:	DIGITSEP
*	Source			:	Codechef
*	Link			:	https://www.codechef.com/problems/DIGITSEP
*	DS				:	NA
*	Algo			:	Recursion, gcd
*	Date			:	Jan 17, 2017
*	Complexity		:	short input : AC(0.00 sec), large input : TLE
*	Solved			:	self
*	Alternative Sol	:	NA
*	Note			:	This code should be used for the purpose of learning only, use it at your own risk
*----------------------------------------------------------------------------------------------------------*/

#include <string>
#include <vector>
#include <cstdio>
#include <iostream>
using namespace std;
long long gcd (const long long a, const long long b) 
{
	if (b == 0)
		return a;
	return gcd (b, a % b);
}
long long fillTable(const long long gcdL, const int col, const string s, const int lastUsedIndex,const int N, const int M, const int X, const int Y)
{
	if(gcdL == 1)	return 1;
	if(col == Y)
	{
		if((N-1-lastUsedIndex)<=M )
		{
			 long long temp = 0;
			for(int j=lastUsedIndex+1; j<N; j++)
			{
				temp *= 10;
				temp += s[j]-'0';
			}
			return gcd(gcdL, temp);
		}
		return 1;
	}
	if(col > Y)	return 1;
	if(N-lastUsedIndex-1 < (X-col+1))	return 1;	// left no of digits are less than min no of digits required
	if(N-lastUsedIndex-1 > (Y-col+1)*M)	return 1;	// left no of digits are greated than max no of digits required
	if(lastUsedIndex == N-1 && col < X) return 1;
	if(lastUsedIndex >= N-1)			return gcdL;
	long long num = 0;
	long long maxGCD = 1;
	int lastIndex = N-1;
	lastIndex = min(lastIndex, M+lastUsedIndex);
	for(int i=lastUsedIndex+1; i<=lastIndex; i++)
	{
		num *= 10;
		num += s[i]-'0';
		long long gcdC = gcd(gcdL, num);
		long long temp = gcdC;
		if( col>=(X-1) && (N-1-i)<=M )
		{
			 temp = 0;
			for(int j=i+1; j<N; j++)
			{
				temp *= 10;
				temp += s[j]-'0';
			}
			maxGCD = max(maxGCD, gcd(gcdC, temp));
		}
		maxGCD = max(maxGCD, fillTable(gcdC, col+1, s, i, N, M, X, Y));
	}
	return maxGCD;
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int N;
		scanf("%d",&N);
		string s;
		cin.clear(); cin.ignore(1, '\n');
		getline(cin, s);
		cin.clear(); cin.ignore(0, '\n');
		int M, X, Y;
		scanf("%d %d %d",&M, &X, &Y);
		vector<long long> A(10, 0);
		long long num = 0;
		int limit = min(M-1, N-1);
		for(int i=0; i<=limit; i++)				// (i+1) digits
		{
			num *= 10;
			num += s[i]-'0';
			A[i] = fillTable(num, 1, s, i, N, M, X, Y);
		}
		long long maxGCD = 0;
		for(int i=0; i<M; i++)
			maxGCD = max(maxGCD, A[i]);
		printf("%lld\n",maxGCD);
	}
	return 0;
}
