/*--------------------------------------------------------------------------------------------------------
*	Name			:	CNatka
*	Problem			:	LEGO
*	Source			:	Spoj
*	Link			:	http://www.spoj.com/problems/LEGO/
*	DS				:	Graph, Disjoint Set
*	Algo			:	kruskal's algorithm, Union Find, Sorting
*	Date			:	Jan 02, 2017
*	Complexity		:	O(M*logN)	
*	Solved			:	self
*	Alternative Sol	:	Prim's Algorithm
*	Note			:	This code should be used for the purpose of learning only, use it at your own risk
*----------------------------------------------------------------------------------------------------------*/

#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef struct Edge
{
	int u;
	int v;
	int weight;
	Edge(){};
	Edge(int a, int b, int c)
	{
		u = a;
		v = b;
		weight = c;
	}

	bool operator<(Edge E)const
	{
		return weight < E.weight;
	}

} Edge;

int find (vector<int>& parent, const int v) 
{
	return (v == parent[v])? v: (parent[v] = find(parent, parent[v]) );
}

void Union(vector<int>& parent, int u, int v)
{
	u = find (parent, u);
	v = find (parent, v);
	if (u != v)
		parent[u] = v;
}
long long kruskal(const vector<Edge>& V, vector<int>& parent)
{
	int n = V.size();
	long long mstWeight = 0;
	for(int i=0; i<n; i++)
	{
		if(find(parent, V[i].u) != find(parent, V[i].v) )
		{
			Union(parent, V[i].u, V[i].v);
			mstWeight += V[i].weight;
		}
	}
	return mstWeight;
}
int main()
{
	int N, M;
	scanf("%d %d",&N, &M);
	vector<Edge> V;
	for(int i=0; i<M; i++)
	{
		int a, j, k;
		scanf("%d %d %d",&a, &j, &k);
		V.push_back(Edge(a-1, j-1, k) );
	}
	sort( V.begin(), V.end() );
	vector<int> parent;
	for(int i=0; i<N; i++)	parent.push_back(i);
	long long ans = kruskal(V, parent);
	printf("%lld\n",ans);
	return 0;
}
