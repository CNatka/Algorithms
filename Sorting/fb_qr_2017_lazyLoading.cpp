/*--------------------------------------------------------------------------------------------------------
*	Name			:	CNatka
*	Problem			:	Lazy Loading
*	Source			:	Facebook Hacker Cup Qualification Round 2017
*	Link			:	https://www.facebook.com/hackercup/problem/169401886867367/ (Link might not work in future)
*	DS			:	NA
*	Algo			:	sorting
*	Date			:	Jan 07, 2017
*	Accepted		:	AC
*	Solved			:	self
*	Note			:	This code should be used for the purpose of learning only, use it at your own risk
*----------------------------------------------------------------------------------------------------------*/

#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int T;
	scanf("%d",&T);
	for(int i=1; i<=T; i++)
	{
		int N;
		scanf("%d",&N);
		vector<int> V;
		for(int j=0; j<N; j++)
		{
			int w;
			scanf("%d",&w);
			V.push_back(w);
		}
		sort(V.begin(), V.end());
		int lo = 0; int hi = V.size()-1;
		int count = 0;
		while(lo<=hi)
		{
			int need = 49/V[hi];
			if(lo+need > hi)	break;
			hi--;
			lo += need;
			count++;
		}
		printf("Case #%d: %d\n",i, count);
	}
	return 0;
}
