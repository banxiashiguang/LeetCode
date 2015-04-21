#include <iostream>
using namespace std;

void solution(int A[],int n)
{
	for (int i = 1; i < n; ++i)
	{
		for(int j = i-1; j >= 0; --j)
		{
			if(A[j+1] < A[j])
				swap(A[j+1],A[j]);
			else
				break;
		}
	}
}

int main(int argc,const char *argv[])
{
	int A[] = {4,2,6,9,8,1,1,5};
	int n = sizeof(A)/sizeof(A[0]);
	solution(A, n);
	for (int i = 0; i < n; ++i)
	{
		cout << A[i] << "\t";
	}
	cout << endl;
}