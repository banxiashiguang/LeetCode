#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	string stringFilter(string str,char c) {
		int len = str.size();
		if(len == 0)
			return str;
		int i{0};
		for(i = 0; i < len; ++i)
			if(str[i] == c)
				break;
		for(int j = i+1; j < len; ++j) {
			if(str[j] != c) {
				str[i] = str[j];
				++i;
			}
		}
		return str.substr(0,i);
	}
};

int main(int argc,const char *argv[])
{
	Solution s;
	cout << s.stringFilter("eeea",'e') << endl;
	return 0;
}
