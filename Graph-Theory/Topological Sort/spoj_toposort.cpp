/*--------------------------------------------------------------------------------------------------------
*	Name			      :	  CNatka
*	Problem			    :	  TOPOSORT
*	Source			    :	  Spoj
*	Link			      :	  http://www.spoj.com/problems/TOPOSORT/
*	DS				      :	  Graph
*	Algo			      :	  Topological Sort
*	Date			      :	  Dec 11, 2016
*	Complexity		  :	  O(n+m)	|| AC(0.09 sec)
*	Solved			    :	  self
*	Alternative Sol	:	  https://www.quora.com/How-should-we-go-about-solving-TOPOSORT-in-SPOJ
*	Note			      :	  This code should be used for the purpose of learning only, use it at your own risk
*----------------------------------------------------------------------------------------------------------*/
#include <cstdio>
#include <vector>
#include <stack>
#include <algorithm>
#define WHITE 0
#define GRAY 1
#define BLACK 2

using namespace std;
bool tsortUtil(const vector<vector<int> >& G, int i, vector<int>& color, stack<int>& S)
{	
	color[i] = GRAY;
	for(int j = G[i].size()-1; j>=0; j--)
	{
		int v = G[i][j];
		if(color[v]==GRAY)			return false;		// back edge means graph has a cycle
		if(color[v]==WHITE)
		{
			if(tsortUtil(G, v, color, S)==false)	return false;
		}
	}
	color[i] = BLACK;
	S.push(i);
	return true;
}

bool tSort(const vector<vector<int> >& G, int n, stack<int>& S)
{
	vector<int> color(n+1, WHITE);
	for(int i=n; i>=1; i--)
	{
		if(color[i] == WHITE)
		{
			if(tsortUtil(G, i, color, S) == false)
				return false;
		}
	}
	return true;
}

int main()
{
	int n, m;
	scanf("%d %d",&n, &m);
	vector<vector<int> > graph(n+1);
	for(int i=0; i<m;i++)
	{
		int x, y;
		scanf("%d %d",&x, &y);
		graph[x].push_back(y);
	}
	for(int i=0;i<=n;i++)
		sort(graph[i].begin(), graph[i].end());
	stack<int> S;
	if(tSort(graph, n, S))
	{
		while(!S.empty())
		{
			printf("%d ",S.top());
			S.pop();
		}
		printf("\n");
	}
	else	printf("Sandro fails.");
	return 0;
}
