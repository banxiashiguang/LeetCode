#include <iostream>
using namespace std;

class rotateArray
{
public:
	rotateArray() { }
	~rotateArray() { }
	void solution(int nums[],int n,int k);
};

void printArray(int nums[],int n)
{
	for (int i = 0; i < n; ++i)
	{
		cout << nums[i] << "\t";
	}
	cout << endl;
}
void rotateArray::solution(int nums[],int n,int k)
{
	if(k == n || k <= 0)
		return;
	int *A = new int[k];
	int index = 0;
	for (int i = n-k; i < n; ++i)
	{
		A[index++] = nums[i];
	}
	for (int i = n-k-1; i >= 0; --i)
	{
		nums[i+k] = nums[i];
	}
	int m = 0;
	for (int i = 0; i < index; ++i)
	{
		nums[m++] = A[i];
	}
	printArray(nums, n);
	delete [] A;
}

int main(int argc, char const *argv[])
{
	int A[] = {1,2,3,4,5,6,7};
	int n = sizeof(A)/sizeof(A[0]);
	rotateArray r;
	r.solution(A, n, 3);
	return 0;
}