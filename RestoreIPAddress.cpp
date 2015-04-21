#include <iostream>
#include <vector>
#include <string>
using namespace std;

class RestoreIPAddress
{
public:
	RestoreIPAddress(){ }
	~RestoreIPAddress() { }
	vector<string> restoreIpAddress(string s)
	{
		vector<string> res;
		if(s.size() < 4 || s.size() > 12)
			return res;
		
	}
};

int main(int argc,const char *argv[])
{
	return 0;
}