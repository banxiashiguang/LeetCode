#include <iostream>
using namespace std;

class Sqrt
{
public:
	Sqrt() { }
	~Sqrt() { }
	int solution(int x);
};

//利用二分搜索法，左范围定义为1，右范围为x
//为防止计算过程中，数值的溢出，所有的变量设为long long类型。
int Sqrt::solution(int x)
{
	if(x < 0)
		return -1;
	if(x == 0 || x == 1)
		return x;
	long long left = 1;
	long long right = x;
	while(left < right)
	{
		long long mid = (left+right) >> 1;
		long long val1 = mid*mid;
		long long val2 = (mid+1)*(mid+1);
		if(x >= val1 && x < val2)
			return mid;
		else if(x >= val2)
			left = mid + 1;
		else
			right = mid - 1;
	}
}

int main(int argc, char const *argv[])
{
	Sqrt s;
	cout << s.solution(2147483647) << endl;
	return 0;
}