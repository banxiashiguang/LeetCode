#include <iostream>
#include <string>
#include <vector>
using namespace std;

class longestCommonPrefix
{
public:
	longestCommonPrefix() { }
	~longestCommonPrefix() { }
	string solution(vector<string> &strs);
};

string longestCommonPrefix::solution(vector<string> &strs)
{
	if(strs.size() == 0)
		return "";
	string res = "";
	bool flags = true;
	for(int i=0;i<strs[0].length();i++)
	{
		for(int j=1;j<strs.size();j++)
		{
			if(strs[0][i] != strs[j][i] || i > strs[j].length())
			{
				flags = false;
				break;
			}
		}
		if(flags == false)
			break;
		res.push_back(strs[0][i]);
	}
	return res;
}

int main(int argc, char const *argv[])
{
	vector<string> strs;
	strs.push_back("a");
	strs.push_back("b");
	longestCommonPrefix l;
	cout<<l.solution(strs)<<endl;
	return 0;
}