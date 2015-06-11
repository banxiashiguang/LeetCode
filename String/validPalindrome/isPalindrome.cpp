#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	bool isPalindrome(string s) {
		int left = 0;
		int right = s.size();
		while(left < right) {
			while(left < right && !isalnum(s[left]))
				++left;
			while(left < right && !isalnum(s[right]))
				--right;
			if(isalpha(s[left]) && isalpha(s[right])) {
				if(tolower(s[left]) != tolower(s[right]))
					return false;
			}else{
				if(s[left] != s[right])
					return false;
			}
			++left;
			--right;
		}
		return true;
	}
};

int main(int argc,const char *argv[])
{
	Solution s;
	string line;
	while(getline(cin,line))
		cout << s.isPalindrome(line) << endl;
	return 0;
}
