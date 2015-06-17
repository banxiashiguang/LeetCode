#include <iostream>
#include <string>
#include <cctype>
using namespace std;

class Solution {
public:
	int lengthOfLastWord(string s) {
		int len = s.size();
		if(len == 0)
			return 0;
		int index{len-1};
		while(isspace(s[index]))
			--index;
		int res{0};
		for(int i = index; i >= 0; --i) {
			if(isalpha(s[i]))
				++res;
			else
				break;
		}
		return res;
	}
};

int main(int argc,const char *argv[]) {
	Solution s;
	string line;
	while(getline(cin,line)) {
		cout << line << ":";
		cout << s.lengthOfLastWord("Hello World") << endl;
	}
	return 0;
}
