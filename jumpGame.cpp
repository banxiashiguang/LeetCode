#include <iostream>
using namespace std;

class jumpGame
{
public:
	jumpGame() { }
	~jumpGame() { }
	bool solution(int A[],int n);
};

bool jumpGame::solution(int A[],int n)
{
	if(A == NULL || n == 1)
		return true;
	int maxIndex = 0;
	for (int i = 0; i <= maxIndex && maxIndex < n-1; ++i)
	{
		if(i+A[i]>maxIndex)
			maxIndex = i+A[i];
	}
	return maxIndex >= n-1;
}

int main(int argc, char const *argv[])
{
	int A[] = {3,2,1,0,4};
	int n = sizeof(A)/sizeof(A[0]);
	jumpGame j;
	cout<< j.solution(A, n) << endl;
	return 0;
}