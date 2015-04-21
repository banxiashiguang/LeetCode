#include <iostream>
using namespace std;

int Partation(int A[],int left,int right)
{
	int index = left;
	int value = A[index];
	while(left < right)
	{
		while(left < right && A[right] > value)
			--right;
		A[index] = A[right];
		index = right;
		while(left < right && A[left] <= value)
			++left;
		A[index] = A[left];
		index = left;
	}
	A[index] = value;
	return index;
}

void quickSort(int A[],int start,int end)
{
	if(start >= end)
		return;
	int index = Partation(A,start,end);
	quickSort(A,start,index-1);
	quickSort(A,index+1,end);
}
int main(int argc, char const *argv[])
{
	int A[] = {4,2,6,9,8,1,1,5};
	int n = sizeof(A)/sizeof(A[0]);
	quickSort(A, 0,n-1);
	for (int i = 0; i < n; ++i)
	{
		cout << A[i] << "\t";
	}
	cout << endl;
	return 0;
}
