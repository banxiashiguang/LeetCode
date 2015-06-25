#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	string next(string str) {
		string res;
		int count{1};
		char ch{str[0]};
		for(int i = 1; i < str.size(); ++i) {
			if(str[i] != ch) {
				//res.push_back((char)(count+'0'));
				//res.push_back(ch);
				res = res+(char)(count+'0')+ch;
				ch = str[i];
				count = 1;
			}else
				++count;
		}
		res = res+(char)(count+'0')+ch;
		return res;
	}
	string countAndSay(int n) {
		if(n == 1)
			return "1";
		string res = "1";
		for(int i = 2; i <= n; ++i) {
			res = next(res);
		}
		return res;
	}
};

int main(int argc,const char *argv[])
{
	Solution s;
	string line;
	while(getline(cin,line)) {
		cout << s.countAndSay(stoi(line)) << endl;
	}
	return 0;
}
