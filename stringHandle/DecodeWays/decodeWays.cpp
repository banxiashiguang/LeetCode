#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
	int numDecodings(string s)
	{
		int len = s.size();
		if(len == 0)
			return 0;
		vector<int> value(len+1,0);
		value[0] = 1;
		if(s[0] == '0')
			value[1] = 0;
		else
			value[1] = 1;
		for(int i = 2; i <= len; ++i)
		{
			int num = stoi(s.substr(i-1,1));
			if(num > 0)
				value[i] = value[i-1];
			num = stoi(s.substr(i-2,2));
			if(num > 9 && num < 27)
				value[i] += value[i-2];
		}
		return value[len];
	}
};

int main(int argc,const char *argv[])
{
	Solution s;
	string str;
	while(getline(cin,str))
	{
		cout << str << "-----";
		cout << s.numDecodings(str) << endl;
	}
	return 0;
}
