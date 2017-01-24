/*--------------------------------------------------------------------------------------------------------
*	Name			:	CNatka
*	Problem			:	RESERVOI
*	Source			:	Codechef
*	Link			:	https://www.codechef.com/problems/RESERVOI
*	DS				:	NA
*	Algo			:	Simple Iteration
*	Date			:	Jan 14, 2017
*	Complexity		:	O(N*M)	||	AC(0.49 sec)
*	Solved			:	self
*	Alternative Sol	:	NA
*	Note			:	This code should be used for the purpose of learning only, use it at your own risk
*----------------------------------------------------------------------------------------------------------*/

#include <vector>
#include <string>
#include <iostream>
#include <cstdio>
using namespace std;
bool ifStable(const vector<string>& V, const int N, const int M)
{
	for(int i=0; i<N; i++)
	{
		for(int j=0; j<M; j++)
		{
			if(V[i][j] == 'A')
			{
				if(j==0)								continue;
				if(V[i][j-1]=='W')						return false;
			}
			else if(V[i][j] == 'W')
			{
				if(j==0 || j==(M-1))					return false;
				if(V[i][j-1]=='A')						return false;
				if(i<(N-1) && V[i+1][j]=='A')			return false;
			}
			else
			{
				if(i==(N-1))							continue;
				if(V[i+1][j]=='W' || V[i+1][j]=='A')	return false;
			}
		}
	}
	return true;
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int N, M;
		scanf("%d %d",&N, &M);
		cin.clear(); cin.ignore(1, '\n');
		vector<string> V;
		for(int i=0; i<N; i++)
		{
			cin.clear(); cin.ignore(0, '\n');
			string s;
			getline(cin, s);
			V.push_back(s);
		}
		bool ans = ifStable(V, N, M);
		if(ans)	printf("yes\n");
		else 	printf("no\n");
	}
	return 0;
}
