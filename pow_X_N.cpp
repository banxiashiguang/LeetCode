#include <iostream>
using namespace std;

class pow_X_N
{
public:
	pow_X_N() { }
	~pow_X_N() { }
	double solution(double x,int n);
};

double pow_X_N::solution(double x,int n)
{
	if(n == 0)
		return 1.0;
	else if(n > 0)
	{
		double half = solution(x,n/2);
		if(n%2 == 0)
			return half*half;
		else
			return half*half*x;
	}else{
		n = -n;
		double half = solution(x, n/2);
		if(n%2 == 0)
			return 1.0/(half*half);
		else
			return 1.0/(x*half*half);
	}
}

int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}