/*-------------------------------------------------------------------------------------------
*   Name            : CNatka
*   Problem         : all permutation of a string
*   Source          : GeeksForGeeks
*   Link            : http://practice.geeksforgeeks.org/problems/permutations-of-a-given-string/0
*   DS              : NA
*   Algo            : Backtracking
*   Date            : May 19, 2017  
*   Complexityy     : O(T*N!*lgN)    ||  AC(0.085 sec)
*   Solved          : Read the code
*   Alternative Sol : NA
*   Note            : This code should be used for the purpose of learning only, use 
*                     it at your own risk   
---------------------------------------------------------------------------------------------*/

#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <set>
using namespace std;

void permute(string s, int l, int r, set<string>& st)
{
    if(l==r) 
    {
        st.insert(s);
        return;
    }
    for(int i=l; i<=r; i++)
    {
        char temp = s[i];
        s[i] = s[l];
        s[l] = temp;
        permute(s, l+1, r, st);
        temp = s[i];
        s[i] = s[l];
        s[l] = temp;
    }
    
}

void printPermutation(string s)
{
    int n = s.size();
    set<string> st;
    permute(s, 0, n-1, st);
    set<string> :: iterator it;
    for(it = st.begin(); it != st.end(); it++)
    cout<<*it<<" ";
}

int main()
{
    int T; scanf("%d", &T);
    cin.clear(); cin.ignore(1, '\n');
    while(T--)
    {
        string s;
        getline(cin, s);
        sort(s.begin(), s.end());
        printPermutation(s);
        printf("\n");
        cin.clear(); cin.ignore(0, '\n');
    }
	return 0;
}
