#include <iostream>
using namespace std;

class searchInRotatedSortedArray
{
public:
	searchInRotatedSortedArray() { }
	~searchInRotatedSortedArray() { }
	int binary_search(int A[],int start,int end,int target);
	int solution(int A[],int n,int target);
};

int searchInRotatedSortedArray::solution(int A[],int n,int target)
{
	int i = 0;
	int index;
	while(i < n-1)
	{
		if(A[i] > A[i+1])
			break;
		i++;
	}
	cout<<A[i]<<endl;
	if(i == n-1)
		index = binary_search(A, 0, n-1, target);
	else{
		index = binary_search(A, 0, i, target);
		if(index == -1)
			index = binary_search(A, i+1, n-1, target);
	}
	return index;
}

int searchInRotatedSortedArray::binary_search(int A[],int start,int end,int target)
{
	int left = start;
	int right = end;
	while(left <= right)
	{
		int mid = (left+right)/2;
		if(A[mid] == target)
			return mid;
		else if(A[mid] < target)
			left++;
		else
			right--;
	}
	return -1;
}

int main(int argc, char const *argv[])
{
	int A[] = {3,1};
	int n = sizeof(A)/sizeof(A[0]);
	searchInRotatedSortedArray s;
	cout<<s.solution(A, n, 1)<<endl;
	return 0;
}