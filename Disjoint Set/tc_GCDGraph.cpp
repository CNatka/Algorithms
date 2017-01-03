/*--------------------------------------------------------------------------------------------------------
*	Name			:	CNatka
*	Problem			:	GCDGraph
*	Source			:	TopCoder
*	Link			:	https://community.topcoder.com/stat?c=problem_statement&pm=14461
*	DS				:	Disjoint Set
*	Algo			:	Union Find
*	Date			:	Jan 03, 2017
*	Complexity		:	O(n*n/k)	||	AC
*	Solved			:	after reading solution : https://community.topcoder.com/stat?c=problem_solution&cr=22860847&rd=16848&pm=14461
*	Alternative Sol	:	NA
*	Note			:	This code should be used for the purpose of learning only, use it at your own risk
*----------------------------------------------------------------------------------------------------------*/

#include <vector>
#include <string>
using namespace std;


class GCDGraph 
{
public:
	int find(int a, vector<int>& V)
	{
		return (a == V[a]) ? a : (V[a] = find(V[a], V) );
	}
	void Union(int a, int b, vector<int>& V)
	{
		a = find(a, V);
		b = find(b, V);
		if(a != b)
			V[a] = b;
	}
	string possible(int n, int k, int x, int y) 
	{
		vector<int>V;
		for(int i=0; i<=n; i++)
			V.push_back(i);
		for(int i=k+1; i<=n; i++)
		{
			for(int j=i+i; j<=n; j+=i)
				Union(i, j, V);
		}
		return (find(x, V) == find(y, V))? "Possible" : "Impossible";
	}
};
