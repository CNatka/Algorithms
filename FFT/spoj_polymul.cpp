/*-------------------------------------------------------------------------------------------
*	Name 			: CNatka
*	Problem 		: POLYMUL
* 	Source  		: Spoj
*	Link			: http://www.spoj.com/problems/POLYMUL/
*	DS				: NA
*	Algo			: FFT
*	Date			: Feb 02, 2017	
*	Complexityy		: O(T*nlogn) 	||	AC(0.18 sec)
*	Solved			: self, picked the code of FFT from web after reading from CLRS
*	Alternative Sol	: NA
*	Note 			: This code should be used for the purpose of learning only, use 
*					  it at your own risk	
---------------------------------------------------------------------------------------------*/

#include <vector>
#include <cstdio>
#include <complex>
#define PI 3.1415926535897
using namespace std;  	
typedef complex<double> base;

void fft(vector<base>& a, bool invert)
{
	int n = (int) a.size();
	for(int i=1, j=0; i<n; ++i)
	{
		int bit = n >> 1;
		for(; j>=bit; bit >>=1)	j-=bit;
			j += bit;
		if(i < j)
		{
			base temp = a[i];
			a[i] = a[j];
			a[j] = temp;
		}
	}
	for(int len=2; len<=n; len<<=1)
	{
		double ang = 2 * PI/len * (invert ? -1 : 1);
		base wlen (cos(ang), sin(ang));
		for(int i=0; i<n; i+=len)
		{
			base w(1);
			for(int j=0; j<len/2; ++j)
			{
				base u = a[i+j], v = a[i+j+len/2]*w;
				a[i+j] = u+v;
				a[i+j+len/2] = u-v;
				w *= wlen;
			}
		}
	}
	if(invert)
	{
		for(int i=0; i<n; i++)
			a[i] /= n;
	}
}

void multiply(const vector<long long>& a, const vector<long long>& b, vector<long long>& res)
{
	vector<base> fa(a.begin(), a.end());
	vector<base> fb(b.begin(), b.end());
	size_t n = 1;
	int m = max(a.size(), b.size());
	while(n < m) n <<= 1;
	n <<= 1;
	fa.resize(n), fb.resize(n);
	fft(fa, false);
	fft(fb, false);
	for(size_t i=0; i<n; ++i)
		fa[i] *= fb[i];
	fft(fa, true);
	res.resize(n);
	for(size_t i=0; i<n; ++i)
		res[i] = (long long)(fa[i].real() + 0.5);
}

int main()
{
	int T;
	scanf("%d", &T);
	while(T--)
	{
		int n;
		scanf("%d", &n);
		vector<long long> a, b;
		for(int i=0; i<=n; i++)
		{
			int temp;
			scanf("%d", &temp);
			a.push_back(temp);
		}
		for(int i=0; i<=n; i++)
		{
			int temp;
			scanf("%d", &temp);
			b.push_back(temp);
		}
		vector<long long> res;
		multiply(a, b, res);
		int m = 2*n;
		printf("%lld", res[0]);
		for(int i=1; i<=m; i++)
			printf(" %lld", res[i]);
		printf("\n");
	}
	return 0;
}
