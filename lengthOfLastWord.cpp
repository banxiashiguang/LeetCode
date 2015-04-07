#include <iostream>
#include <cstring>
using namespace std;

class lengthOfLastWord
{
public:
	lengthOfLastWord() { }
	~lengthOfLastWord() { }
	int solution(const char *s);
};

int lengthOfLastWord::solution(const char *s)
{
	int res = 0,last = 0;
	const char *p = s;
	while(*p != '\0')
	{
		if(*p == ' ')
		{
			if(res != 0)
				last = res;
			res = 0;
		}else{
			++res;
		}
		++p;
	}
	if(*p == '\0' && *(p-1) == ' ')
		res = last;
	return res;
}

int main(int argc, char const *argv[])
{
	lengthOfLastWord l;
	cout << l.solution("Hello World") << endl;
	return 0;
}