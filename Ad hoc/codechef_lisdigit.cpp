/*--------------------------------------------------------------------------------------------------------
*	Name			:	CNatka
*	Problem			:	LISDIGIT
*	Source			:	Codechef
*	Link			:	https://www.codechef.com/problems/LISDIGIT
*	DS			:	NA
*	Algo			:	NA
*	Date			:	Jan 22, 2017
*	Complexity		:	O(T*n)	||	AC(0.04 sec)
*	Solved			:	self
*	Alternative Sol		:	NA
*	Note			:	This code should be used for the purpose of learning only, use it at your own risk
*----------------------------------------------------------------------------------------------------------*/

#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n;
		scanf("%d",&n);
		vector<int>V;
		for(int i=0; i<n; i++)
		{
			int temp;
			scanf("%d",&temp);
			V.push_back(temp);
		}
		long long num = V[0];
		for(int i=1; i<n; i++)
		{
			num *= 10;
			num += V[i];
		}
		printf("%lld\n",num);
	}
	return 0;
}
