#include <iostream>
#include <limits>
#include <string>
using namespace std;

class Solution {
public:
	int myAtoi(string str) {
		int len = str.size();
		if(len == 0)
			return 0;
		int index{0};
		while(isspace(str[index])) ++index;
		int sign = str[index] == '-'? -1:1;
		if(str[index] == '-' || str[index] == '+')
			++index;
		int ret{0};
		int max = numeric_limits<int>::max();
		int min = numeric_limits<int>::min();
		while(isdigit(str[index])) {
			int digit = str[index]-'0';
			if(max/10 >= ret)
				ret *= 10;
			else
				return sign == -1? min:max;
			if(max-digit >= ret)
				ret += digit;
			else
				return sign == -1? min:max;
			++index;
		}
		return ret*sign;
	}
};

int main(int argc,const char *argv[])
{
	Solution s;
	string str;
	while(getline(cin,str)) {
		cout << str << "\t";
		cout << s.myAtoi(str) << endl;
	}
	return 0;
}
