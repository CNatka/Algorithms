/*--------------------------------------------------------------------------------------------------------
*	Name			:	CNatka
*	Problem			:	CSTREET
*	Source			:	Spoj
*	Link			:	http://www.spoj.com/problems/CSTREET/
*	DS			:	Graph, Disjoint Set
*	Algo			:	kruskal's algorithm, Union Find, Sorting
*	Date			:	Jan 02, 2017
*	Complexity		:	O(t*m*logn)	||	AC(0.02 sec)
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
	int a;
	int b;
	int len;
	Edge(){};
	Edge(int x, int y, int z)
	{
		a = x;
		b = y;
		len = z;
	}

	bool operator<(const Edge E)const
	{
		return (len < E.len);
	}
}Edge;

int find(int v, vector<int>& parent)
{
	return (v == parent[v]) ? v : ( parent[v] = find(parent[v], parent) );
}

void Union(int a, int b, vector<int>& parent)
{
	a = find(a, parent);
	b = find(b, parent);
	if(a != b)
		parent[a] = b;
}

long long kruskal(const vector<Edge>& V, vector<int>& parent)
{
	int n = V.size();
	long long res = 0;
	for(int i=0; i<n; i++)
	{
		if(find(V[i].a, parent) != find(V[i].b, parent))
		{
			res += V[i].len;
			Union(V[i].a, V[i].b, parent);
		}
	}
	return res;
}
int main()
{
	int t; scanf("%d",&t);
	while(t--)
	{
		int p; scanf("%d",&p);
		int n; scanf("%d",&n);
		int m; scanf("%d",&m);
		vector<Edge>V;
		for(int i=0; i<m; i++)
		{
			int a, b, c;
			scanf("%d %d %d", &a, &b, &c);
			V.push_back( Edge(a-1, b-1, c) );
		}
		sort(V.begin(), V.end());
		vector<int> parent;
		for(int i=0; i<n; i++)
			parent.push_back(i);
		long long totalLen = kruskal(V, parent);
		long long cost = totalLen*(long long)p;
		printf("%lld\n",cost);
	}
	return 0;
}
