/*--------------------------------------------------------------------------------------------------------
*	Name			:	CNatka
*	Problem			:	ULM09
*	Source			:	Spoj
*	Link			:	http://www.spoj.com/problems/ULM09/
*	DS			:	Graph, Disjoint Set
*	Algo			:	kruskal's algorithm, Union Find, Sorting
*	Date			:	Jan 03, 2017
*	Complexity		:	O(n*logm)	||	AC(0.05 sec)
*	Solved			:	self
*	Alternative Sol		:	Prim's Algorithm
*	Note			:	This code should be used for the purpose of learning only, use it at your own risk
*----------------------------------------------------------------------------------------------------------*/

#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
typedef struct Edge
{
	int u;
	int v;
	int w;
	Edge(){};
	Edge(int x, int y, int z)
	{
		u = x;
		v = y;
		w = z;
	}
	bool operator< (const Edge& E)const
	{
		return (w < E.w);
	}
}Edge;

int find(int a, vector<int>& parent)
{
	return (a == parent[a]) ? a : ( parent[a] = find(parent[a], parent) );
}

void Union(int i, int j, vector<int>& parent)
{
	i = find(i, parent);
	j = find(j, parent);
	parent[i] = j;
}

long long kruskal(const vector<Edge>& V, vector<int>& parent)
{
	long long res = 0;
	int n = V.size();
	for(int i=0; i<n; i++)
	{
		if( find(V[i].u, parent) != find(V[i].v, parent) )
		{
			Union(V[i].u, V[i].v, parent);
			res += V[i].w;
		}
	}
	return res;
}
int main()
{
	while(1)
	{
		int m, n;
		scanf("%d %d",&m, &n);
		if(m==0 && m==n)	break;
		vector<Edge>V;
		long long originalExpenditure = 0;
		for(int i=0; i<n; i++)
		{
			int x, y, z;
			scanf("%d %d %d",&x, &y, &z);
			V.push_back( Edge(x, y, z) );
			originalExpenditure += z;
		}
		sort( V.begin(), V.end() );
		vector<int> parent;
		for(int i=0; i<m; i++)
			parent.push_back(i);
		long long optimizedExpenditure = kruskal(V, parent);
		long long saving = originalExpenditure - optimizedExpenditure;
		printf("%lld\n", saving);
	}
	return 0;
}
