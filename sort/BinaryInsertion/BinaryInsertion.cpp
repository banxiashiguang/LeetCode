#include <iostream>
using namespace std;

int binarySearch(int A[],int start,int end,int target)
{
	int left = start;
	int right = end;
	while(left <= right)
	{
		int mid = (left+right)/2;
		if(A[mid] > target)
			right = mid - 1;
		else
			left = mid + 1;
	}
	return left;
}
void solution(int A[],int n)
{
	for (int i = 1; i < n; ++i)
	{
		int value = A[i];
		int index = binarySearch(A, 0, i-1, value);
		cout << "index=" << index << endl;
		for (int j = i-1; j >= index; --j)
		{
			A[j+1] = A[j];
		}
		A[index] = value;
	}
}

int main(int argc,const char *argv[])
{
	int A[] = {1,4,2,6,9,8,1,5};
	int n = sizeof(A)/sizeof(A[0]);
	solution(A, n);
	for (int i = 0; i < n; ++i)
	{
		cout << A[i] << "\t";
	}
	cout << endl;
}