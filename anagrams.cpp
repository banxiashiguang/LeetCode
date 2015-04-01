#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

class anagrams
{
public:
	anagrams() { }
	~anagrams() {}
	vector<string> solution(vector<string> &strs);
};
vector<string> anagrams::solution(vector<string> &strs)
{
	vector<string> res;
	map<string,int> tmp;
	for (int i = 0; i < strs.size(); ++i)
	{
		string s = strs[i];
		sort(s.begin(),s.end());
		if(tmp.find(s) == tmp.end())
			tmp[s] = 1;
		else
			tmp[s]++;
	}
	for (int i = 0; i < strs.size(); ++i)
	{
		string s = strs[i];
		sort(s.begin(),s.end());
		if(tmp.find(s) != tmp.end() && tmp[s] > 1)
			res.push_back(str[i]);
	}
	return res;
}

int main(int argc, char const *argv[])
{
	string s("adbc");
	cout << s << endl;
	sort(s.begin(),s.end());
	cout << s << endl;
	return 0;
}