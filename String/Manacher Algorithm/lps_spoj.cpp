/*--------------------------------------------------------------------------------------------------------
*	Name			:	CNatka
*	Problem			:	LPS
*	Source			:	Spoj
*	Link			:	http://www.spoj.com/problems/LPS/
*	DS				:	String
*	Algo			:	Manacher's algorithm
*	Date			:	Dec 17, 2016
*	Complexity		:	O(n)	||	AC(0.00 sec)
*	Solved			:	self
*	Alternative Sol	:	NA
*	Note			:	This code should be used for the purpose of learning only, use it at your own risk
*	No Idea			:	WA for string and AC for char[]
*----------------------------------------------------------------------------------------------------------*/

#include <cstdio>
#include <vector>
#include <string>
#include <iostream>
using namespace std;


int manacher(char* S, int n)
{
	vector<int> d1(n), d2(n);
	int l = 0, r = -1;
	int mLen = 0;
	for(int i=0; i<n; i++)
	{
		int k = (i>r ? 0 : min(d1[l+r-i]-1, r-i) )+1;
		while(i+k < n && i-k >= 0 && S[i+k]== S[i-k]) ++k;
		d1[i] = k--;
		mLen = max(mLen, 2*d1[i]-1);
		if(i+k > r)
		{
			r = i+k;
			l = i-k;
		}
	}
	l = 0, r = -1;
	for(int i=0; i<n; i++)
	{
		int k = (i>r ? 0 : min(d2[l+r-i+1], r-i+1) )+1;
		while(i+k-1 < n && i-k >= 0 && S[i-k]==S[i+k-1])	++k;
		d2[i] = --k;
		mLen = max(mLen, 2*d2[i]);
		if(i+k-1 > r)
		{
			r = i+k-1;
			l = i-k;
		}
	}
	return mLen;
}
int main()
{
	int N;
    scanf("%d",&N);
    char s[N + 1];
 	scanf("%s",s);
 //   cin.clear(); cin.ignore(1, '\n');
 //   string s;
 //  getline(cin, s);
	printf("%d\n",manacher(s, N));
	return 0;
}