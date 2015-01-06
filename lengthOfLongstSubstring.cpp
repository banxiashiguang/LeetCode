#include <iostream>
#include <string>
#include <map>
using namespace std;

class lengthOfLongstSubstring
{
public:
	lengthOfLongstSubstring() { }
	~lengthOfLongstSubstring() { }
	int solution(string s);
};

int lengthOfLongstSubstring::solution(string s)
{
	map<char, int> indexs;
	int maxLen = 0;
	int curLen = 0;
	for(int i = 0;i < s.size();i++)
	{
		if(indexs.count(s[i]) == 0 || curLen < i - indexs[s[i]])
		{
			curLen++;
		}else{
			curLen = i - indexs[s[i]];
		}
		indexs[s[i]] = i;
		maxLen = curLen > maxLen? curLen:maxLen;
	}
	for(map<char,int>::iterator i = indexs.begin();i != indexs.end();i++)
	{
		cout<<i->first<<"\t"<<i->second<<endl;
	}
	return maxLen;
}

int main(int argc, char const *argv[])
{
	string str;
	cout<<"输入字符串：";
	cin>>str;
	lengthOfLongstSubstring l;
	cout<<l.solution(str)<<endl;
	return 0;
}