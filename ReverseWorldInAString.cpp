#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class ReverseWorldInAString
{
public:
	ReverseWorldInAString() { }
	~ReverseWorldInAString(){ }
	void totalReverseString(string &str);
	void singleWorld(string &str);
	void solution(string &s);
};

void ReverseWorldInAString::totalReverseString(string &str)
{
	int i = 0;
	int j = str.size()-1;
	while(i < j)
		swap(str[i++],str[j--]);
}

void ReverseWorldInAString::singleWorld(string &str)
{
	int i = 0;
	int j = str.size()-1;
	while(i < j)
		swap(str[i++],str[j--]);
}

void ReverseWorldInAString::solution(string &s)
{
	if(s.size() == 0)
		return;
	string res = "";
	string str = s;
	string tmp;
	totalReverseString(str);
	istringstream input(str);
	bool flags = false;
	while(input >> tmp)
	{
		flags = true;
		singleWorld(tmp);
		res += tmp;
		res += " ";
	}
	if(flags)
		s.assign(res.begin(),res.end() - 1);
	else
		s = "";
}

int main(int argc, char const *argv[])
{
	string s = "  ";
	ReverseWorldInAString r;
	r.solution(s);
	cout << s << endl;
	return 0;
}