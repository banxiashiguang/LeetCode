#include <iostream>
#include <string>
using namespace std;

class integerToRoman
{
public:
	integerToRoman() { }
	~integerToRoman() { }
	string solution(int num);	
};

string integerToRoman::solution(int num)
{
	string symbol[] = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
	int value[] = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
	string str;
	for(int i = 0;num != 0;i++)
	{
		while(num >= value[i])
		{
			num -= value[i];
			str += symbol[i];
		}
	}
	return str;
}

int main(int argc, char const *argv[])
{
	integerToRoman i;
	cout<<i.solution(999)<<endl;
	return 0;
}