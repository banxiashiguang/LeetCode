#include <iostream>
#include <vector>
using namespace std;

class plusOne
{
public:
	plusOne(){ }
	~plusOne() { }
	vector<int> solution(vector<int> &digits);
};

/**
 * digits从左到右分别是整数的高位到低位。
 * 返回值也要符合平时int数值的写法，每次插入时，从vector头进行插入。
 */
vector<int> plusOne::solution(vector<int> &digits)
{
	vector<int> res;
	int flags = 1;
	for (int i = digits.size()-1; i >= 0; --i)
	{
		int mod = (digits[i]+flags)%10;
		res.insert(res.begin(),mod);
		flags = (digits[i]+flags)/10;
	}
	if(flags > 0)
		res.insert(res.begin(),flags);
	return res;
}

int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}