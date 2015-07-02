#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class Solution {
public:
	void reverseWords(string &s) {
		string res,word;
		istringstream input(s);
		input >> res;
		while(input >> word)
			res = word+" "+res;
		s = res;
	}
};

int main(int argc,const char *argv[]) 
{
	Solution s;
	string str = "the sky is blue";
	s.reverseWords(str);
	return 0;
}
