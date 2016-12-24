/*--------------------------------------------------------------------------------------------------------
*	Name			:	CNatka
*	Problem			:	SUBMERGE
*	Source			:	Spoj
*	Link			:	http://www.spoj.com/problems/SUBMERGE/
*	DS				:	Graph
*	Algo			:	Tarjan's Algorithm, Articulation Point, DFS
*	Date			:	Dec 24, 2016
*	Complexity		:	O(N+M)	|| AC(0.04 sec)
*	Solved			:	self
*	Alternative Sol	:	NA
*	Note			:	This code should be used for the purpose of learning only, use it at your own risk
*----------------------------------------------------------------------------------------------------------*/

#include <vector>
#include <cstdio>
#include <iostream>
using namespace std;

void DFS(const vector<vector<int> >& G, const int u, vector<bool>& visited, vector<int>& d, vector<int>& low, vector<int>& parent, vector<bool>& AP, int& time)
{
	visited[u] = true;
	time++;
	d[u] = low[u] = time;
	int child = 0;
	for(size_t i=0; i<G[u].size(); i++)
	{
		int v = G[u][i];
		if(!visited[v])
		{
			child++;
			parent[v] = u;
			DFS(G, v, visited, d, low, parent, AP, time);
			low[u] = min(low[u], low[v]);
			if(parent[u] != -1 && low[v] >= d[u])
				AP[u] = true;
		}
		else if(parent[u] != v)
			low[u] = min(low[u], d[v]);
	}
	if(parent[u] == -1 && child > 1)
		AP[u] = true;
}

int AP(const vector<vector<int> >& G, const int N)
{
	vector<bool> visited(N, false), AP(N, false);
	vector<int> d(N,0), low(N,0), parent(N, -1);
	int time = 0;
	for(int i=0; i<N; i++)
	{
		if(!visited[i])
			DFS(G, i, visited, d, low, parent, AP, time);
	}
	int count = 0;
	for(int i=0; i<N; i++)
		if(AP[i])	count++;
	return count;
}

int main()
{
	while(1)
	{
		int N, M;
		scanf("%d %d",&N, &M);
		if(N==0 && N==M)	break;
		vector<vector<int> >G(N);
		for(int i=0;i<M;i++)
		{
			int u,v;
			scanf("%d %d",&u, &v);
			G[u-1].push_back(v-1);
			G[v-1].push_back(u-1);
		}
		printf("%d\n",AP(G,N) );
	}
	return 0;
}
