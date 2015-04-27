#include <iostream>
#include <sstream>
#include <limits>
#include <string>
using namespace std;

class Solution
{
public:
	string minWindow(string s,string t)
	{
		cout << s << "\t" << t << endl;
		int lenS = s.size();
		int lenT = t.size();
		string res;
		if(lenT == 0)
			return res;
		int need[128] = {0};//保存t中个字符出现的次数。
		int candidate[128] = {0};//遍历过程中个字符出现的次数。
		for(int i = 0; i < lenT; ++i)
		{
			int value = (int)t[i];
			cout << value << endl;
			need[value]++;
		}
		int left = 0,right = 0;
		int count  = 0;//遍历过程中同时在s和t中都穿的字符的总个数。
		int minLen = numeric_limits<int>::max();
		while(right < lenS)
		{
			int value = (int)s[right];
			cout << s[right] << "\t" << count << endl;
			if(++candidate[value] <= need[value])
				++count;
			if(count == lenT)
			{
				while(left < right)
				{
					int tmp = (int)s[left];
					if(candidate[tmp] > need[tmp])
					{
						candidate[tmp]--;
						++left;
					}else
						break;
				}
				if(minLen > right-left+1)
				{
					cout << "left=" << left << "\t" << "right=" << right << endl;
					minLen = right-left+1;
					res = s.substr(left,minLen);
				}
			}
			++right;
		}
		return res;
	}
};

int main(int argc,const char *argv[])
{
	string line,str1,str2;
	Solution s;
	while(getline(cin,line))
	{
		cout << "测试用例-------" << endl;
		istringstream sin(line);
		sin >> str1 >> str2;
		cout << s.minWindow(str1,str2) << endl;
	}
	return 0;
}
