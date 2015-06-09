#include <iostream>
#include <cmath>
#include <string>
using namespace std;

class Solution {
public:
	int titleToNumber(string s) {
		int len = s.size();
		if(len == 0)
			return 0;
		int ret{0};
		for(int i = len-1; i >= 0; --i) {
			ret += pow(26,len-1-i)*(s[i]-'A'+1);
		}
		return ret;
	}
};

int main(int argc,const char *argv[])
{
	Solution s;
	string str;
	while(getline(cin,str))
		cout << s.titleToNumber(str) << endl;
	return 0;
}
