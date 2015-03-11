#include <iostream>
using namespace std;

class removeDuplicatesFromSortedArray
{
public:
	removeDuplicatesFromSortedArray() { }
	~removeDuplicatesFromSortedArray() { }
	int solution(int A[],int n);
};

int removeDuplicatesFromSortedArray::solution(int A[],int n)
{
	if(n <= 1)
		return n;
	int index = 1;
	for(int i=1;i<n;i++)
	{
		if(A[i] != A[i-1])
		{
			A[index] = A[i];
			index++;
		}
	}
	return index;
}

int main(int argc, char const *argv[])
{
	int a[] = {1,2,2,3,3,4,5};
	int n = sizeof(a)/sizeof(a[0]);
	removeDuplicatesFromSortedArray r;
	cout<<r.solution(a, n)<<endl;
	return 0;
}