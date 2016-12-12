/*--------------------------------------------------------------------------------------------------------
*	Name			:	CNatka
*	Problem			:	SCAVHUNT
*	Source			:	Spoj
*	Link			:	http://www.spoj.com/problems/SCAVHUNT/
*	DS				:	Hash Table
*	Algo			:	Find start and end and then print the elements using hash table
*	Date			:	Dec 12, 2016
*	Complexity		:	O(s*logs)	AC(0.05 sec)
*	Solved			:	self
*	Alternative Sol	:	Topological Sort
*	Note			:	This code should be used for the purpose of learning only, use it at your own risk
*----------------------------------------------------------------------------------------------------------*/

#include <string>
#include <cstdio>
#include <iostream>
#include <set>
#include <map>
using namespace std;

bool stringCompare(string s1, string s2)
{
	int n = s1.size();
	if(s2.size() != n)	return false;
	for(int i=0; i<n; i++)
	{
		if(s1[i] != s2[i])	return false;
	}
	return true;
}
int main()
{
	int scenario;
	scanf("%d",&scenario);
	for(int i=1; i<=scenario; i++)
	{
		int steps;
		scanf("%d",&steps);
		cin.clear(); cin.ignore(1,'\n');
		set<string> first, last;
		map<string, string> M;
		string one, two;
		for(int j=1;j<steps;j++)
		{
			cin>>one>>two;
			first.insert(one);
			last.insert(two);
			M.insert(make_pair(one, two));
			cin.clear(); cin.ignore(0,'\n');
		}
		set<string>:: iterator it;
		for(it=first.begin(); it != first.end(); ++it)
		{
			if(last.find(*it) == last.end())		break;
		}
		if(it != first.end())	one = *it;
		for(it=last.begin(); it != last.end(); ++it)
		{
			if(first.find(*it) == first.end())		break;
		}
		if(it != last.end())	two = *it;
		printf("Scenario #%d:\n",i);
		string next = one;
		while(!stringCompare(next, two))
		{
			//printf("%s\n",next);
			cout<<next<<endl;
			next = M[next];
		}
		//printf("%s\n",next);
		cout<<next<<endl<<endl;
		//printf("\n");
	}
	return 0;
}
