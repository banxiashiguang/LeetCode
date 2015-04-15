#include <iostream>
#include <string>
using namespace std;

class simplifyPath
{
public:
	simplifyPath() { }
	~simplifyPath() { }
	void sampleHandle(string res,string &path);
	string solution(string path);
};

void simplifyPath::sampleHandle(string res, string &path)
{
	
}

string simplifyPath::solution(string path)
{
	string res = "";
	sampleHandle(res, path);
	cout << res << endl;
}

int main(int argc, char const *argv[])
{
	simplifyPath s;
	cout << s.solution("/a/./b/../../c/") << endl;
	return 0;
}