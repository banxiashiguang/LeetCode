#include "search.h"

//二分查找:时间复杂度O(logn)。
int binary_search(int A[],int n,int target)
{
	int left = 0;
	int right = n-1;
	while(left <= right)
	{
		int mid = (left+right)/2;
		if(A[mid] == target)
			return mid;
		else if(A[mid] < target)
			left = mid+1;
		else
			right = mid-1;
	}
	return -1;
}

int main(int argc, char const *argv[])
{
	int A[] = {1,2,3,4,5,6,7,8,9};
	int n = sizeof(A)/sizeof(A[0]);
	cout<<binary_search(A, n, 4)<<endl;
	return 0;
}