/*--------------------------------------------------------------------------------------------------------
*	Name			:	CNatka
*	Problem			:	CATSDOGS
*	Source			:	Codechef
*	Link			:	https://www.codechef.com/problems/CATSDOGS
*	DS				:	NA
*	Algo			:	NA
*	Date			:	Jan 14, 2017
*	Complexity		:	O(1)	||	AC(0.04 sec)
*	Solved			:	self
*	Alternative Sol	:	NA
*	Note			:	This code should be used for the purpose of learning only, use it at your own risk
*----------------------------------------------------------------------------------------------------------*/

#include <cstdio>
using namespace std;
long long max(long long a, long long b)
{
	if(a>b)	return a;
	return b;
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		long long C, D, L;
		scanf("%lld %lld %lld",&C, &D, &L);
		if(L%4 != 0)
			printf("no\n");
		else
		{
			long long minCount = 0, maxCount = 0;
			maxCount = C+D;
			long long temp = max(0, C-2*D);
			minCount = D + temp;
			L /= 4;
			if(L>= minCount && L <= maxCount)
				printf("yes\n");
			else
				printf("no\n");
		}
	}
	return 0;
}
