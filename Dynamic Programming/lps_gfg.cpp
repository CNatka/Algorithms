/*-------------------------------------------------------------------------------------------
*   Name            : CNatka
*   Problem         : Longest palindromic substring
*   Source          : GeeksForGeeks
*   Link            : http://practice.geeksforgeeks.org/problems/longest-palindrome-in-a-string/0
*   DS              : NA
*   Algo            : Dynamic Programming
*   Date            : May 16, 2017  
*   Complexityy     : O(T*N*N)    ||  AC(0.101 sec)
*   Solved          : Read the code
*   Alternative Sol : NA
*   Note            : This code should be used for the purpose of learning only, use 
*                     it at your own risk   
---------------------------------------------------------------------------------------------*/

#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
using namespace std;

string lps(string s)
{
    int n = s.size();
    vector<vector<bool>> DP;
    for(int i=0; i<n; i++)
    {
        vector<bool> temp(n, false);
        DP.push_back(temp);
    }
    for(int i=0; i<n; i++)  DP[i][i] = true;
    int start = -1, gLen = 1;
    for(int i=0; i<n-1; i++)
    {
        if(s[i] == s[i+1])
        {
            if(start < 0)
            {
                start = i;
                gLen = 2;
            }
            DP[i][i+1] = true;
        }
    }
    for(int len=3; len<=n; len++)
    {
        for(int i=0; i<=n-len; i++)
        {
            int j=i+len-1;
            if(DP[i+1][j-1] && s[i] == s[j])
            {
                DP[i][j] = true;
                if(len > gLen)
                {
                    gLen = len;
                    start = i;
                }
            }
        }
    }
    string res = "";
    if(gLen > 1)
    {
        for(int i=start; i<start+gLen; i++)
            res = res + s[i];
    }
    else res = res + s[0];
    return res;
}

int main()
{
    int T; scanf("%d", &T);
    cin.clear();cin.ignore(1, '\n');
    while(T--)
    {
       string s;
       getline(cin, s);
       cout<<lps(s)<<endl;
       cin.clear(); cin.ignore(0, '\n');
    }
	return 0;
}
