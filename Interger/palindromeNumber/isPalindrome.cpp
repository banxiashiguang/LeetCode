#include <iostream>
#include <sstream>
using namespace std;

class Solution {
public:
	bool isPalindrome(int x) {
		int tmp = x;
		int sum{0};
		while(tmp > 0) {
			sum = sum*10+(tmp%10);
			tmp /= 10;
		}
		if(sum == x)
			return true;
		else
			return false;
	}
};

int main(int argc,const char *argv[])
{
	Solution s;
	string line;
	int x;
	while(getline(cin,line)) {
		istringstream ss(line);
		ss >> x;
		cout << line << ":";
		cout << s.isPalindrome(x) << endl;
	}
	return 0;
}
