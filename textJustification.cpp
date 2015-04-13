#include <iostream>
#include <string>
#include <vector>
using namespace std;

class textJustification
{
public:
	textJustification() { }
	~textJustification() { }
	bool isBeyond(int &len,string &str,int L)
	{
		if(len == 0 && str.size() <= L)
		{
			len += str.size();
			return true;
		}
		if(len != 0 && ((len + 1 + str.size()) <= L))
		{
			len += str.size()+1;
			return true;
		}
		return false;

	}
	string addSpace(string &str,int k)
	{
		string res = str;
		for (int i = 0; i < k; ++i)
		{
			res += ' ';
		}
		return res;
	}
	void parse(vector<string> &res,vector<string> &words,int left,int right,int size,int L);
	void finalHandle(vector<string> &res,vector<string> &words,int left,int right,int size,int L);
	vector<string> solution(vector<string> &words,int L);
};

void textJustification::parse(vector<string> &res,vector<string> &words,int left,int right,int size,int L)
{
	int diff = right - left;
	if(diff == 0)
	{
		string s = addSpace(words[left], L-size);
		res.push_back(s);
	}else{
		string tmp = "";
		int mod = (L-size)/diff;
		int re = (L-size)%diff;
		for (int i = left; i < right; ++i)
		{
			int k = mod;
			if(re != 0)
			{
				k += 1;
				--re;
			}
			tmp += addSpace(words[i], k);
		}
		tmp += words[right];
		res.push_back(tmp);
	}
}

void textJustification::finalHandle(vector<string> &res,vector<string> &words,int left,int right,int size,int L)
{
	int diff = right - left;
	if(diff == 0)
	{
		string s = addSpace(words[left], L-size);
		res.push_back(s);
	}else{
		string tmp = "";
		for (int i = left; i < right; ++i)
		{
			tmp += words[i];
			tmp += ' ';
		}
		tmp += addSpace(words[right], L-(size+diff));
		res.push_back(tmp);
	}
}

vector<string> textJustification::solution(vector<string> &words,int L)
{
	vector<string> res;
	if(words.size() == 0)
		return res;
	int left = 0,right = 0;
	int size = 0,spaceSize = 0;
	for (int i = 0; i < words.size(); ++i)
	{
		if(isBeyond(spaceSize,words[i],L))
		{
			size += words[i].size();
			right = i;
		}else{
			parse(res,words,left,right,size,L);
			left = i;
			right = i;
			i -= 1;
			size = spaceSize = 0;
		}
	}
	finalHandle(res,words,left,right,size,L);
	for (int i = 0; i < res.size(); ++i)
	{
		cout << res[i] << endl;
	}
	return res;
}

int main(int argc, char const *argv[])
{
	vector<string> words {"What","must","be","shall","be."};
	textJustification t;
	t.solution(words,12);
	return 0;
}