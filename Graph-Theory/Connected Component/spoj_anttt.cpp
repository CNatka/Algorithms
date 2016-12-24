/*--------------------------------------------------------------------------------------------------------
*	Name			:	CNatka
*	Problem			:	ANTTT
*	Source			:	Spoj
*	Link			:	http://www.spoj.com/problems/ANTTT/
*	DS				:	Graph
*	Algo			:	DFS, Connected Component, Union Find, line segment intersect
*	Date			:	Dec 24, 2016
*	Complexity		:	O(N*N)	||	AC(0.11 sec)
*	Solved			:	Copied code of line segment intersection check from GeeksForGeeks(in my ToDo list)
*	Alternative Sol	:	NA
*	Note			:	This code should be used for the purpose of learning only, use it at your own risk
*----------------------------------------------------------------------------------------------------------*/

#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

typedef struct node
{
	int Ax, Ay, Bx, By;
	node(){};
	node(int a1, int a2, int b1, int b2)
	{
		// x = 1, y = 2
		Ax = a1;
		Ay = a2;
		Bx = b1;
		By = b2;
	}
} node;

typedef struct Point 
{
	int x, y;
} Point;

bool onSegment(Point p, Point q, Point r)
{
    if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) &&
        q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y))
       return true;
 
    return false;
}
int orientation(Point p, Point q, Point r)
{
    int val = (q.y - p.y) * (r.x - q.x) -
              (q.x - p.x) * (r.y - q.y);
 
    if (val == 0) return 0;  // colinear
 
    return (val > 0)? 1: 2; // clock or counterclock wise
}

bool doIntersect(Point p1, Point q1, Point p2, Point q2)
{
    int o1 = orientation(p1, q1, p2);
    int o2 = orientation(p1, q1, q2);
    int o3 = orientation(p2, q2, p1);
    int o4 = orientation(p2, q2, q1);
 
    if (o1 != o2 && o3 != o4)
        return true;
	
	if (o1 == 0 && onSegment(p1, p2, q1)) return true;
    if (o2 == 0 && onSegment(p1, q2, q1)) return true;
    if (o3 == 0 && onSegment(p2, p1, q2)) return true;
    if (o4 == 0 && onSegment(p2, q1, q2)) return true;
 
    return false;
}

bool isConnected(const node X, const node Y)
{
	Point p1, q1, p2, q2;
	p1.x = X.Ax;
	p1.y = X.Ay;

	q1.x = X.Bx;
	q1.y = X.By;

	p2.x = Y.Ax;
	p2.y = Y.Ay;

	q2.x = Y.Bx;
	q2.y = Y.By;
	
	return doIntersect(p1, q1, p2, q2);
}

void DFS(const vector<node>& G, const int n, const int u, vector<int>& CC, int number)
{
	CC[u] = number;
	for(int i=0; i<n; i++)
	{
		if(CC[i] != -1) continue;								//visited
		if(isConnected(G[u],G[i]) )	
			DFS(G, n, i, CC, number);
	}
}

void makeConnectedComponents(const vector<node>& G, const int n, vector<int>& CC)
{
	int ccNo = 0;
	for(int i=0; i<n; i++)
	{
		if(CC[i] == -1)
		{
			DFS(G, n, i, CC, ccNo);
			ccNo++;
		}
	}
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n, m;
		scanf("%d %d",&n, &m);
		vector<node> G;
		for(int i=0; i<n; i++)
		{
			// x = 1, y = 2
			int a1, a2, b1, b2;
			scanf("%d %d %d %d",&a1, &a2, &b1, &b2);
			G.push_back(node(a1, a2, b1, b2) );
		}
		vector<int> CC(n,-1);
		makeConnectedComponents(G, n, CC);
		for(int i=0; i<m; i++)
		{
			int x, y;
			scanf("%d %d",&x, &y);
			if(CC[x-1] == CC[y-1])	printf("YES\n");
			else					printf("NO\n");
		}
	}
	return 0;
}
