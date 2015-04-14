#include <iostream>
#include <string>
#include <limits>
using namespace std;

typedef unsigned int uint32_t;

class reverseBits
{
public:
	reverseBits() { }
	~reverseBits() { }
	uint32_t solution(uint32_t n);
};

uint32_t reverseBits::solution(uint32_t n)
{
	string tmp = "";
	uint32_t res = 0;
	int count = 1;
	while(n >0)
	{
		int mod = n %2;
		tmp += (char)(mod + '0');
		n /= 2;
	}
	for (int i = tmp.size()+1; i <= 32; ++i)
	{
		tmp += '0';
	}
	for (int i = tmp.size()-1; i >= 0; --i)
	{
		if(i != tmp.size() - 1)
			count *= 2;
		if(res > (numeric_limits<unsigned int>::max()) - ((tmp[i] - '0')*count))
			return numeric_limits<unsigned int>::max();
		else
			res += ((tmp[i] - '0')*count);
	}
	return res;

}

int main(int argc, char const *argv[])
{
	reverseBits r;

	//964176192
	cout << r.solution(43261596) << endl;
	return 0;
}