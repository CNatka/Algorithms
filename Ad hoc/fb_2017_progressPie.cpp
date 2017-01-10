/*--------------------------------------------------------------------------------------------------------
*	Name			:	CNatka
*	Problem			:	Progress Pie
*	Source			:	Facebook Hacker Cup Qualification Round 2017
*	Link			:	https://www.facebook.com/hackercup/problem/1254819954559001/ (Link might not work in future)
*	DS			:	NA
*	Algo			:	Geometry
*	Date			:	Jan 07, 2017
*	Accepted		:	No (one test case failed out of 2005)
*	Solved			:	self, copied code for angle calculation from stackoverflow
*	Note			:	This code should be used for the purpose of learning only, use it at your own risk
*----------------------------------------------------------------------------------------------------------*/


#include <cstdio>
#include <cmath>
#define M_PI           3.14159265358979323846  /* pi */
using namespace std;
double distance(int x, int y)
{
	double dist = sqrt( (double)(x-50)*(x-50) + (y-50)*(y-50) );
	return dist;
}
double angle(int x, int y)
{
	if(x==50 && y== 50)	return 0.000000;
	double dx21 = 50-50;
	double dx31 = x-50;
	double dy21 = 100-50;
	double dy31 = y-50;
	double m12 = sqrt( dx21*dx21 + dy21*dy21 );
	double m13 = sqrt( dx31*dx31 + dy31*dy31 );
	double theta = acos( (dx21*dx31 + dy21*dy31) / (m12 * m13) );
	theta = theta * 180.0 / M_PI;
	if(x < 50)	theta = 360 - theta;
	return theta;
}

int main()
{
	int T;
	scanf("%d",&T);
	for(int i=1; i<=T; i++)
	{
		int P, X, Y;
		scanf("%d %d %d",&P, &X, &Y);
		//double progress = (P*360)/100;					// this line caused one test case to fail. input ; 12 65 66
		double progress = (2 * M_PI * 0.01 * P *180)/M_PI;
		double theta = angle(X, Y);
		double dist = distance(X, Y);
		if(progress == 0.000000)
			printf("Case #%d: white\n",i);
		else if( ((theta-progress)<0.000001) && ((dist-50.000000)<0.000001) )
			printf("Case #%d: black\n",i);
		else
			printf("Case #%d: white\n",i);
	}
	return 0;
}
