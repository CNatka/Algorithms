/*--------------------------------------------------------------------------------------------------------
*	Name			:	CNatka
*	Problem			:	EC_P
*	Source			:	Spoj
*	Link			:	http://www.spoj.com/problems/EC_P/
*	DS			:	Graph
*	Algo			:	Tarjan's Algorithm, Sorting, DFS
*	Date			:	Dec 24, 2016
*	Complexity		:	O(NC*(N+M))	||	AC(0.04)
*	Solved			:	self
*	Alternative Sol		:	NA
*	Note			:	This code should be used for the purpose of learning only, use it at your own risk
*----------------------------------------------------------------------------------------------------------*/

#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
typedef struct edge
{
	int u;
	int v;
	edge(){};
	edge(int x, int y)
	{
		u = x;
		v = y;
	}
} edge;

bool operator< (const edge E1, const edge E2)
{
	if(E1.u == E2.u)	return E1.v < E2.v;
	return E1.u < E2.u;
}

void DFS(const vector<vector<int> >& G, int u, vector<int>& d, vector<int>& low, vector<int>& parent, vector<bool>& visited, vector<edge>& E, int& time)
{
	visited[u] = true;
	time++;
	d[u] = low[u] = time;
	for(int i=0; i<G[u].size(); i++)
	{
		int v = G[u][i];
		if(!visited[v])
		{
			parent[v] = u;
			DFS(G, v, d, low, parent, visited, E, time);
			low[u] = min(low[u], low[v]);
			if(low[v] > d[u])
				E.push_back(edge (min(u,v), max(u,v) ) );
		}
		else if(parent[u] != v)
			low[u] = min(low[u], d[v]);
	}
}

void findBridges(const vector<vector<int> >& G, const int N, vector<edge>& E)
{
	vector<int> d(N), low(N), parent(N,-1);
	vector<bool> visited(N, false);
	int time = 0;
	for(int i=0; i<N; i++)
	{
		if(!visited[i])
			DFS(G, i, d, low, parent, visited, E, time);
	}
}

int main()
{
	int NC;
	scanf("%d",&NC);
	for(int c=1; c<=NC; c++)
	{
		int N, M;
		scanf("%d %d",&N, &M);
		vector<vector<int> >G(N);
		for(int i=0;i<M; i++)
		{
			int a, b;
			scanf("%d %d",&a, &b);
			G[a-1].push_back(b-1);
			G[b-1].push_back(a-1);
		}
		vector<edge> E;
		findBridges(G, N, E);
		sort(E.begin(), E.end() );
		printf("Caso #%d\n", c);
		int criticlEdge = E.size();
		if(criticlEdge == 0)	printf("Sin bloqueos\n");
		else
		{
			printf("%d\n", criticlEdge);
			for(int i=0;i<criticlEdge; i++)
				printf("%d %d\n",E[i].u+1, E[i].v+1);
		}
	}
	return 0;
}
