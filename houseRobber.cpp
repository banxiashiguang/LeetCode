#include <iostream>
#include <vector>
using namespace std;

class houseRobber
{
public:
	houseRobber() { }
	~houseRobber() { }
	int rob(vector<int> &num)
	{
		int size = num.size();
		if(size == 0)
			return 0;
		int *A = new int[size];
		for (int i = 0; i < size; ++i)
		{
			if(i == 0)
				A[i] = num[i];
			else if(i == 1)
				A[i] = num[i-1] > num[i]? num[i-1]:num[i];
			else{
				A[i] = (A[i-1] > (A[i-2]+num[i]))? A[i-1]:A[i-2]+num[i];
			}
		}
		int max = A[size-1];
		delete [] A;
		return max;
	}
};

int main(int argc, char const *argv[])
{
	vector<int> num {2,1,1,2};
	houseRobber h;
	cout << h.rob(num) << endl;
	return 0;
}