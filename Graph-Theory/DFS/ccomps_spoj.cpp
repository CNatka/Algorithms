/*--------------------------------------------------------------------------------------------------------
*	Name			:	CNatka
*	Problem			:	CCOMPS
*	Source			:	Spoj
*	Link			:	http://www.spoj.com/problems/CCOMPS/
*	DS				:	Graph
*	Algo			:	DFS
*	Date			:	Dec 13, 2016
*	Complexity		:	O(n+m)	|| Problem can not be submitted
*	Solved			:	self
*	Alternative Sol	:	BFS
*	Note			:	This code should be used for the purpose of learning only, use it at your own risk
*----------------------------------------------------------------------------------------------------------*/

#include <vector>
#include <cstdio>
using namespace std;

//int t;
//vector<int>startTime(100000);
//vector<int>finishTime(100000);
enum E {WHITE, GRAY, BLACK};

void dfs(const vector<vector<int> >& G, vector<E>& V, int u)
{
	V[u] = GRAY;
//	startTime[u] = ++t;
	for(int i=0; i<G[u].size(); i++)
	{
		int v = G[u][i];
		if(V[v] == WHITE)	dfs(G, V, v);
	}
//	finishTime[u] = ++t;
	V[u] = BLACK;
}
int main()
{
	int N, M;
	scanf("%d %d",&N, &M);
	vector<vector<int> > G(N);
	for(int i=0; i<M; i++)
	{
		int x, y;
		scanf("%d %d",&x, &y);
		G[x-1].push_back(y-1);
		G[y-1].push_back(x-1);
	}
	vector<E> visited(N, WHITE);
	int count = 0; 						// This keeps count of connected component
	for(int i=0; i<N; i++)
	{
		if(visited[i] == WHITE)
		{
			count++;
			dfs(G, visited, i);
		}
	}
	printf("%d",count);
	scanf("%d",&count);
	return 0;
}