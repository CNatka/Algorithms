/*--------------------------------------------------------------------------------------------------------
*	Name			:	CNatka
*	Problem			:	CAPCITY
*	Source			:	Spoj
*	Link			:	http://www.spoj.com/problems/CAPCITY/
*	DS			:	Graph, Component Graph
*	Algo			:	Kosaraju Sharir's algorithm to find SCC, DFS 
*	Date			:	Dec 25, 2016
*	Complexity		:	O(N+M)	||	AC(0.72 sec)
*	Solved			:	After reading the solution description : https://onlinejudge.wordpress.com/2011/07/20/spoj-capcity/
*	Alternative Sol		:	Tarjan's Algorithm to find the SCC
*	Note			:	This code should be used for the purpose of learning only, use it at your own risk
*----------------------------------------------------------------------------------------------------------*/

#include <cstdio>
#include <vector>
using namespace std;

void DFS1(const vector<vector<int> >& G, const int u, vector<bool>& visited, vector<int>& topoOrder)
{
	visited[u] = true;
	for(size_t i=0; i<G[u].size(); i++)
	{
		int v = G[u][i];
		if(!visited[v])	DFS1(G, v, visited, topoOrder);
	}
	topoOrder.push_back(u);
}

void DFS2(const vector<vector<int> >& Gr, int u, vector<bool>& visited, vector<int>& Component, int comNo)
{
	visited[u] = true;
	Component[u] = comNo;
	for(size_t i=0; i<Gr[u].size(); i++)
	{
		int v = Gr[u][i];
		if(!visited[v])	DFS2(Gr, v, visited, Component, comNo);
	}
}
int main()
{
	int N, M;
	scanf("%d %d",&N, &M);
	vector<vector<int> >G(N), Gr(N);
	for(int i=0; i<M; i++)
	{
		int A, B;
		scanf("%d %d",&A, &B);
		G[A-1].push_back(B-1);
		Gr[B-1].push_back(A-1);
	}
	vector<bool>visited(N,false);
	vector<int> topoOrder;
	for(int i=0;i<N;i++)
	{
		if(!visited[i])
			DFS1(G, i, visited, topoOrder);
	}
	visited.assign(N, false);
	vector<int> Component(N,-1);					// Component number for each vertex
	int comNo = 0;							// Component Number
	for(int i=0; i<N; i++)
	{
		int u = topoOrder[N-1-i];
		if(!visited[u])			DFS2(Gr, u, visited, Component, comNo++);
	}
	vector<int> IN(comNo, 0);					// in degree of every node in component graph
	for(int u=0; u<N; u++)
	{
		for(size_t j=0; j<Gr[u].size(); j++)
		{
			int v = Gr[u][j];
			if(Component[u] != Component[v])	IN[Component[v] ]++;
		}
	}
	int count = 0;
	for(int i=0; i<comNo; i++)
		if(IN[i] == 0)	count++;				// counting nodes whose in degree in zero in component graph
	if(count > 1)
	{
		printf("0\n");
	}
	else
	{
		count = 0;
		vector<int> CandidateCities;
		for(int u=0; u<N; u++)
		{
			if(IN[ Component[u] ] == 0)		
			{
				count++;				// counting nodes in actual graph whose Component in Component graph has zero inDegree
				CandidateCities.push_back(u);
			}
		}
		printf("%d\n", count);
		for(size_t i=0; i<count; i++)	printf("%d ",CandidateCities[i]+1);
	}
	return 0;
}
