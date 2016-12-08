/*-------------------------------------------------------------------------------------------
*	Name 			: CNatka
*	Problem 		: AKBAR
* 	Source  		: Spoj
*	Link			: http://www.spoj.com/problems/AKBAR/
*	DS			: Graph
*	Algo			: BFS
*	Date			: Dec 08, 2016
*	Complexityy		: O(N+R) 	|| AC(0.28 sec)
*	Solved			: Read help after my TLE attempts http://codeforces.com/blog/entry/43713
*	Alternative Sol		: DFS
*	Note 			: This code should be used for the purpose of learning only, use it at your own risk				 	
---------------------------------------------------------------------------------------------*/

#include <cstdio>
#include <list>
#include <queue>
using namespace std;
void bfs(const vector<vector<int> >&graph, int N, vector<int>& S, const vector<int>& O)
{
	vector<bool>visited(N+1,false);
	queue<int>Q;
	Q.push(1);
    visited[1] = true;
    while (!Q.empty()) 
	{
        int u = Q.front();
        Q.pop();
        for (int i=0; i<graph[u].size();i++)
		{
           int v = graph[u][i];
           if (!visited[v]) Q.push(v);
           visited[v] = true;
           if (O[u] == -1)	S[u] = max(S[u], S[v] - 1);
           if (O[v] == -1)	S[v] = max(S[v], S[u] - 1);
        }
    }
}
int main() {
    int T;
    scanf("%d", &T);
	int test, src, dest, i, nodes, edges, soldier, number, strn, org, temp;
    while (T--) 
	{
		int N, R, M;
        scanf("%d %d %d", &N, &R, &M);
		vector<vector<int> >graph(N+1);
		vector<int>S(N+1,-1);
		vector<int>O(N+1,-1);
        for (i = 0; i < R; i++) 
		{
			int src, dest;
            scanf("%d %d", &src, &dest);
            graph[src].push_back(dest);
            graph[dest].push_back(src);
        }
        for (i = 0; i < M; i++) 
		{
			int city, strength;
            scanf("%d %d", &city, &strength);
            S[city] = strength;
            O[city] = strength;
        }
		bfs(graph, N, S, O);    
        bool optimal = true;
        for (i = 1; i <= N; i++) 
		{
            if (S[i] < 0) {
                optimal = false;
                break;
            }
        }
        printf("%s\n",optimal ? "Yes" : "No");
    }

    return 0;
}
