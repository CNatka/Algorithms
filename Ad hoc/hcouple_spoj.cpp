/*--------------------------------------------------------------------------------------------------------
*	Name			:	CNatka
*	Problem			:	HCOUPLE
*	Source			:	Spoj
*	Link			:	http://www.spoj.com/problems/HCOUPLE/
*	DS			:	NA
*	Algo			:	NA
*	Date			:	Dec 12, 2016
*	Complexity		:	O(1) || AC(0.00 sec)
*	Solved			:	self
*	Alternative Sol		:	NA
*	Note			:	This code should be used for the purpose of learning only, use it at your own risk
*----------------------------------------------------------------------------------------------------------*/

#include <cstdio>
#include <string>
#include <iostream>
using namespace std;
int main()
{
	int T;
	scanf("%d",&T);
	cin.clear(); cin.ignore(1,'\n');
	for(int j=1;j<=T;j++)
	{
		string s;
		getline(cin, s);
		int count=0;
		int n = s.size();
		for(int i=0;i<n;i++)
			count += s[i];
		if(count%3==0)	printf("Case %d: Yes\n",j);
		else		printf("Case %d: No\n",j);
	}
	return 0;
}
