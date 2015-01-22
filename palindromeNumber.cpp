/*########################################
1、负数当成非回文的
########################################*/
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

class palindromeNumber
{
public:
	palindromeNumber() { }
	~palindromeNumber() { }
	bool solution(int x);
};

bool palindromeNumber::solution(int x)
{
	char str[20];
	sprintf(str,"%d",x);
	int left = 0;
	int right = strlen(str)-1;
	while(left <= right)
	{
		if(str[left] != str[right])
			return false;
		left ++;
		right--;
	}
	return true;
}

int main(int argc, char const *argv[])
{
	int x = 12321;
	palindromeNumber p;
	cout<<p.solution(x)<<endl;
	return 0;
}