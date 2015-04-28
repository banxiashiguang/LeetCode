#include <iostream>
using namespace std;

class Solution
{
public:
	int removeDuplicates(int A[],int n)
	{
		if(n == 0)
			return 0;
		int count = 1;
		int index = 1;
		for(int i = 1; i < n; ++i)
		{
			//上个if和下个if之间不可以进行交换。
			if(A[i] == A[i-1] && count == 1)
			{
				A[index] = A[i];
				++index;
				++count;
			}
			if(A[i] != A[i-1])
			{
				count = 1;
				A[index] = A[i];
				++index;
			}
		}
		return index;
	}
};

int main(int argc,const char *argv[])
{
	int A[] = {1,1,1,2,2,3};
	int n = sizeof(A)/sizeof(A[0]);
	Solution s;
	int sum = s.removeDuplicates(A,n);
	cout << sum << endl;
	for(int i = 0; i < sum; ++i)
		cout << A[i] << "\t";
	cout << endl;
	return 0;
}
