/*--------------------------------------------------------------------------------------------------------
*	Name			:	CNatka
*	DS			:	Binary Heap
*	Algo			:	Heapsort
*	Date			:	Dec 31, 2016
*	Complexity		:	O(N*logN)
*	Solved			:	read from Cormen and implemented, Read while needed min priority queue for Prim's algo
*	Alternative Sol		:	NA
*	Note			:	This code should be used for the purpose of learning only, use it at your own risk
*----------------------------------------------------------------------------------------------------------*/

#include <cstdio>
#include <vector>
using namespace std;
void heapify(vector<int>& A, int i, int size)
{
	int n = size;
	int l = 2*i, r = 2*i+1;
	int largest = i;
	if(l<=n && A[l-1] > A[i-1])
		largest = l;
	if(r<=n && A[r-1] > A[largest-1])
		largest = r;
	if(i != largest)
	{
		int temp = A[i-1];
		A[i-1] = A[largest-1];
		A[largest-1] = temp;
		heapify(A, largest, size);
	}
}
void buildHeap(vector<int>& A, int size)
{
	int n = size;
	for(int i=n; i>=1; i--)
		heapify(A, i, size);
}
void HeapSort(vector<int>& A)
{
	int size = A.size();
	buildHeap(A, size);
	for(int i=size; i>1; i--)
	{
		int temp = A[i-1];
		A[i-1] = A[0];
		A[0] = temp;
		size--;
		heapify(A, 1, size);
	}
}
int main()
{
	int N;
	scanf("%d",&N);
	vector<int> A(N);
	for(int i=0; i<N;i++)
		scanf("%d",&A[i]);
	HeapSort(A);
	for(int i=0; i<A.size(); i++)
		printf("%d ",A[i]);
	printf("\n");
	int n;
	scanf("%d",&n);
	return 0;
}
