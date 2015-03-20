#include <iostream>
using namespace std;

class searchInsertSort
{
public:
	searchInsertSort() { }
	~searchInsertSort(){ }
	int binary_search(int A[],int start,int end,int target);
	int solution(int A[],int n,int target);
};

int searchInsertSort::binary_search(int A[],int start,int end,int target)
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
	return left;
}
int searchInsertSort::solution(int A[],int n,int target)
{
	int index = binary_search(A, 0, n-1, target);
	return index;
}

int main(int argc, char const *argv[])
{
	int A[] = {1,3,5,6};
	int n = sizeof(A)/sizeof(A[0]);
	searchInsertSort s;
	cout<<s.solution(A, n, 0)<<endl;
	return 0;
}