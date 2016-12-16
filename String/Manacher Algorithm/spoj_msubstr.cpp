/*--------------------------------------------------------------------------------------------------------
*	Name			:	CNatka
*	Problem			:	MSUBSTR
*	Source			:	Spoj
*	Link			:	http://www.spoj.com/problems/MSUBSTR/
*	DS			:	String
*	Algo			:	Manacher's algorithm
*	Date			:	Dec 16, 2016
*	Complexity		:	O(n)	||	AC(0.01 sec)
*	Solved			:	self
*	Alternative Sol		:	NA
*	Note			:	This code should be used for the purpose of learning only, use it at your own risk
*----------------------------------------------------------------------------------------------------------*/

#include <cstdio>
#include <string>
#include <iostream>
#include <vector>
using namespace std;

void manacher(vector<int>& A, vector<int>& B, string s, int& m)
{
	int n = s.size();
	int l = 0, r = -1;
	for(int i=0; i<n; i++)
	{
		int k = (i > r ? 0 : min(A[l+r-i]-1, r-i))+1;
		while(i+k < n && i-k >= 0 && s[i+k]==s[i-k])	++k;
		A[i] = k--;
		m = max(m, 2*A[i] - 1);
		if(i+k > r)
		{
			r = i+k;
			l = i-k;
		}
	}
	l = 0, r = -1;
	for(int i=0; i<n; i++)
	{
		int k = (i > r ? 0 : min(B[l+r-i+1], r-i+1) )+1;
		while(i+k-1 < n && i-k >= 0 && s[i+k-1]==s[i-k]	) ++k;
		B[i] = --k;
		m = max(m, 2*B[i]);
		if(i+k-1 > r)
		{
			r = i+k-1;
			l = i-k;
		}
	}
}

int main()
{
	int t;
	scanf("%d",&t);
	cin.clear(); cin.ignore(1,'\n');
	while(t--)
	{
		string s;
		getline(cin,s);
		int n = s.size();
		cin.clear(); cin.ignore(0,'\n');
		vector<int> odd(n),even(n);
		int max=0, count=0;
		manacher(odd, even, s, max);
		for(int i=0; i<n; i++)
		{
			if(2*odd[i]-1 == max)	count++;
			if(2*even[i] == max)	count++;
		}
		printf("%d %d\n", max, count);
	}
	return 0;
}
