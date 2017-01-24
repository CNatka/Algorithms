/*--------------------------------------------------------------------------------------------------------
*	Name			:	CNatka
*	Problem			:	TOURISTS
*	Source			:	Codechef
*	Link			:	https://www.codechef.com/problems/TOURISTS
*	DS				:	Graph
*	Algo			:	Euler Circuit
*	Date			:	Jan 17, 2017
*	Complexity		:	O(E*logE)	||	AC(0.15 sec)
*	Solved			:	self
*	Alternative Sol	:	NA
*	Note			:	This code should be used for the purpose of learning only, use it at your own risk
*----------------------------------------------------------------------------------------------------------*/

#include <vector>
#include <cstdio>
#include <stack>
#include <set>
#include <ctime>
#include <map>
#define INF 100000000
using namespace std;
typedef struct edge
{
	int u;
	int v;
	edge(){};
	edge(int a, int b)
	{
		u = a;
		v = b;
	}
}edge;
void DFS(const vector<vector<int> >& Gr, const int u, vector<bool>& visited)
{
	visited[u]=true;
	int n=Gr[u].size();
	for(int i=0; i<n; i++)
	{
		int v = Gr[u][i];
		if(!visited[v])	DFS(Gr, v, visited);
	}
}
void eulerianCircuit(vector<set<int> >& G, const int N, const int E, vector<edge>& EV, map<long long, int>& M)
{
	stack<int> S;
	vector<int> circuit;
	int curVertex = 0;
	while(1)
	{
		int nextNeighbour=-1;
		if(G[curVertex].size()>0)
		{
			nextNeighbour = *G[curVertex].begin();
			G[curVertex].erase(G[curVertex].begin());
			G[nextNeighbour].erase(G[nextNeighbour].find(curVertex));
			S.push(curVertex);
			curVertex = nextNeighbour;
		}
		else
		{
			circuit.push_back(curVertex);
			if(S.empty())	break;
			curVertex = S.top();
			S.pop();
		}
	}
	int	pre = circuit[0];
	int cur;
	int n = circuit.size();
	for(int i=1; i<n; i++)
	{
		cur = circuit[i];
		int high, low;
		high = max(cur+1, pre+1);
		low = min(cur+1, pre+1);
		long long key = high*INF + low;
		int index = M[key];
		EV[index] = edge(cur, pre);
		pre = cur;
	}
}
int main()
{
	int N, E;
	scanf("%d %d",&N, &E);
	map<long long, int> M;
	vector<set<int> >G(N);
	vector<vector<int> >Gr(N);
	vector<edge>EV;
	vector<int> degree(N, 0);
	for(int i=0; i<E; i++)
	{
		int a, b;
		scanf("%d %d",&a, &b);
		G[a-1].insert(b-1);
		G[b-1].insert(a-1);
		Gr[a-1].push_back(b-1);
		Gr[b-1].push_back(a-1);
		degree[a-1]++;
		degree[b-1]++;
		EV.push_back(edge(a-1, b-1));
		int high, low;
		high = max(a, b);
		low = min(a, b);
		long long index = INF*high + low;
		M.insert(make_pair(index, i));
	}
	for(int i=0; i<N; i++)
	{
		if(degree[i]==0)	
		{
			printf("NO\n");
			return 0;
		}
		if(degree[i]%2==1)
		{
			printf("NO\n");
			return 0;
		}
 
	}
	vector<bool>visited(N, false);
	DFS(Gr, 0, visited);
	for(int i=1; i<N; i++)
	{
		if(!visited[i])
		{
			printf("NO\n");
			return 0;
		}
	}
	eulerianCircuit(G, N, E, EV, M);
	printf("YES\n");
	for(int i=0; i<E; i++)
		printf("%d %d\n", EV[i].u+1, EV[i].v+1);
	return 0;
} 
