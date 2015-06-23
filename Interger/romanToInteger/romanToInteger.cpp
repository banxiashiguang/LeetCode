#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
	int romanToInt(string s) {
		unordered_map<char,int> value{{'M',1000},{'D',500},{'C',100},{'L',50},{'X',10},{'V',5},{'I',1}};
		int res{0};
		for(int i = 0; i < s.size(); ++i) {
			if(i > 0 && value[s[i]] > value[s[i-1]])
				res += value[s[i]]-2*value[s[i-1]];
			else
				res += value[s[i]];
		}		
		return res;
	}
};

int main(int argc,const char *argv[])
{
	Solution s;
	string line;
	while(getline(cin,line)) {
		cout << line << ":";
		cout << s.romanToInt(line) << endl;
	}
	return 0;
}
