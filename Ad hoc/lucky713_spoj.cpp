/*--------------------------------------------------------------------------------------------------------
*	Name			:	CNatka
*	Problem			:	LUCKY713
*	Source			:	Spoj
*	Link			:	http://www.spoj.com/problems/LUCKY713/
*	DS			:	NA
*	Algo			:	Arithmetic Progression : Sum = (n*(a+l))/2, nth term = a + (n-1)*d
*	Date			:	Dec 12, 2016
*	Complexity		:	O(1)	||	AC(0.00 sec)
*	Solved			:	self
*	Alternative Sol		:	NA
*	Note			:	This code should be used for the purpose of learning only, use it at your own risk
*----------------------------------------------------------------------------------------------------------*/

#include <cstdio>
#include <string>
#include <iostream>
using namespace std;
int main()
{
	int T;
	scanf("%d",&T);
	cin.clear(); cin.ignore(1,'\n');
	for(int j=1;j<=T;j++)
	{
		int N;
		scanf("%d",&N);
		int sum = 0;
		int a,l;
		if(N>7)
		{
			a = 7;
			for(int i=N-1;i>=7;i--)
			{
				if(i%7 == 0)
				{
					l = i;
					break;
				}
			}
			int n = 1 + (l-a)/7;
			sum  += (n*(a+l))/2;
		}
		if(N>13)
		{
			a = 13;
			for(int i=N-1; i>=13;i--)
			{
				if(i%13 == 0)
				{
					l = i;
					break;
				}
			}
			int n = 1 + (l-a)/13;
			sum += (n*(a+l))/2;
		}
		if(N>91)
		{
			a = 91;
			for(int i=N-1; i>=91;i--)
			{
				if(i%91 == 0)
				{
					l = i;
					break;
				}
			}
			int n = 1 + (l-a)/91;
			sum -= (n*(a+l))/2;
		}
		printf("Case %d: %d\n",j,sum);
	}
	return 0;
}
