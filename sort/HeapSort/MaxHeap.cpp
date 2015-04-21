#include <iostream>
using namespace std;

void printArray(int A[],int n)
{
	for(int i = 0; i < n; ++i)
		cout << A[i] << "\t";
	cout << endl;
}

void adjustUp(int A[],int start)
{
	int value = A[start];
	int index = start;
	int parent = (start-1)/2;
	while(parent >= 0)
	{
		if(A[parent] < value)
		{
			swap(A[parent],A[index]);
			index = parent;
			parent = (parent-1)/2;
		}else
			break;
	}
}

void adjustDown(int A[],int start,int end)
{
	int value = A[start];
	int index = start;
	int child = 2*start+1;//左孩子索引
	while(child <= end)
	{
		if(child+1 <= end && A[child] < A[child+1])
			child += 1;	
		if(A[child] > value)
		{
			swap(A[index],A[child]);
			index = child;
			child = 2*child+1;
		}else
			break;
	}	
}
void makeHeap(int A[],int n)
{
	for(int i = 0;i < n; ++i)
		adjustUp(A,i);
	printArray(A,n);
}

void pop(int A[],int n)
{
	swap(A[0],A[n-1]);
	adjustDown(A,0,n-2);
}

int main(int argc,const char *argv[])
{
	int A[] = {2,5,9,1,111,5,3,6,8,7};
	int n = sizeof(A)/sizeof(A[0]);
	makeHeap(A,n);
	for(int i = 0;i < n; ++i)
		pop(A,n-i);
	printArray(A,n);
	return 0;
}
