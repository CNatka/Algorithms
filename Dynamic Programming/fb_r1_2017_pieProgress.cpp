/*--------------------------------------------------------------------------------------------------------
*	Name			:	CNatka
*	Problem			:	Pie Progress
*	Source			:	Facebook Hacker Cup 1st Round 2017
*	Link			:	https://www.facebook.com/hackercup/problem/1800890323482794/ (Link might not work in future)
*	DS			:	NA
*	Algo			:	Dynamic Programming, greedy
*	Date			:	Jan 15, 2017
*	Accepted		:	AC
*	Solved			:	self
*	Note			:	This code should be used for the purpose of learning only, use it at your own risk
*----------------------------------------------------------------------------------------------------------*/


#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const long long INF = 987654321;
int main()
{
	int T;
	scanf("%d",&T);
	for(int caso=1; caso<=T; caso++)
	{
		int N, M;
		scanf("%d %d",&N, &M);
		vector<vector<int> > P(N);
		for(int i=0; i<N; i++)
		{
			for(int j=0; j<M; j++)
			{
				int temp;
				scanf("%d",&temp);
				P[i].push_back(temp);
			}
			sort(P[i].begin(), P[i].end());
		}
		vector<int> NI(N, 0);
		vector<long long> T(N, 0);
		T[0] = P[0][NI[0]++]+1;
		for(int i=1; i<N; i++)
		{
			int minIndex=-1;
			long long cost = INF;
			for(int j=0; j<=i; j++)
			{
				if(NI[j] > (M-1))	continue;
				int iCount = NI[j];
				long long temp = T[i-1] + P[j][NI[j]] -  iCount*iCount + (iCount+1)*(iCount+1);
				if(temp < cost)
				{
					cost = temp;
					minIndex = j;
				}
			}
			T[i] = cost;
			if(minIndex >= 0)
				NI[minIndex]++;
		}
		printf("Case #%d: %lld\n", caso, T[N-1]);
	}
	return 0;
}
