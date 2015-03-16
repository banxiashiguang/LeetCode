#include <iostream>
#include <string>
using namespace std;

class convertToTitle
{
public:
	convertToTitle() { }
	~convertToTitle() { }
	string solution(int n);
};

string convertToTitle::solution(int n)
{
	string res = "";  
	while(n)  
	{  
	 	res += (char)('A' + (n-1)%26) + res;
	            	n = (n-1) / 26;  
	}  
	return res;  
}

int main(int argc, char const *argv[])
{
	convertToTitle c;
	string res = c.solution(28);
	cout<<res<<endl;
	return 0;
}