/*--------------------------------------------------------------------------------------------------------
*	Name			:	CNatka
*	Problem			:	SEACIR
*	Source			:	Codechef
*	Link			:	https://www.codechef.com/problems/SEACIR
*	DS			:	NA
*	Algo			:	Math, Geometry, Implementation
*	Date			:	Jan 17, 2017
*	Complexity		:	AC(0.00 sec)	||	(2955.497059 points)
*	Solved			:	self
*	Alternative Sol		:	NA
*	Note			:	This code should be used for the purpose of learning only, use it at your own risk
*----------------------------------------------------------------------------------------------------------*/

#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
	int N, S, skip;
	scanf("%d %d %d", &N, &S, &skip);
	vector<int> A;
	int limit = 2*N;
	for(int i=0; i<limit; i++)
	{
		int temp;
		scanf("%d",&temp);
		A.push_back(temp);
	}
	sort(A.begin(), A.end());
	int cutoff = A[A.size()-skip];
	int maxRadius = A[A.size()-skip-1];
	int perLine = (int)sqrt((double)(N-skip));
	while(1)
	{
		if(perLine*perLine < (N-skip))
			perLine++;
		else break;
	}
	int lowLimit = 0, upperLimit = 0;			// upperLimit is the max value upto which circle is reaching, low limit is to maintain the gap
	int leftBoundary = 0;
	int minGap = (S - 2*maxRadius*perLine)/(perLine-1);
	int currentCirclesInLine = 0;
	int row = 0;
	int skipCount = 0;
	for(int i=0; i<N; i++)
	{
		int r;
		int x = -1, y = -1;
		scanf("%d",&r);
		if( (r >= cutoff && skipCount < skip) || (skip-skipCount)>=(N-i))
		{
			//printf("-1 -1\n");
			cout<<"-1 -1"<<endl;
			fflush(stdout);
			skipCount++;
			continue;
		}
		if(currentCirclesInLine == perLine)
		{
			currentCirclesInLine = 0;
			lowLimit = upperLimit;
			leftBoundary = 0;
			row++;
		}
		if(row==0)
		{
			y = r;
			upperLimit = max(upperLimit, y+r);
			if(currentCirclesInLine==0)
			{
				x = r;
				leftBoundary = x+r;
			}
			else if(currentCirclesInLine == (perLine-1))
			{
				x = S-r;
			}
			else
			{
				int hgap = (S-leftBoundary-(perLine-currentCirclesInLine)*2*maxRadius)/(perLine-currentCirclesInLine);
				int hbuffer = (maxRadius-r)/(perLine-currentCirclesInLine);
				x = max(minGap, hgap+hbuffer);
				x += (leftBoundary+r);
				leftBoundary = x+r;
			}
			currentCirclesInLine++;
		}
		else if(row==(perLine-1))
		{
			y = S-r;
			if(currentCirclesInLine==0)
			{
				x = r;
				leftBoundary = x+r;
			}
			else if(currentCirclesInLine == (perLine-1))
			{
				x = S-r;
			}
			else
			{
				int hgap = (S-leftBoundary-(perLine-currentCirclesInLine)*2*maxRadius)/(perLine-currentCirclesInLine);
				int hbuffer = (maxRadius-r)/(perLine-currentCirclesInLine);
				x = max(minGap, hgap+hbuffer);
				x += (leftBoundary+r);
				leftBoundary = x+r;
			}
			currentCirclesInLine++;
		}
		else
		{
			int vgap = (S-upperLimit-(perLine-row)*2*maxRadius)/(perLine-row);
			int vbuffer = (maxRadius-r)/(perLine-row);
			y = max(minGap, vgap+vbuffer);
			y += (lowLimit+r);
			upperLimit = max(upperLimit, y+r);
			if(currentCirclesInLine==0)
			{
				x = r;
				leftBoundary = x+r;
			}
			else if(currentCirclesInLine == (perLine-1))
			{
				x = S-r;
			}
			else
			{
				int hgap = (S-leftBoundary-(perLine-currentCirclesInLine)*2*maxRadius)/(perLine-currentCirclesInLine);
				int hbuffer = (maxRadius-r)/(perLine-currentCirclesInLine);
				x = max(minGap, hgap+hbuffer);
				x += (leftBoundary+r);
				leftBoundary = x+r;
			}
			currentCirclesInLine++;
		}
		cout<<x<<" "<<y<<endl;
		fflush (stdout);
	}
	return 0;
}
