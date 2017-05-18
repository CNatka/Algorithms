/*-------------------------------------------------------------------------------------------
*   Name            : CNatka
*   Problem         : activity selection problem
*   Source          : GeeksForGeeks
*   Link            : http://practice.geeksforgeeks.org/problems/activity-selection/0
*   DS              : NA
*   Algo            : Greedy
*   Date            : May 18, 2017  
*   Complexityy     : O(T*N*lgN)    ||  AC(0.091 sec)
*   Solved          : Read the code
*   Alternative Sol : NA
*   Note            : This code should be used for the purpose of learning only, use 
*                     it at your own risk   
---------------------------------------------------------------------------------------------*/

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

struct activity
{
    int start;
    int finish;
    activity(int a)
    {
        start = a;
        finish = 0;
    }
};

bool comp1(activity a, activity b)
{
    if(a.finish == b.finish)  return (a.start<b.start);
    return (a.finish < b.finish);
}

int activityCount(vector<activity> V, const int N)
{
    int count = 0;
    if(N==0)    return count;
    sort(V.begin(), V.end(), comp1);
    //printf("---------------------------------------\n");
    //for(int i=0; i<N; i++)  printf("%d ",V[i].start);
    //printf("\n");
    //for(int i=0; i<N; i++)  printf("%d ",V[i].finish);
    //printf("\n---------------------------------------\n");
    count++;
    int finishTime = V[0].finish;
    for(int i=1; i<N; i++)
    {
        if(V[i].start >= finishTime)
        {
            count++;
            //printf("%d\n",count);
            finishTime = V[i].finish;
        }
    }
    printf("%d\n", count);
    return count;
}

int main()
{
    int T; scanf("%d", &T);
    while(T--)
    {
        int N;  scanf("%d", &N);
        vector<activity> V;
        for(int i=0; i<N; i++)
        {
            int temp; scanf("%d",&temp);
            V.push_back(activity(temp));
        }
        for(int i=0; i<N; i++)
        {
            int temp; scanf("%d", &temp);
            V[i].finish = temp;
        }
        activityCount(V, N);
        //printf("%d\n", activityCount(V, N));
    }
	return 0;
}
