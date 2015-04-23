#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	string LCS(const string &word1,const string &word2)
	{
		int len1 = word1.size();
		int len2 = word2.size();

		//考虑空字符串的情况
		if(len1 == 0 || len2 == 0)
			return NULL;
		
		//保存以word1[i],word2[j]为结尾的公共子串的长度
		vector<vector<int> > value(len2,vector<int>(len1,0));
		for(int i = 0; i < len1; ++i)
			value[0][i] = (word2[0] == word1[i])? 1:0;
		for(int i = 0; i < len2; ++i)
			value[i][0] = (word1[0] == word2[i])? 1:0;

		//DP算法核心value[i+1,j+1] == (word1[i+1] == word2[j+1])? L[i,j]+1:0
		for(int i = 1; i < len1; ++i)
		{
			for(int j = 1; j < len2; ++j)
			{
				if(word1[i] == word2[j])
					value[j][i] = value[j-1][i-1] + 1;
				else
					value[j][i] = 0;
			}
		}
		int longestLen = 0;//保存最长公共字串的长度
		int start1 = 0;//保存最长公共子串在word1中的开始位置
		int start2 = 0;//保存最长公共子串在word2中的开始位置

		for(int i = 0; i < len1; ++i)
		{
			for(int j = 0; j < len2; ++j)
			{
				if(longestLen < value[j][i])
				{
					longestLen = value[j][i];
					start1 = i - longestLen + 1;
					start2 = j - longestLen + 1;
				}
			}
		}
		cout << "start1=" << start1 << endl;
		cout << "start2=" << start2 << endl;
		string subStr = word1.substr(start1,longestLen);
		cout << "最长公共字符串：" << subStr << "长度：" << longestLen << endl;
		return subStr;
	}
};

int main(int argc,const char *argv[])
{
	string word1,word2;
	string line;
	Solution s;
	while(getline(cin,line))
	{
		cout << line << "测试用例" << endl;
		istringstream sin(line);
		sin >> word1 >> word2;
		s.LCS(word1,word2);
	}
	cout << endl;
	return 0;
}
