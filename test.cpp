#include <iostream>
#include <sstream>
using namespace std;

int main(int argc, char const *argv[])
{
	struct ABCD
	{
		bool a:2;
		bool b:2;
		bool c:2;
		bool d:2;
	};
	ABCD abcd;
	abcd.a = 1;
	abcd.b = 1;
	abcd.c = 0;
	abcd.d = 0;
	char *state = (char*)&abcd;
	int a,b,c,d;
	a = *state & 0x3;
	b = *state >> 2 & 0x3;
	c = *state >> 4 & 0x3;
	d = *state >> 6 & 0x3;
	cout << a << endl;
	cout << b << endl;
	cout << c << endl;
	cout << d << endl;
	cout << "heloo--endl" << endl;
	cout << "hello--flush" << flush;
	cout << endl;
	cout << "hello--ends" << ends;
	return 0;
}
