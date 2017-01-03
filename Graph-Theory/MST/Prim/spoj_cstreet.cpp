/*--------------------------------------------------------------------------------------------------------
*	Name			:	CNatka
*	Problem			:	CSTREET
*	Source			:	Spoj
*	Link			:	http://www.spoj.com/problems/CSTREET/
*	DS			:	Graph, Min Priority Queue
*	Algo			:	Prim's Algorithm
*	Date			:	Jan 03, 2017
*	Complexity		:	O(t*m*n*logn)	||	AC(0.04 sec)
*	Solved			:	self
*	Alternative Sol		:	Kruskal's Algorithm
*	Note			:	Code can be more clean
*	Note			:	This code should be used for the purpose of learning only, use it at your own risk
*----------------------------------------------------------------------------------------------------------*/

#include <vector>
#include <cstdio>
#define INF 1000000000
using namespace std;
typedef struct node
{
	int weight;
	int vertex;
	node(){};
	node(int w, int v)
	{
		weight = w;
		vertex = v;
	}

	bool operator<(const node& N)const
	{
		return (weight < N.weight);
	}
}node ;

void heapify(vector<node>& A, const int i, const int size)
{
	int l = 2*i;
	int r = 2*i+1;
	int lowest = i;
	if(l<=size && A[l-1].weight < A[i-1].weight)
		lowest = l;
	if(r<=size && A[r-1].weight < A[lowest-1].weight)
		lowest = r;
	if(lowest != i)
	{
		node temp = A[lowest-1];
		A[lowest-1] = A[i-1];
		A[i-1] = temp;
		heapify(A, lowest, size);
	}
}

int isPresent(const vector<node>& A, const int v)
{
	int n = A.size();
	for(int i=0; i<n; i++)
	{
		if(A[i].vertex == v)	return i;
	}
	return -1;
}

void decreaseWeight(vector<node>& A, int v, const int key)
{
	A[v-1].weight = key;
	while(v > 1 && A[v/2 -1].weight > A[v-1].weight)
	{
		node temp = A[v/2 - 1];
		A[v/2 - 1] = A[v-1];
		A[v-1] = temp;
		v = v/2;
	}
}

node extractMin(vector<node>& A)
{
	int size = A.size();
	if(size > 0)
	{
		node min = A[0];
		A[0] = A[size-1];
		heapify(A, 1, size-1);
		A.erase(A.begin() + size-1);
		return min;
	}
}

long long prim(const vector<vector<node> >&G)
{
	long long pathLen = 0;
	int n = G.size();
	vector<node> minQueue;
	minQueue.push_back( node(0, 0) );
	for(int i=1; i<n; i++)
	{
		minQueue.push_back( node(INF, i) );
	}
	while(minQueue.size() > 0)
	{
		node u = extractMin(minQueue);
		for(int i=0; i<G[u.vertex].size(); i++)
		{
			node v = G[u.vertex][i];
			int index = isPresent(minQueue, v.vertex);
			if(index >=0 && v.weight < minQueue[index].weight)
				decreaseWeight(minQueue, index+1, v.weight);
		}
		pathLen += u.weight;
	}
	return pathLen;
}
int main()
{
	int t; scanf("%d",&t);
	while(t--)
	{
		int p; scanf("%d",&p);
		int n; scanf("%d",&n);
		int m; scanf("%d",&m);
		vector<vector<node> >G(n);
		for(int i=0; i<m; i++)
		{
			int a, b, c;
			scanf("%d %d %d",&a, &b, &c);
			G[a-1].push_back( node(c, b-1) );
			G[b-1].push_back( node(c, a-1) );
		}
		long long pathLen = prim(G);
		long long cost = pathLen * (long long)p;
		printf("%lld\n",cost);
	}
	return 0;
}
