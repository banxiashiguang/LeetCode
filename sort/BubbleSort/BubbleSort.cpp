#include <iostream>
using namespace std;

void solution(int A[],int n)
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n-i-1; ++j)
		{
			if(A[j] > A[j+1])
				swap(A[j],A[j+1]);
		}
	}
}

int main(int argc,const char *argv[])
{
	int A[] = {1,4,2,6,7,9,9,8,1,5};
	int n = sizeof(A)/sizeof(A[0]);
	solution(A, n);
	for (int i = 0; i < n; ++i)
	{
		cout << A[i] << "\t";
	}
	cout << endl;
}