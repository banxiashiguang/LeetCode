#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class excelSheetColumnNumber
{
public:
	excelSheetColumnNumber(){ }
	~excelSheetColumnNumber() { }
	int solution(string s);
};

int excelSheetColumnNumber::solution(string s)
{
	int res = 0;
	int size = s.size()-1;
	for (int i = 0; i <= size; ++i)
	{
		res += (s[i]-'A'+1)*pow(26,size-i);
	}
	return res;
}

int main(int argc, char const *argv[])
{
	excelSheetColumnNumber e;
	cout << e.solution("AAA") << endl;
	return 0;
}