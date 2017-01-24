/*--------------------------------------------------------------------------------------------------------
*	Name			:	CNatka
*	Problem			:	CAPIMOVE
*	Source			:	Codechef
*	Link			:	https://www.codechef.com/problems/CAPIMOVE
*	DS			:	Graph
*	Algo			:	Sorting, Iteration
*	Date			:	Jan 14, 2017
*	Complexity		:	O(T*N)	||	AC(0.29 sec)
*	Solved			:	self
*	Alternative Sol		:	NA
*	Note			:	This code should be used for the purpose of learning only, use it at your own risk
*----------------------------------------------------------------------------------------------------------*/

#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;
typedef struct two
{
	int power;
	int index;
	two(){};
	two(int a, int b)
	{
		power = a;
		index = b;
	}
	bool operator<(const two& T)const
	{
		return (power<T.power);
	}
}two;

int findCapital(int curCap, const vector<vector<int> >&G, const int N, const vector<two>& P)
{
	int n=G[curCap].size();
	vector<bool>visited(N, true);
	visited[curCap] = false;
	for(size_t i=0; i<n; i++)
	{
		int v = G[curCap][i];
		visited[v]=false;
	}
	for(int i=N-1; i>=0; i--)
	{
		int ind = P[i].index;
		if(visited[ind])			return ind;
	}
	return -1;
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int N;
		scanf("%d",&N);
		vector<vector<int> >G(N);
		vector<two>P;
		for(int i=0; i<N; i++)
		{
			int temp;
			scanf("%d",&temp);
			P.push_back(two(temp, i));
		}
		sort(P.begin(), P.end());
		for(int i=0; i<(N-1); i++)
		{
			int U, V; scanf("%d %d",&U, &V);
			G[U-1].push_back(V-1);
			G[V-1].push_back(U-1);
		}
		vector<int> A;
		for(int i=0; i<N; i++)
		{
			int index = findCapital(i, G, N, P);
			printf("%d ",index+1);
		}
		printf("\n");
	}
	return 0;
}
