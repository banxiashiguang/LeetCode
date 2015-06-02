#include <iostream>
#include <string>
using namespace std;

string convert(string s,int numRows) {
	if(numRows == 1)
		return s;
	string res{""};
	for(int i = 0; i < numRows; ++i) {
		for(int j = i; j < s.size(); j += 2*(numRows-1)) {
			res.push_back(s[j]);
			if(i > 0 && i < numRows-1) {
				if(j+2*(numRows-i-1) < s.size())
					res.push_back(s[j+2*(numRows-i-1)]);
			}
		}
	}
	cout << res << endl;
	return res;
}

int main(int argc,const char *argv[])
{
	cout << convert("PAYPALISHIRING",3) << endl;
	return 0;
}
