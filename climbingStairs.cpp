#include <iostream>
using namespace std;

class climbingStairs
{
public:
	climbingStairs() { }
	~climbingStairs() { }
	//int fun(int n);
	int solution(int n);
};

/*int climbingStairs::fun(int n)
{
	if(n == 1)
		return 1;
	if(n == 2)
		return 2;
	return fun(n-1)+fun(n-2);
}*/
int climbingStairs::solution(int n)
{
	int *A = new int[n];
	A[0] = 1;
	A[1] = 2;
	for (int i = 2; i < n; ++i)
	{
		A[i] = A[i-1]+A[i-2];
	}
	int res = A[n-1];
	delete [] A;
	return res;
}

int main(int argc, char const *argv[])
{
	climbingStairs c;
	cout << c.solution(44) << endl;
	return 0;
}