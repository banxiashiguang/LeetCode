#include <iostream>
using namespace std;

class Solution
{
public:
	int partation(int A[],int left,int right)
	{
		int value = A[left];
		int index = left;
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
	void quickSort(int A[],int left,int right)
	{
		if(left >= right)
			return;
		int index = partation(A,left,right);
		quickSort(A,left,index-1);
		quickSort(A,index+1,right);
	}
	void sortColors(int A[],int n)
	{
		quickSort(A,0,n-1);	
	}
};

int main(int argc,const char *argv[])
{
	int A[] = {1,1,0,0,2,1,0,2};
	int n = sizeof(A)/sizeof(A[0]);
	Solution s;
	s.setColors(A,n);
	for(int i = 0; i < n; ++i)
		cout << A[i] << "\t";
	cout << endl;
	return 0;
}
