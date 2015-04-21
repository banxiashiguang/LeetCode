#include <iostream>
using namespace std;

void selectionSort(int A[],int n)
{
	for(int i = 0;i < n-1;++i)
	{
		int index = 0;
		for(int j = 0;j < n-i;++j)
		{
			if(A[j] > A[index])
				index = j;
		}
		swap(A[index],A[n-i-1]);
	}	
}

int main(int argc,const char *argv[])
{
	int A[] = {4,2,6,9,8,1,1,5,10,111,4};
	int n = sizeof(A)/sizeof(A[0]);
	selectionSort(A, n);
	for (int i = 0; i < n; ++i)
	{
		cout << A[i] << "\t";
	}
	cout << endl;
}
