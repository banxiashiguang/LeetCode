#include <iostream>
#include <vector>
using namespace std;

class searchForARange
{
public:
	searchForARange() { }
	~searchForARange() { }
	int binary_search(int A[],int start,int end,int target);
	vector<int> solution(int A[],int n,int target);
};

int searchForARange::binary_search(int A[],int start,int end,int target)
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

vector<int> searchForARange::solution(int A[],int n,int target)
{
	vector<int> res;
	int left,right;
	int index = binary_search(A, 0, n-1, target);
	if(index == -1)
	{
		res.push_back(-1);
		res.push_back(-1);
		return res;
	}
	left=right=index;
	while(left>=0 && A[index]==A[left])
		left--;
	while(right<n && A[index]==A[right])
		right++;
	res.push_back(left+1);
	res.push_back(right-1);
	return res;
}

int main(int argc, char const *argv[])
{
	int A[] = {1};
	int n = sizeof(A)/sizeof(A[0]);
	
	return 0;
}