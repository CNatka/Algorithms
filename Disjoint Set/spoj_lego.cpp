/*--------------------------------------------------------------------------------------------------------
*	Name			:	CNatka
*	Problem			:	LEGO
*	Source			:	Spoj
*	Link			:	http://www.spoj.com/problems/LEGO/
*	DS			:	Disjoint Set
*	Algo			:	Union Find, Sorting
*	Date			:	Dec 28, 2016
*	Complexity		:	O(N*logN)	||	AC(0.21 sec)
*	Solved			:	read from https://github.com/mukel/ProgrammingContests/blob/master/OldStuff/SPOJ/new10/lego.cpp
*					and then self implemented
*	Alternative Sol		:	Connected Component (I couldn't get TLE resolved)
*	Note			:	This code should be used for the purpose of learning only, use it at your own risk
*----------------------------------------------------------------------------------------------------------*/

#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
typedef struct lego
{
	int lo, hi, id, t;
	lego(int a, int b, int c, int d)
	{
		lo = a;
		hi = b;
		id = c;
		t = d;
	}
} lego;

bool comp1(const lego L1, const lego L2)
{
	if(L1.lo != L2.lo)	return L1.lo < L2.lo;
	return L1.t > L2.t;
}

bool comp2(const lego L1, const lego L2)
{
	if(L1.hi != L2.hi)	return L1.hi < L2.hi;
	return L1.t > L2.t;
}

int find(const vector<int>& parent, const int a)
{
	if(parent[a] == a)	return a;
	return find(parent, parent[a]);
}

void Union(vector<int>& parent, int a, int b, int& count)
{
	int id1 = find(parent, a);
	int id2 = find(parent, b);
	if(id1 != id2)
	{
		count--;
		parent[id1] = id2;
	}
}

int main()
{
	int N;
	scanf("%d",&N);
	map<int, vector<lego> >M;
	for(int i=0; i<N; i++)
	{
		int a, b, c, d;
		scanf("%d %d %d %d",&a, &b, &c, &d);
		M[b].push_back(lego(a, c, i, 0) );
		M[d].push_back(lego(a, c, i, 1) );
	}
	vector<int> DS;
	for(int i=0; i<N; i++)	DS.push_back(i);
	int count = N;
	map<int, vector<lego> > :: iterator it;
	for(it = M.begin(); it != M.end(); ++it)
	{
		vector<lego>& V = it->second;
		vector<lego> check;
		sort(V.begin(), V.end(), comp1);
		for(int i=V.size()-1; i>=0; i--)
		{
			if(V[i].t == 1)	check.push_back(V[i]);
			else
			{
				for(int j=check.size()-1; j>=0; j--)
				{
					if(V[i].hi > check[j].lo)
						Union(DS, V[i].id, check[j].id, count);
					else break;
				}
			}
		}
		check.clear();
		sort(V.begin(), V.end(), comp2);
		for(int i=0; i<V.size(); i++)
		{
			if(V[i].t == 1)	check.push_back(V[i]);
			else
			{
				for(int j=check.size()-1; j>=0; j--)
				{
					if(V[i].lo < check[j].hi)
						Union(DS, V[i].id, check[j].id, count);
					else break;
				}
			}
		}
	}
	printf("%d\n",count);
	return 0;
}
