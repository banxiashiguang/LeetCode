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
	if(A==NULL || n==0)
		return true;
	int reach = 0;
	for (int i = 0; i <= reach && reach < n; ++i)
	{
		reach = max(A[i]+i,reach);
	}
	if(reach < n-1)
		return false;
	return true;
}

int main(int argc, char const *argv[])
{
	int A[] = {3,2,1,0,4};
	int n = sizeof(A)/sizeof(A[0]);
	jumpGame j;
	cout<< j.solution(A, n) << endl;
	return 0;
}