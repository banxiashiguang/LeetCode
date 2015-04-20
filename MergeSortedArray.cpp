#include <iostream>
using namespace std;

class MergeSortedArray
{
public:
	MergeSortedArray() { }
	~MergeSortedArray() { }
	void move(int A[],int start,int n)
	{
		for (int i = n-1; i >= start; --i)
		{
			cout << A[i] << "\t";
			A[i+1] = A[i];
		}
		cout << endl;
	}
	void merge(int A[],int m,int B[],int n)
	{
		int index1 = 0;
		int index2 = 0;
		while(index1 < m && index2 < n)
		{
			if(A[index1] > B[index2])
			{
				move(A, index1, m);
				A[index1] = B[index2];
				++m;
				++index2;
			}
			++index1;
		}
		while(index2 < n)
			A[m++] = B[index2++];
		for (int i = 0; i < m; ++i)
		{
			cout << A[i] << "\t";
		}
		cout << endl;
	}
};

int main(int argc, char const *argv[])
{
	int A[10] = {4,5,6};
	int B[] = {1,2,3};
	MergeSortedArray m;
	m.merge(A, 3, B, 3);
	return 0;
}