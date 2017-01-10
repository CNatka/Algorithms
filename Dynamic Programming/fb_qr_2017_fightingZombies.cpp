/*--------------------------------------------------------------------------------------------------------
*	Name			:	CNatka
*	Problem			:	Fighting the Zombie
*	Source			:	Facebook Hacker Cup Qualification Round 2017
*	Link			:	https://www.facebook.com/hackercup/problem/326053454264498/ (Link might not work in future)
*	DS			:	NA
*	Algo			:	Dynamic Programming, Probability
*	Date			:	Jan 08, 2017
*	Accepted		:	AC
*	Solved			:	self
*	Note			:	This code should be used for the purpose of learning only, use it at your own risk
*----------------------------------------------------------------------------------------------------------*/

#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
long double A[21][21][10401];
double MAX(double a, double b)
{
	if( (a-b) > 0 )	return a;
	return b;
}
void preProcess()
{
	for(int i=4; i<13; i += 2)					
	{
		for (int sum=1; sum<=i; sum++)			
			A[i][1][sum] = 1;
		for(int thrw=2; thrw<21; thrw++)					
		{
			for(int sum=1; sum<=i*thrw; sum++)			
			{
				for (int k = 1; k <= i && k < sum; k++)
					A[i][thrw][sum] += A[i][thrw-1][sum-k];
			}
		}
	}
	for (int sum=1; sum<=20; sum++)			
			A[20][1][sum] = 1;
	for(int thrw=2; thrw<21; thrw++)					
	{
		for(int sum=1; sum<=20*thrw; sum++)			
		{
			for (int k = 1; k <= 20 && k < sum; k++)
				A[20][thrw][sum] += A[20][thrw-1][sum-k];
		}
	}
}
int main()
{
	preProcess();
	int T;
	scanf("%d",&T);
	for(int i=1; i<=T; i++)
	{
		int H, S;
		scanf("%d %d",&H, &S);
		cin.clear(); cin.ignore(1,'\n');
		string s;
		getline(cin, s);
		cin.clear(); cin.ignore(0,'\n');
		int X, Y, Z;
		int index = 0;
		int lastIndex = s.size();
		double probability = 0;
		for(int j=0; j<S; j++)
		{
			X = 0, Y = 0, Z = 0;
			int temp = s[index++]-'0';
			if(s[index] != 'd')
				temp = temp*10 + s[index++]-'0';
			X = temp;
			index++;
			temp = s[index++]-'0';
			if(index<lastIndex && (s[index] == '0' || s[index] == '2') )
				temp = temp*10 + s[index++]-'0';
			Y = temp;
			if(index<lastIndex && s[index]== ' ')			index++;
			else if(index<lastIndex && (s[index] =='+' || s[index]=='-') )
			{
				bool minus = false;
				if(s[index++] == '-')	minus = true;
				temp = s[index++]-'0';
				while(index<lastIndex && s[index] != ' ')
					temp = temp*10 + s[index++]-'0';
				index++;
				Z = temp;
				if(minus)	Z = -Z;
			}
			//printf("X : %d, Y : %d, Z : %d\n",X, Y, Z);
			double totalCases = 1;
			for(int j=1; j<=X; j++)
				totalCases *= Y;
			int maxS = Y*X+Z;
			if(maxS < H)	continue;
			int minS = X+Z;
			minS = max(H, minS);
			double passCases = 0;
			for(int j=minS; j<=maxS; j++)
				passCases += A[Y][X][j-Z];
			double dTemp = passCases/totalCases;
			probability = MAX(dTemp, probability);
			//printf("current : %3.6f, probability : %3.6f \n",dTemp, probability);
		}
		printf("Case #%d: %1.6f\n",i, probability);
	}
	return 0;
}
