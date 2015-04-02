//利用DP的思想
#include <iostream>
using namespace std;

class maxSumSubArray
{
public:
	maxSumSubArray() { }
	~maxSumSubArray(){ }
	int solution(int A[],int n);
};

int maxSumSubArray::solution(int A[],int n)
{
	if(n == 1)
		return A[0];
	int index = 0;
	for (int i = 0; i < n; ++i)
	{
		if(A[index] < A[i])
			index = i;
	}
	if(A[index] <= 0)
		return A[index];
	int sum = A[0];
	int maxSum = A[0];
	int left = 0;
	int right = 0;
	for (int i = 1; i < n; ++i)
	{
		if(sum < 0)
		{
			sum = A[i];
			left = i;
		}else{
			sum += A[i];
		}
		if(sum > maxSum)
		{
			maxSum = sum;
			right = i;
		}
	}
	cout << "left=" << left << "\tright=" << right << endl;
	return maxSum;
}

int main(int argc, char const *argv[])
{
	int A[] = {-2,1,-3,4,-1,2,1,-5,4};
	int n = sizeof(A)/sizeof(A[0]);
	maxSumSubArray m;
	cout << m.solution(A, n) << endl;
	return 0;
}