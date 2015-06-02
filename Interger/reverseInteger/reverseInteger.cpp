#include <iostream>
#include <limits>
using namespace std;

class Solution {
public:
	int reverse(int x) {
		const int upper = numeric_limits<int>::max();
		const int lower = numeric_limits<int>::min();
		int sum{0};
		while(x != 0) {
			if(sum > upper/10 || sum < lower/10)
				return 0;
			sum = sum*10+x%10;
			x /= 10;
		}
		return sum;
	}
};

int main(int argc,const char *argv[])
{
	Solution s;
	cout << s.reverse(1000) << endl;
	return 0;
}
