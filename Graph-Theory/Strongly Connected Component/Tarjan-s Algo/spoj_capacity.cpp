/*--------------------------------------------------------------------------------------------------------
*	Name			:	CNatka
*	Problem			:	CAPCITY
*	Source			:	Spoj
*	Link			:	http://www.spoj.com/problems/CAPCITY/
*	DS			:	Graph, Component Graph
*	Algo			:	Tarjan's algorithm to find SCC, DFS 
*	Date			:	Dec 26, 2016
*	Complexity		:	O(N+M)	||	AC(0.90 sec)
*	Solved			:	After reading the solution description : https://onlinejudge.wordpress.com/2011/07/20/spoj-capcity/
*	Alternative Sol		:	Kosaraju Sharir's Algorithm to find the SCC
*	Note			:	This code should be used for the purpose of learning only, use it at your own risk
*----------------------------------------------------------------------------------------------------------*/

#include <cstdio>
#include <vector>
#include <stack>
using namespace std;

int N;

void Tarjan(const vector<vector<int> >& G, int u, vector<int>& d, vector<int>& low, vector<int>& Component, int& comNo, int& time, stack<int>& S, vector<bool>& visited)
{
	S.push(u);
	visited[u] = true;
	time++;
	d[u] = low[u] = time;
	for(int i=0; i<G[u].size(); i++)
	{
		int v = G[u][i];
		if(d[v] == -1)
		{
			Tarjan(G, v, d, low, Component, comNo, time, S, visited);
			low[u] = min(low[u], low[v]);
		}
		else if( (d[v] < d[u]) && visited[v]  )
			low[u] = min(low[u], d[v]);
	}
	if(low[u] == d[u])
	{
		while(1)
		{
			if(S.empty())	break;
			int v = S.top();
			if(d[v] >= d[u])
			{
				Component[v] = comNo;
				S.pop();
				visited[v] = false;
			}
			else	break;
		}
		comNo++;
	}
}
int main()
{
	int M;
	scanf("%d %d",&N, &M);
	vector<vector<int> >G(N), Gr(N);
	for(int i=0; i<M; i++)
	{
		int A, B;
		scanf("%d %d",&A, &B);
		G[A-1].push_back(B-1);
		Gr[B-1].push_back(A-1);
	}
	vector<bool> visited(N, false);
	vector<int> d(N,-1), low(N,0);
	vector<int> Component(N,-1);				// Component number for each vertex
	int comNo = 0;								// Component Number
	int time = 0;
	stack<int> S;
	for(int i=0; i<N; i++)
	{
		if(d[i] == -1)
		{
			visited.assign(N, false);
			Tarjan(G, i, d, low, Component, comNo, time, S, visited);
		}
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
		if(IN[i] == 0)	count++;				// counting nodes whose in degree is zero in component graph
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
				count++;						// counting nodes in actual graph whose Component in Component graph has zero inDegree
				CandidateCities.push_back(u);
			}
		}
		printf("%d\n", count);
		for(size_t i=0; i<count; i++)	printf("%d ",CandidateCities[i]+1);
	}
	return 0;
}
