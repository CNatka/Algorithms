/*-------------------------------------------------------------------------------------------
*	Name 			: CNatka
*	Problem 	    	: ABCPATH
* 	Source  		: Spoj
*	Link			: http://www.spoj.com/problems/ABCPATH/
*	DS			: Graph
*	Algo			: DFS
*	Date			: Dec 09, 2016
*	Complexity		: O(H+W) || AC(0.00 sec)  		
*	Solved			: self
*	Alternative Sol		: NA
*	Note 			: This code should be used for the purpose of learning only, use it at your own risk	
---------------------------------------------------------------------------------------------*/

#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
using namespace std;
int max(int a, int b)
{
	if(a>b)	return a;
	return b;
}
bool isSafe(int r1, int c1, int r, int c)
{
	if(r1>=0 && r1 <= r && c1 >= 0 && c1 <= c)	return true;
	return false;
}
void dfs(const vector<vector<char> >&V, vector<vector<bool> >& visited, int i, int j, int r, int c, int& len, int count)
{
	len = max(len, count);
	int R[] = {1, -1, 0, 0, 1, 1, -1, -1};
	int C[] = {1, -1, 1, -1, 0, -1, 0, 1};
	for(int d=0;d<8;d++)
	{
		int r1 = i+R[d];
		int c1 = j+C[d];
		if(isSafe(r1, c1, r, c) && visited[r1][c1]==false)
		{
			if(V[r1][c1] == V[i][j]+1)
			{
				visited[r1][c1]=true;
				dfs(V, visited, r1, c1, r, c, len, count+1);
			}
		}
	}
}
int main()
{
	int H, W;
	int c = 0;
	while(1)
	{
		scanf("%d %d",&H, &W);
		if(H==0 && W==0)	break;
		vector<vector<char> > V(H);
		vector<vector<bool> > visited(H);
		for(int i=0;i<H;i++)
		{
			V[i].resize(W);
			visited[i].resize(W,false);
		}
		string s;
		cin.clear(); cin.ignore(1,'\n');
		for(int i=0;i<H;i++)
		{
			getline(cin,s);cin.clear(); cin.ignore(0,'\n');
			for(int j=0;j<W;j++)
			{
				V[i][j] = s[j];
			}
		}
		int maxLen = 0;
		for(int i=0;i<H;i++)
		{
			for(int j=0;j<W;j++)
			{
				if(V[i][j] == 'A')
				{
					visited[i][j] = true;
					dfs(V, visited, i, j, H-1, W-1, maxLen, 1);
				}
			}
		}
		printf("Case %d: %d\n",++c, maxLen);
	}
	return 0;
}
