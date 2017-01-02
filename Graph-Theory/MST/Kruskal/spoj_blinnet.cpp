/*--------------------------------------------------------------------------------------------------------
*	Name			:	CNatka
*	Problem			:	BLINNET
*	Source			:	Spoj
*	Link			:	http://www.spoj.com/problems/BLINNET/
*	DS				:	Graph, Disjoint Set
*	Algo			:	kruskal's algorithm, Union Find, Sorting
*	Date			:	Jan 02, 2017
*	Complexity		:	O(s*sigma(P)*logN)	||	AC(0.12 sec)
*	Solved			:	self
*	Alternative Sol	:	Prim's Algorithm
*	Note			:	This code should be used for the purpose of learning only, use it at your own risk
*----------------------------------------------------------------------------------------------------------*/

#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
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
	bool operator<(const Edge& E)const
	{
		return (weight < E.weight) ; 
	}
} Edge;

int find(int v, vector<int>& parent)
{
	return (v==parent[v])? v: (parent[v] = find(parent[v], parent) );
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
	long long totalCost = 0;
	int n = V.size();
	for(int i=0; i<n; i++)
	{
		if( find(V[i].u, parent) != find(V[i].v, parent) )
		{
			totalCost += V[i].weight;
			Union(V[i].u, V[i].v, parent);
		}
	}
	return totalCost;
}

int main()
{
	int s; scanf("%d",&s);
	while(s--)
	{
		string temp;
		getline(cin, temp);
		cin.clear(); cin.ignore(0,'\n');
		int n; scanf("%d",&n);
		vector<Edge> V;
		vector<int> parent;
		for(int i=0; i<n; i++)
		{
			parent.push_back(i);
			cin.clear(); cin.ignore(1,'\n');
			string s;
			getline(cin, s);
			cin.clear(); cin.ignore(0, '\n');
			int p; scanf("%d",&p);
			while(p--)
			{
				int neigh, cost;
				scanf("%d %d",&neigh, &cost);
				int u = min(i, neigh-1);
				int v = max(i, neigh-1);
				V.push_back( Edge(u, v, cost) );
			}
		}
		sort( V.begin(), V.end() );
		long long ans = kruskal(V, parent);
		printf("%lld\n",ans);
	}
	return 0;
}
