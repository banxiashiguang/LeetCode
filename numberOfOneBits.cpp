#include <iostream>
using namespace std;

class numberOfOneBits
{
public:
	numberOfOneBits(){ }
	~numberOfOneBits(){ }
	typedef unsigned int uint32_t;
	int solution(uint32_t n);
};

int numberOfOneBits::solution(uint32_t n)
{
	int res = 0;
	while(n > 0)
	{
		int mod = n%2;
		if(mod == 1)
			++res;
		n /= 2;
	}
	return res;
}

int main(int argc, char const *argv[])
{
	numberOfOneBits n;
	cout << n.solution(11) << endl;
	return 0;
}