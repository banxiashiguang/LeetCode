#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	string longestCommonPrefix(vector<string> &strs) {
		string res = "";
		if(strs.size() == 0)
			return res;
		for(int i=0; i < strs[0].size(); ++i) {
			char c = strs[0][i];
			for(int j = 1; j < strs.size(); ++j) {
				if(i >= strs[j].size())
					return res;
				if(strs[j][i] != c)
					return res;
			}
			res.push_back(c);
		}
		return res;
	}
};

int main(int argc,const char *argv[])
{
	vector<string> strs={"wo","wohenxihuanide","wohahah"};
	Solution s;
	cout << s.longestCommonPrefix(strs) << endl;
	return 0;
}
